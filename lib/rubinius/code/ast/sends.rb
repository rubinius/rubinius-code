# -*- encoding: us-ascii -*-

module CodeTools
  module AST
    class Send < Node
      attr_accessor :receiver, :name, :privately, :block, :variable, :vcall_style

      def initialize(line, receiver, name, privately=false, vcall_style=false)
        @line = line
        @receiver = receiver
        @name = name
        @privately = privately
        @block = nil
        @vcall_style = vcall_style
      end

      def check_local_reference(g)
        if @receiver.kind_of? Self and g.state.check_for_locals
          g.state.scope.search_local(@name)
        end
      end

      def bytecode(g, anddot=false)
        pos(g)

        if @vcall_style
          if reference = check_local_reference(g)
            return reference.get_bytecode(g)
          end
        elsif !anddot
          @receiver.bytecode(g)
        end

        if @block
          @block.bytecode(g)
          g.send_with_block @name, 0, @privately
        elsif @vcall_style
          g.send_vcall @name
        else
          g.send @name, 0, @privately
        end
      end

      def value_defined(g, f)
        # Save the current exception into a stack local
        g.push_exception_state
        outer_exc_state = g.new_stack_local
        g.set_stack_local outer_exc_state
        g.pop

        ok = g.new_label
        ex = g.new_label
        g.setup_unwind ex, RescueType

        bytecode(g)

        g.pop_unwind
        g.goto ok

        ex.set!
        g.clear_exception
        g.push_stack_local outer_exc_state
        g.restore_exception_state
        g.goto f

        ok.set!
      end

      def defined(g)
        if @block.kind_of? For
          @block.defined(g)
          return
        end

        if @vcall_style and check_local_reference(g)
          g.push_literal "local-variable"
          return
        end

        f = g.new_label
        done = g.new_label

        @receiver.value_defined(g, f)

        g.push_literal @name

        if @vcall_style or @privately
          g.push_true
          g.send :__respond_to_p__, 2
        else
          g.push_self
          g.invoke_primitive :vm_check_callable, 3
        end
        g.goto_if_false f
        g.push_literal "method"
        g.goto done

        f.set!
        g.push_nil

        done.set!
      end

      def sexp_name
        :call
      end

      def receiver_sexp
        @privately ? nil : @receiver.to_sexp
      end

      def arguments_sexp
        sexp = [:arglist]
        sexp << @block.to_sexp if @block
        sexp
      end

      def to_sexp
        case @block
        when For
          n, x, b = @block.to_sexp
          xs = @receiver.to_sexp
          [n, x, xs, b]
        else
          [sexp_name, receiver_sexp, @name, arguments_sexp]
        end
      end
    end

    class AndSend < Send
      def bytecode(g)
        done = g.new_label

        @receiver.bytecode(g)

        g.dup
        g.goto_if_nil done

        super(g, true)

        done.set!
      end

      def sexp_name
        :and_call
      end
    end

    class SendWithArguments < Send
      attr_accessor :arguments

      def initialize(line, receiver, name, arguments, privately=false)
        super line, receiver, name, privately
        @block = nil
        @arguments = Arguments.new line, arguments
      end

      def bytecode(g, anddot=false)
        @receiver.bytecode(g) unless anddot
        @arguments.bytecode(g)

        pos(g)

        if @arguments.splat?
          @block ? @block.bytecode(g) : g.push_nil
          g.send_with_splat @name, @arguments.size, @privately, false
        elsif @block
          @block.bytecode(g)
          g.send_with_block @name, @arguments.size, @privately
        else
          g.send @name, @arguments.size, @privately
        end
      end

      def arguments_sexp(name=:arglist)
        sexp = [name]

        case @arguments
        when PushArguments
          sexp << @arguments.to_sexp
        else
          sexp += @arguments.to_sexp
        end

        sexp << @block.to_sexp if @block
        sexp
      end
    end

    class AndSendWithArguments < SendWithArguments
      def bytecode(g)
        done = g.new_label

        @receiver.bytecode(g)

        g.dup
        g.goto_if_nil done

        super(g, true)

        done.set!
      end

      def sexp_name
        :and_call
      end
    end

    class AttributeAssignment < SendWithArguments
      def initialize(line, receiver, name, arguments)
        @line = line

        @receiver = receiver
        @privately = receiver.kind_of?(Self) ? true : false

        @name = :"#{name}="

        @arguments = Arguments.new line, arguments
      end

      def bytecode(g, anddot=false)
        @receiver.bytecode(g) unless anddot
        if g.state.masgn?
          g.swap
          g.send @name, 1, @privately
        else
          @arguments.bytecode(g)
          g.dup

          if @arguments.splat?
            g.move_down @arguments.size + 2
            g.swap
            g.push_nil
            g.send_with_splat @name, @arguments.size, @privately, true
          else
            g.move_down @arguments.size + 1
            g.send @name, @arguments.size, @privately
          end

          g.pop
        end
      end

      def sexp_name
        :attrasgn
      end
    end

    class AndAttributeAssignment < AttributeAssignment
      def bytecode(g)
        done = g.new_label

        @receiver.bytecode(g)

        g.dup
        g.goto_if_nil done

        super(g, true)

        done.set!
      end

      def sexp_name
        :and_attrasgn
      end
    end

    class ElementAssignment < SendWithArguments
      def initialize(line, receiver, arguments)
        @line = line

        @receiver = receiver
        @privately = receiver.kind_of?(Self) ? true : false

        @name = :[]=

        case arguments
        when PushArgs
          @arguments = PushArguments.new line, arguments
        else
          @arguments = Arguments.new line, arguments
        end
      end

      def masgn_bytecode(g)
        @receiver.bytecode(g)
        g.swap
        @arguments.masgn_bytecode(g)
        g.send @name, @arguments.size + 1, @privately
        # TODO: splat
      end

      def bytecode(g)
        return masgn_bytecode(g) if g.state.masgn?

        @receiver.bytecode(g)
        @arguments.bytecode(g)

        g.dup

        if @arguments.splat?
          case @arguments
          when PushArguments
            g.move_down @arguments.size + 2
            g.swap
            flag = true
          when Arguments
            # TODO: Optimize bytecode for x[a, *b, c, d] = e
            g.send :last, 0, true
            g.move_down @arguments.size + 2
            flag = false
          end

          g.push_nil
          g.send_with_splat @name, @arguments.size, @privately, flag
        else
          g.move_down @arguments.size + 1
          g.send @name, @arguments.size, @privately
        end

        g.pop
      end

      def sexp_name
        :attrasgn
      end
    end

    class PreExe < Node
      attr_accessor :block

      def initialize(line)
        @line = line
      end

      def pre_bytecode(g)
        pos(g)

        g.push_state ClosedScope.new(@line)
        g.state.push_name :BEGIN

        g.push_rubinius
        g.find_const :Runtime
        @block.bytecode(g)
        g.send_with_block :pre_exe, 0, false

        g.state.pop_name
        g.pop_state
      end

      def to_sexp
      end

      def pre_sexp
        @block.to_sexp.insert 1, :pre_exe
      end
    end

    class PreExe19 < PreExe
      def pre_bytecode(g)
        pos(g)

        @block.body.bytecode(g)
      end
    end

    class PushArguments < Node
      attr_accessor :arguments

      def initialize(line, node)
        @line = line
        @arguments = node.arguments
        @value = node.value
      end

      def size
        splat? ? 1 : @arguments.size + 1
      end

      def splat?
        @arguments.splat?
      end

      def bytecode(g)
        @arguments.bytecode(g)
        @value.bytecode(g)
      end

      def to_sexp
        [:argspush, @arguments.to_sexp, @value.to_sexp]
      end
    end

    class BlockPass < Node
      attr_accessor :body

      def initialize(line, body)
        @line = line
        @body = body
      end

      def convert(g)
        nil_block = g.new_label
        g.dup
        g.goto_if_nil nil_block

        g.push_cpath_top
        g.find_const :Proc

        g.swap
        g.send :__from_block__, 1

        nil_block.set!
      end

      def bytecode(g)
        @body.bytecode(g)
        convert(g)
      end

      def assignment_bytecode(g)
        g.push_proc
        @body.bytecode(g)
      end

      def to_sexp
        [:block_pass, @body.to_sexp]
      end
    end

    class BlockPass19 < BlockPass
      attr_accessor :arguments

      def initialize(line, arguments, body)
        super(line, body)
        @arguments = arguments
      end
    end

    class CollectSplat < Node
      attr_accessor :splat, :array, :last

      def initialize(line, *parts)
        @line = line
        @splat = parts.shift
        @last = parts.pop
        @array = parts
      end

      def bytecode(g)
        @splat.bytecode(g)

        @array.each do |x|
          x.bytecode(g)
          g.cast_array
          g.send :+, 1
        end

        return unless @last

        not_hash = g.new_label
        done = g.new_label

        @last.bytecode(g)

        g.dup
        g.push_cpath_top
        g.find_const :Hash
        g.swap
        g.kind_of
        g.goto_if_false not_hash

        g.make_array 1
        g.goto done

        not_hash.set!
        g.cast_array

        done.set!
        g.send :+, 1
      end

      def to_sexp
        [:collect_splat] + @array.map { |x| x.to_sexp }
      end
    end

    class Arguments < Node
      attr_accessor :array, :splat

      def initialize(line, arguments=nil)
        @line = line
        @splat = nil

        case arguments
        when SplatValue
          @splat = arguments
          @array = []
        when ConcatArgs
          case arguments.array
          when ArrayLiteral
            @array = arguments.array.body
            @splat = SplatValue.new line, arguments.rest
          when PushArgs
            @array = []
            node = SplatValue.new line, arguments.rest
            @splat = CollectSplat.new line, arguments.array, node
          else
            @array = []
            @splat = CollectSplat.new line, arguments.array, arguments.rest
          end
        when PushArgs
          if arguments.arguments.kind_of? ConcatArgs
            if ary = arguments.arguments.peel_lhs
              @array = ary
            else
              @array = []
            end
          else
            @array = []
          end

          node = ArrayLiteral.new line, [arguments.value]
          @splat = CollectSplat.new line, arguments.arguments, node
        when ArrayLiteral
          @array = arguments.body
        when nil
          @array = []
        else
          @array = [arguments]
        end
      end

      def size
        @array.size
      end

      def stack_size
        size = @array.size
        size += 1 if splat?
        size
      end

      def splat?
        not @splat.nil?
      end

      def masgn_bytecode(g)
        @array.each do |x|
          x.bytecode(g)
          g.swap
        end
        # TODO: splat
      end

      def bytecode(g)
        @array.each { |x| x.bytecode(g) }
        @splat.bytecode(g) if @splat
      end

      def to_sexp
        sexp = @array.map { |x| x.to_sexp }
        sexp << @splat.to_sexp if @splat
        sexp
      end
    end

    class Iter < Node
      include Compiler::LocalVariables

      attr_accessor :parent, :arguments, :body

      def initialize(line, arguments, body)
        @line = line
        @arguments = arguments || Parameters.new(line)
        @body = body || NilLiteral.new(line)

        if @body.kind_of?(Block) and @body.locals
          @locals = @body.locals.body.map { |x| x.value }
        else
          @locals = nil
        end
      end

      def block_local?(name)
        @locals.include?(name) if @locals
      end

      def block_parameter?(name)
        @arguments.block_arg.name == name if @arguments.block_arg
      end

      def module?
        false
      end

      def nest_scope(scope)
        scope.parent = self
      end

      # A nested scope is looking up a local variable. If the variable exists
      # in our local variables hash, return a nested reference to it. If it
      # exists in an enclosing scope, increment the depth of the reference
      # when it passes through this nested scope (i.e. the depth of a
      # reference is a function of the nested scopes it passes through from
      # the scope it is defined in to the scope it is used in).
      def search_local(name)
        if variable = variables[name]
          variable.nested_reference
        elsif block_local?(name)
          new_nested_local name
        elsif reference = @parent.search_local(name)
          reference.depth += 1
          reference
        end
      end

      def new_local(name)
        variables[name] ||= Compiler::LocalVariable.new allocate_slot
      end

      def new_nested_local(name)
        new_local(name).nested_reference
      end

      # If the local variable exists in this scope, set the local variable
      # node attribute to a reference to the local variable. If the variable
      # exists in an enclosing scope, set the local variable node attribute to
      # a nested reference to the local variable. Otherwise, create a local
      # variable in this scope and set the local variable node attribute.
      def assign_local_reference(var)
        if variable = variables[var.name]
          var.variable = variable.reference
        elsif block_local?(var.name) || var.placeholder? || block_parameter?(var.name)
          variable = new_local var.name
          var.variable = variable.reference
        elsif reference = @parent.search_local(var.name)
          reference.depth += 1
          var.variable = reference
        else
          variable = new_local var.name
          var.variable = variable.reference
        end
      end

      def bytecode(g)
        pos(g)

        state = g.state
        state.scope.nest_scope self

        blk = new_block_generator g, @arguments

        blk.push_state self
        blk.definition_line @line
        blk.state.push_super state.super
        blk.state.push_eval state.eval

        blk.state.push_name blk.name

        # Push line info down.
        pos(blk)

        @arguments.bytecode(blk)

        blk.state.push_block
        blk.push_modifiers
        blk.break = nil
        blk.next = nil
        blk.redo = blk.new_label
        blk.redo.set!

        @body.bytecode(blk)

        blk.pop_modifiers
        blk.state.pop_block
        blk.ret
        blk.close
        blk.pop_state

        blk.splat_index = @arguments.splat_index
        blk.kwrest_index = @arguments.kwrest_index
        blk.local_count = local_count
        blk.local_names = local_names

        g.create_block blk
      end

      def sexp_name
        :iter
      end

      def to_sexp
        body_sexp = @body.to_sexp
        if @locals
          body_sexp[1] = @locals.map { |x| [:lvar, x] }
        end
        [sexp_name, @arguments.to_sexp, body_sexp]
      end
    end

    class IterArguments < Node
      attr_accessor :prelude, :arity, :optional, :arguments, :splat_index, :block_index
      attr_accessor :required_args, :keywords, :kwrest_index

      def initialize(line, arguments)
        @line = line
        @optional = 0
        @arguments = nil

        @splat_index = -1
        @block_index = nil
        @kwrest_index = nil
        @required_args = 0
        @splat = nil
        @block = nil
        @prelude = nil

        case arguments
        when Fixnum
          @splat_index = nil
          @arity = 0
          @prelude = nil
        when MultipleAssignment
          arguments.iter_arguments

          if arguments.splat
            case arguments.splat
            when EmptySplat
              @splat_index = -2
              arguments.splat = nil
              @prelude = :empty
            else
              @splat = arguments.splat = arguments.splat.value
            end

            @optional = 1
            if arguments.left
              @prelude = :multi
              size = arguments.left.body.size
              @arity = -(size + 1)
              @required_args = size
            else
              @prelude = :splat unless @prelude
              @arity = -1
            end
          elsif arguments.left
            size = arguments.left.body.size
            @prelude = :multi
            @arity = size
            @required_args = size

            # distinguish { |a, | ... } from { |a| ... }
            @splat_index = nil unless size == 1
          else
            @splat_index = 0
            @prelude = :multi
            @arity = -1
          end

          @block = arguments.block

          @arguments = arguments
        when nil
          @arity = -1
          @splat_index = -2 # -2 means accept the splat, but don't store it anywhere
          @prelude = nil
        when BlockPass
          @arity = -1
          @splat_index = -2
          @prelude = nil
          @block = arguments
        else # Assignment
          @splat_index = nil
          @arguments = arguments
          @arity = 1
          @required_args = 1
          @prelude = :single
        end
      end

      alias_method :total_args, :required_args

      def post_args
        0
      end

      def names
        case @arguments
        when MultipleAssignment
          if arguments = @arguments.left.body
            array = arguments.map { |x| x.name }
          else
            array = []
          end

          if @arguments.splat.kind_of? SplatAssignment
            array << @arguments.splat.name
          end

          array
        when nil
          []
        else
          [@arguments.name]
        end
      end

      def arguments_bytecode(g, is_array=false)
        g.state.push_masgn

        if @arguments.kind_of? MultipleAssignment
          @arguments.bytecode(g, is_array)
        else
          @arguments.bytecode(g) if @arguments
        end

        g.state.pop_masgn

        if @splat
          @splat_index = @splat.variable.slot
        end
      end

      def bytecode(g)
        case @prelude
        when :single
          g.cast_for_single_block_arg
          arguments_bytecode(g)
          g.pop
        when :multi
          g.cast_for_multi_block_arg
          arguments_bytecode(g, true)
          g.pop
        when :splat
          g.cast_for_splat_block_arg
          arguments_bytecode(g)
          g.pop
        when :empty
          g.cast_for_splat_block_arg
          g.pop
        end

        if @block
          @block.assignment_bytecode(g)
        end
      end

      def to_sexp
        if @arguments
          @arguments.to_sexp
        elsif @arity == 0
          0
        else
          nil
        end
      end
    end

    class For < Iter
      def initialize(line, arguments, body)
        @line = line
        @arguments = ForParameters.new line, arguments
        @body = body || NilLiteral.new(line)

        new_local :"$for_args"
      end

      def nest_scope(scope)
        scope.parent = self
      end

      def search_local(name)
        if reference = @parent.search_local(name)
          reference.depth += 1
          reference
        end
      end

      def new_nested_local(name)
        reference = @parent.new_nested_local name
        reference.depth += 1
        reference
      end

      def assign_local_reference(var)
        unless reference = search_local(var.name)
          reference = new_nested_local var.name
        end

        var.variable = reference
      end

      def defined(g)
        g.push_literal "expression"
      end

      def sexp_name
        :for
      end
    end

    class ForParameters < Node
      attr_accessor :assignments, :required_args, :splat_index,
                    :post_args, :keywords, :block_index, :kwrest_index

      def initialize(line, assignments)
        @line = line
        @assignments = assignments
        @splat_index = assignments.kind_of?(MultipleAssignment) ? 0 : nil
        @required_args = @splat_index ? 0 : 1
        @post_args = 0
        @keywords = nil
        @block_index = nil
        @kwrest_index = nil
      end

      alias_method :total_args, :required_args
      alias_method :arity, :required_args

      def map_arguments(scope)
        case @assignments
        when LocalVariable
          scope.assign_local_reference @assignments
        end
      end

      def bytecode(g)
        map_arguments(g.state.scope)

        if @splat_index
          g.push_rubinius
          g.find_const :Runtime
          g.push_local 0
          g.send :unwrap_block_arg, 1
        else
          g.push_local 0
        end

        g.state.push_masgn
        @assignments.bytecode(g)
        g.state.pop_masgn
      end

      def to_sexp
        sexp = [:args]

        case @assignments
        when ArrayLiteral
          @assignments.each do |a|
            case a
            when Symbol
              sexp << a
            when Node
              sexp << a.to_sexp
            end
          end
        else
          sexp << @assignments.to_sexp
        end

        sexp
      end
    end

    class Negate < Node
      attr_accessor :value

      def initialize(line, value)
        @line = line
        @value = value
      end

      def bytecode(g)
        pos(g)

        if @value.kind_of? FixnumLiteral
          g.push_int(-@value.value)
        elsif @value.kind_of? NumberLiteral
          g.push_literal(-@value.value)
        else
          @value.bytecode(g)
          g.send :"-@", 0
        end
      end

      def to_sexp
        [:negate, @value.to_sexp]
      end
    end

    class Super < SendWithArguments
      attr_accessor :name, :block

      def initialize(line, arguments)
        @line = line
        @block = nil
        @name = nil
        @arguments = Arguments.new line, arguments
      end

      def block_bytecode(g)
        if @block
          @block.bytecode(g)
        else
          g.push_block
        end
      end

      def bytecode(g)
        pos(g)

        @name = g.state.super.name if g.state.super?

        @arguments.bytecode(g)

        block_bytecode(g)

        if @arguments.splat?
          g.send_super @name, @arguments.size, true
        else
          g.send_super @name, @arguments.size
        end
      end

      def defined(g)
        nope = g.new_label
        done = g.new_label

        g.invoke_primitive :vm_check_super_callable, 0

        g.goto_if_false nope

        g.push_literal "super"
        g.string_dup
        g.goto done

        nope.set!
        g.push_nil

        done.set!
      end

      def to_sexp
        arguments_sexp :super
      end
    end

    class Yield < SendWithArguments
      attr_accessor :flags

      def initialize(line, arguments, unwrap)
        @line = line

        if arguments.kind_of? ArrayLiteral and not unwrap
          arguments = ArrayLiteral.new line, [arguments]
        end

        @arguments = Arguments.new line, arguments
        @argument_count = @arguments.size
        @yield_splat = false

        if @arguments.splat?
          splat = @arguments.splat.value
          if (splat.kind_of? ArrayLiteral or splat.kind_of? EmptyArray) and not unwrap
            @argument_count += 1
          else
            @yield_splat = true
          end
        end
      end

      def bytecode(g)
        pos(g)

        @arguments.bytecode(g)

        if @yield_splat
          g.yield_splat @argument_count
        else
          g.yield_stack @argument_count
        end
      end

      def defined(g)
        t = g.new_label
        f = g.new_label

        g.push_block
        g.goto_if_true t
        g.push_nil
        g.goto f

        t.set!
        g.push_literal "yield"

        f.set!
      end

      def to_sexp
        args = @arguments.to_sexp
        args << @block.to_sexp if @block
        if @argument_count == 1 and !@yield_splat and @arguments.splat.nil? and
           @arguments.array.first.kind_of? SplatValue
          [:yield, [:array] + args]
        else
          [:yield] + args
        end
      end
    end

    class ZSuper < Super
      def initialize(line)
        @line = line
        @block = nil
      end

      def bytecode(g)
        pos(g)

        @name = g.state.super.name if g.state.super?

        block_bytecode(g)

        g.zsuper @name
      end

      def to_sexp
        [:zsuper]
      end
    end
  end
end
