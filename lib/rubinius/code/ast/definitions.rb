# -*- encoding: us-ascii -*-

module CodeTools
  module AST
    class Alias < Node
      attr_accessor :to, :from

      def initialize(line, to, from)
        @line = line
        @to = to
        @from = from
      end

      def bytecode(g)
        pos(g)

        g.push_scope
        @to.bytecode(g)
        @from.bytecode(g)
        g.send :alias_method, 2, true
      end

      def to_sexp
        [:alias, @to.to_sexp, @from.to_sexp]
      end
    end

    class VAlias < Alias
      def bytecode(g)
        pos(g)

        g.push_rubinius
        g.find_const :Globals
        g.push_literal @from
        g.push_literal @to
        # TODO: fix #add_alias arg order to match #alias_method
        g.send :add_alias, 2
      end

      def to_sexp
        [:valias, @to, @from]
      end
    end

    class Undef < Node
      attr_accessor :name

      def initialize(line, sym)
        @line = line
        @name = sym
      end

      def bytecode(g)
        pos(g)

        g.push_scope
        @name.bytecode(g)
        g.send :__undef_method__, 1
      end

      def to_sexp
        [:undef, @name.to_sexp]
      end
    end

    # Is it weird that Block has the :arguments attribute? Yes. Is it weird
    # that MRI parse tree puts arguments and block_arg in Block? Yes. So we
    # make do and pull them out here rather than having something else reach
    # inside of Block.
    class Block < Node
      attr_accessor :array, :locals

      def initialize(line, array)
        @line = line
        @array = array

        # These are any local variable that are declared as explicit
        # locals for this scope. This is only used by the |a;b| syntax.
        @locals = nil
      end

      def extract_parameters
        if @array.first.kind_of? Parameters
          node = @array.shift
          if @array.first.kind_of? BlockArgument
            node.block_arg = @array.shift
          end
          return node
        end
      end

      def bytecode(g)
        count = @array.size - 1
        @array.each_with_index do |x, i|
          start_ip = g.ip
          x.bytecode(g)
          g.pop unless start_ip == g.ip or i == count
        end
      end

      def to_sexp
        @array.inject([:block]) { |s, x| s << x.to_sexp }
      end
    end

    class ClosedScope < Node
      include Compiler::LocalVariables

      attr_accessor :body

      # A nested scope is looking up a local variable. If the variable exists
      # in our local variables hash, return a nested reference to it.
      def search_local(name)
        if variable = variables[name]
          variable.nested_reference
        end
      end

      def new_local(name)
        variables[name] ||= Compiler::LocalVariable.new allocate_slot
      end

      def new_nested_local(name)
        new_local(name).nested_reference
      end

      # There is no place above us that may contain a local variable. Set the
      # local in our local variables hash if not set. Set the local variable
      # node attribute to a reference to the local variable.
      def assign_local_reference(var)
        unless variable = variables[var.name]
          variable = new_local var.name
        end

        var.variable = variable.reference
      end

      def nest_scope(scope)
        scope.parent = self
      end

      def module?
        false
      end

      def attach_and_call(g, arg_name, scoped=false, pass_block=false)
        name = @name || arg_name
        meth = new_generator(g, name)

        meth.push_state self
        meth.for_module_body = true

        if scoped
          meth.push_self
          meth.add_scope
        end

        meth.state.push_name name

        @body.bytecode meth

        meth.state.pop_name

        meth.ret
        meth.close

        meth.local_count = local_count
        meth.local_names = local_names

        meth.pop_state

        g.create_block meth
        g.swap
        g.push_scope
        g.push_true
        g.send :call_under, 3

        return meth
      end

      def to_sexp
        sexp = [:scope]
        sexp << @body.to_sexp if @body
        sexp
      end
    end

    class Define < ClosedScope
      attr_accessor :name, :arguments

      def initialize(line, name, block)
        @line = line
        @name = name
        @arguments = block.extract_parameters
        block.array << NilLiteral.new(line) if block.array.empty?
        @body = block
      end

      def compile_body(g)
        meth = new_generator(g, @name, @arguments)

        meth.push_state self
        meth.state.push_super self
        meth.definition_line(@line)

        meth.state.push_name @name

        @arguments.bytecode(meth)
        @body.bytecode(meth)

        meth.state.pop_name

        meth.local_count = local_count
        meth.local_names = local_names

        meth.ret
        meth.close
        meth.pop_state

        return meth
      end

      def bytecode(g)
        pos(g)

        g.push_rubinius
        g.push_literal @name
        g.push_generator compile_body(g)
        g.push_scope
        g.push_variables
        g.send :method_visibility, 0

        g.send :add_defn_method, 4
      end

      def to_sexp
        [:defn, @name, @arguments.to_sexp, [:scope, @body.to_sexp]]
      end
    end

    class DefineSingleton < Node
      attr_accessor :receiver, :body

      def initialize(line, receiver, name, block)
        @line = line
        @receiver = receiver
        @body = DefineSingletonScope.new line, name, block
      end

      def bytecode(g)
        pos(g)

        @body.bytecode(g, @receiver)
      end

      def to_sexp
        [:defs, @receiver.to_sexp, @body.name,
          @body.arguments.to_sexp, [:scope, @body.body.to_sexp]]
      end
    end

    class DefineSingletonScope < Define
      def initialize(line, name, block)
        super line, name, block
      end

      def bytecode(g, recv)
        pos(g)

        g.push_rubinius
        g.push_literal @name
        g.push_generator compile_body(g)
        g.push_scope
        recv.bytecode(g)

        g.send :attach_method, 4
      end
    end

    class Lambda < Node
      attr_accessor :arguments, :body

      def initialize(line, arguments, body)
        @line = line
        @arguments = arguments
        @body = Iter.new line, arguments, body
      end

      def bytecode(g)
        pos(g)

        g.push_rubinius
        @body.bytecode(g)
        g.send_with_block :lambda, 0, false
      end

      def to_sexp
        [:lambda, @arguments.to_sexp, [:scope, @body.body.to_sexp]]
      end
    end

    class Parameters < Node
      attr_accessor :names, :required, :optional, :defaults, :splat,
                    :post, :keywords, :kwrest
      attr_reader :block_arg, :block_index

      def initialize(line, required=nil, optional=nil, splat=nil,
                     post=nil, kwargs=nil, kwrest=nil, block=nil)
        @line = line
        @defaults = nil
        @keywords = nil
        @block_arg = nil
        @splat_index = nil
        @block_index = nil
        @locals = []
        @local_index = 0

        names = []

        process_fixed_arguments Array(required), @required = [], names

        if optional
          @defaults = DefaultArguments.new line, optional
          @optional = @defaults.names
          names.concat @optional
          @locals.concat @defaults.arguments
        else
          @optional = []
        end

        case splat
        when Symbol
          names << splat
          @locals << splat
        when true
          splat = :*
          @locals << splat
        when false
          splat = nil
          @splat_index = -3
        end

        @splat = splat

        process_fixed_arguments post, @post = [], names

        if kwargs
          @keywords = KeywordParameters.new line, kwargs, kwrest
          names.concat @keywords.names
        elsif kwrest
          @keywords = KeywordParameters.new line, nil, kwrest
        end

        if @keywords
          var = local_placeholder
          @keywords.value = LocalVariableAccess.new line, var
          @locals << var
        end

        @names = names

        self.block_arg = block
      end

      def process_fixed_arguments(array, arguments, names)
        if array
          array.each do |arg|
            case arg
            when :_
              var = names.include?(:_) ? local_placeholder : arg
              names << arg
            when Symbol
              var = arg
              names << arg
            when MultipleAssignment
              var = arg
              var.right = LocalVariableAccess.new line, local_placeholder
            when VariableAssignment
              var = arg
              names << var.name
            end

            arguments << var
            @locals << var
          end
        end
      end

      def local_placeholder
        :"_:#{@local_index += 1}"
      end

      def block_arg=(block)
        case block
        when BlockArgument
          @block_arg = block
        when nil
          return
        else
          @block_arg = BlockArgument.new @line, block
        end

        if @locals.last.kind_of? BlockArgument
          @block_index -= 1
          @locals.pop
        end
        @names.pop if @names.last.kind_of? BlockArgument

        @block_index = @locals.size
        @locals << @block_arg
        @names << @block_arg.name
      end

      def required_args
        @required.size + @post.size
      end

      def post_args
        @post.size
      end

      def total_args
        args = @required.size + @optional.size + @post.size
        args += 1 if @keywords
        args
      end

      def splat_index
        return @splat_index if @splat_index

        return @required.size + @optional.size if @splat
      end

      def arity
        arity = required_args

        if @keywords and @keywords.required?
          arity += 1
        end

        if @splat or not @optional.empty? or
            (@keywords and not @keywords.required?)
          arity += 1
        end

        if @splat or not @optional.empty? or
            (@keywords and not @keywords.required?)
          arity = -arity
        end

        arity
      end

      def map_arguments(scope)
        @locals.map do |v|
          case v
          when Symbol
            scope.new_local v
          when MultipleAssignment
            scope.assign_local_reference v.right
          when LocalVariable
            scope.assign_local_reference v
          when nil
            STDERR.puts @locals.inspect, self.inspect
          end
        end

        @keywords.map_arguments(scope) if @keywords
      end

      def bytecode(g)
        g.state.check_for_locals = false
        map_arguments g.state.scope

        @required.each_with_index do |arg, index|
          if arg.kind_of? MultipleAssignment
            g.push_local index
            arg.bytecode(g)
            g.pop
          end
        end

        @defaults.bytecode(g) if @defaults

        index = @required.size + @optional.size
        index += 1 if @splat_index

        @post.each do |arg|
          if arg.kind_of? MultipleAssignment
            g.push_local index
            index += 1
            arg.bytecode(g)
            g.pop
          end
        end

        @keywords.bytecode(g) if @keywords

        @block_arg.bytecode(g) if @block_arg

        g.state.check_for_locals = true
      end

      def to_sexp
        sexp = [:args]

        @required.each do |a|
          case a
          when Symbol
            sexp << a
          when Node
            sexp << a.to_sexp
          end
        end

        sexp += @defaults.names if @defaults

        if @splat == :*
          sexp << :*
        elsif @splat
          sexp << :"*#{@splat}"
        end

        if @post
          @post.each do |a|
            case a
            when Symbol
              sexp << a
            when Node
              sexp << a.to_sexp
            end
          end
        end

        sexp += @keywords.names if @keywords

        sexp << :"&#{@block_arg.name}" if @block_arg

        sexp << [:block] + @defaults.to_sexp if @defaults
        sexp << @keywords.to_sexp if @keywords

        sexp
      end
    end

    class DefaultArguments < Node
      attr_accessor :arguments, :names

      def initialize(line, block)
        @line = line
        array = block.array
        @names = array.map { |a| a.name }
        @arguments = array
      end

      def map_arguments(scope)
        @arguments.each { |var| scope.assign_local_reference var }
      end

      def bytecode(g)
        @arguments.each do |arg|
          done = g.new_label

          arg.variable.get_bytecode(g)
          g.ginu done
          arg.bytecode(g)
          g.pop

          done.set!
        end
      end

      def to_sexp
        @arguments.map { |x| x.to_sexp }
      end
    end

    class KeywordParameters < Node
      attr_accessor :arguments, :defaults, :names, :kwrest, :value

      def initialize(line, block, kwrest)
        @line = line
        @kwrest = kwrest
        @required = []
        @defaults = []

        if block
          array = block.array
          @names = array.map { |a| a.name }

          array.each do |arg|
            if arg.value.kind_of?(SymbolLiteral) and arg.value.value == :*
              @required << arg
            else
              @defaults << arg
            end
          end

          @arguments = array
        else
          @arguments = []
          @names = []
        end

        case kwrest
        when Symbol
          kwrest_name = :"**#{kwrest}"
          @kwrest = LocalVariableAssignment.new line, kwrest
        when true
          kwrest_name = :**
          @kwrest = true
        end

        @names << kwrest_name if kwrest_name
      end

      def required?
        not @required.empty?
      end

      def entries
        entries = []
        @required.each { |arg| entries << arg.name << true }
        @defaults.each { |arg| entries << arg.name << false }
        entries
      end

      def map_arguments(scope)
        @arguments.each { |var| scope.assign_local_reference var }

        if @kwrest.kind_of? LocalVariableAssignment
          scope.assign_local_reference @kwrest
        end
      end

      def bytecode(g)
        done = g.new_label
        assignments = g.new_label
        missing_value = g.new_label

        @value.bytecode(g)

        g.dup
        g.goto_if_not_nil assignments

        g.pop
        g.push_cpath_top
        g.find_const :Hash
        g.send :allocate, 0, true

        assignments.set!

        @required.each do |arg|
          g.dup
          g.push_literal arg.name
          g.send :find_item, 1, true

          g.dup
          g.gif missing_value

          g.send :value, 0, true

          arg.variable.set_bytecode(g)
          g.pop
        end

        defaults = g.new_label
        g.goto defaults

        missing_value.set!
        g.pop
        g.push_rubinius
        g.find_const :Runtime
        g.swap
        g.send :keywords_missing, 1, true
        g.goto done

        defaults.set!

        extra_keys = g.new_label

        if @defaults.empty?
          g.dup
          g.send :size, 0, true
          g.push @arguments.size
          g.gine extra_keys

          if @kwrest.kind_of? LocalVariableAssignment
            g.push_cpath_top
            g.find_const :Hash
            g.send :allocate, 0, true
            @kwrest.variable.set_bytecode(g)
            g.pop
          end

          g.goto done
        else
          @defaults.each do |arg|
            next_value = g.new_label
            default_value = g.new_label

            g.dup
            g.push_literal arg.name
            g.send :find_item, 1, true

            g.dup
            g.gif default_value

            g.send :value, 0, true
            arg.variable.set_bytecode(g)
            g.goto next_value

            default_value.set!
            g.pop
            arg.bytecode(g)

            next_value.set!
            g.pop
          end
        end

        extra_keys.set!

        g.dup
        g.push_rubinius
        g.find_const :Runtime
        g.swap

        if @kwrest
          g.push :true
        else
          g.push :false
        end

        g.send :keywords_extra, 2, true
        if @kwrest.kind_of? LocalVariableAssignment
          @kwrest.variable.set_bytecode(g)
        end
        g.pop

        done.set!
      end

      def to_sexp
        sexp = [:kwargs]
        sexp << @names unless @names.empty?
        sexp << @defaults.map { |x| x.to_sexp } unless @defaults.empty?
        sexp
      end
    end

    module LocalVariable
      attr_accessor :variable
    end

    class BlockArgument < Node
      include LocalVariable

      attr_accessor :name

      def initialize(line, name)
        @line = line
        @name = name
      end

      def bytecode(g)
        pos(g)

        g.push_proc

        if @variable.respond_to?(:depth) && @variable.depth != 0
          g.set_local_depth @variable.depth, @variable.slot
        else
          g.set_local @variable.slot
        end

        g.pop
      end
    end

    class Class < Node
      attr_accessor :name, :superclass, :body

      def initialize(line, name, superclass, body)
        @line = line

        @superclass = superclass ? superclass : NilLiteral.new(line)

        case name
        when Symbol
          @name = ClassName.new line, name, @superclass
        when ToplevelConstant
          @name = ToplevelClassName.new line, name, @superclass
        else
          @name = ScopedClassName.new line, name, @superclass
        end

        if body
          @body = ClassScope.new line, @name, body
        else
          @body = EmptyBody.new line
        end
      end

      def bytecode(g)
        @name.bytecode(g)
        @body.bytecode(g)
      end

      def to_sexp
        superclass = @superclass.kind_of?(NilLiteral) ? nil : @superclass.to_sexp
        [:class, @name.to_sexp, superclass, @body.to_sexp]
      end
    end

    class ClassScope < ClosedScope
      def initialize(line, name, body)
        @line = line
        @name = name.name
        @body = body
      end

      def module?
        true
      end

      def bytecode(g)
        pos(g)

        attach_and_call g, :__class_init__, true
      end
    end

    class ClassName < Node
      attr_accessor :name, :superclass

      def initialize(line, name, superclass)
        @line = line
        @name = name
        @superclass = superclass
      end

      def name_bytecode(g)
        g.push_rubinius
        g.push_literal @name
        @superclass.bytecode(g)
      end

      def bytecode(g)
        pos(g)

        name_bytecode(g)
        g.push_scope
        g.send :open_class, 3
      end

      def to_sexp
        @name
      end
    end

    class ToplevelClassName < ClassName
      def initialize(line, node, superclass)
        @line = line
        @name = node.name
        @superclass = superclass
      end

      def bytecode(g)
        pos(g)

        name_bytecode(g)
        g.push_cpath_top
        g.send :open_class_under, 3
      end

      def to_sexp
        [:colon3, @name]
      end
    end

    class ScopedClassName < ClassName
      attr_accessor :parent

      def initialize(line, node, superclass)
        @line = line
        @name = node.name
        @parent = node.parent
        @superclass = superclass
      end

      def bytecode(g)
        pos(g)

        name_bytecode(g)
        @parent.bytecode(g)
        g.send :open_class_under, 3
      end

      def to_sexp
        [:colon2, @parent.to_sexp, @name]
      end
    end

    class Module < Node
      attr_accessor :name, :body

      def initialize(line, name, body)
        @line = line

        case name
        when Symbol
          @name = ModuleName.new line, name
        when ToplevelConstant
          @name = ToplevelModuleName.new line, name
        else
          @name = ScopedModuleName.new line, name
        end

        if body
          @body = ModuleScope.new line, @name, body
        else
          @body = EmptyBody.new line
        end
      end

      def bytecode(g)
        @name.bytecode(g)
        @body.bytecode(g)
      end

      def to_sexp
        [:module, @name.to_sexp, @body.to_sexp]
      end
    end

    class EmptyBody < Node
      def bytecode(g)
        g.pop
        g.push :nil
      end

      def to_sexp
        [:scope]
      end
    end

    class ModuleName < Node
      attr_accessor :name

      def initialize(line, name)
        @line = line
        @name = name
      end

      def name_bytecode(g)
        g.push_rubinius
        g.push_literal @name
      end

      def bytecode(g)
        pos(g)

        name_bytecode(g)
        g.push_scope
        g.send :open_module, 2
      end

      def to_sexp
        @name
      end
    end

    class ToplevelModuleName < ModuleName
      def initialize(line, node)
        @line = line
        @name = node.name
      end

      def bytecode(g)
        pos(g)

        name_bytecode(g)
        g.push_cpath_top
        g.send :open_module_under, 2
      end

      def to_sexp
        [:colon3, @name]
      end
    end

    class ScopedModuleName < ModuleName
      attr_accessor :parent

      def initialize(line, node)
        @line = line
        @name = node.name
        @parent = node.parent
      end

      def bytecode(g)
        pos(g)

        name_bytecode(g)
        @parent.bytecode(g)
        g.send :open_module_under, 2
      end

      def to_sexp
        [:colon2, @parent.to_sexp, @name]
      end
    end

    class ModuleScope < ClosedScope
      def initialize(line, name, body)
        @line = line
        @name = name.name
        @body = body
      end

      def module?
        true
      end

      def bytecode(g)
        pos(g)

        attach_and_call g, :__module_init__, true
      end
    end

    class SClass < Node
      attr_accessor :receiver

      def initialize(line, receiver, body)
        @line = line
        @receiver = receiver
        @body = SClassScope.new line, body
      end

      def bytecode(g)
        pos(g)
        @receiver.bytecode(g)
        @body.bytecode(g)
      end

      def to_sexp
        [:sclass, @receiver.to_sexp, @body.to_sexp]
      end
    end

    class SClassScope < ClosedScope
      def initialize(line, body)
        @line = line
        @body = body
        @name = nil
      end

      def bytecode(g)
        pos(g)

        g.push_type
        g.swap
        g.send :object_singleton_class, 1

        if @body
          # if @body just returns self, don't bother with it.
          if @body.kind_of? Block
            ary = @body.array
            return if ary.size == 1 and ary[0].kind_of? Self
          end

          # Ok, emit it.
          attach_and_call g, :__metaclass_init__, true, true
        else
          g.pop
          g.push :nil
        end
      end
    end

    class Container < ClosedScope
      attr_accessor :file, :name, :variable_scope, :pre_exe

      def initialize(body)
        @body = body || NilLiteral.new(1)
        @pre_exe = []
      end

      def push_state(g)
        g.push_state self
      end

      def pop_state(g)
        g.pop_state
      end

      def container_bytecode(g)
        g.name = @name
        g.file = @file.to_sym

        push_state(g)
        @pre_exe.each { |pe| pe.pre_bytecode(g) }

        yield if block_given?
        pop_state(g)

        g.local_count = local_count
        g.local_names = local_names
      end

      def to_sexp
        sexp = [sexp_name]
        @pre_exe.each { |pe| sexp << pe.pre_sexp }
        sexp << @body.to_sexp
        sexp
      end
    end

    class EvalExpression < Container
      def initialize(body)
        super body
        @name = :__eval_script__
      end

      def should_cache?
        !@body.kind_of?(AST::ClosedScope)
      end

      def search_scopes(name)
        depth = 1
        scope = @variable_scope
        while scope
          if !scope.method.for_eval? and slot = scope.method.local_slot(name)
            return Compiler::NestedLocalVariable.new(depth, slot)
          elsif scope.eval_local_defined?(name, false)
            return Compiler::EvalLocalVariable.new(name)
          end

          depth += 1
          scope = scope.parent
        end
      end

      # Returns a cached reference to a variable or searches all
      # surrounding scopes for a variable. If no variable is found,
      # it returns nil and a nested scope will create the variable
      # in itself.
      def search_local(name)
        if variable = variables[name]
          return variable.nested_reference
        end

        if variable = search_scopes(name)
          variables[name] = variable
          return variable.nested_reference
        end
      end

      def new_local(name)
        variables[name] ||= Compiler::EvalLocalVariable.new name
      end

      def assign_local_reference(var)
        unless reference = search_local(var.name)
          variable = new_local var.name
          reference = variable.reference
        end

        var.variable = reference
      end

      def push_state(g)
        g.push_state self
        g.state.push_eval self
      end

      def bytecode(g)
        super(g)

        container_bytecode(g) do
          @body.bytecode(g)
          g.ret
        end
      end

      def sexp_name
        :eval
      end
    end

    class Snippet < Container
      def initialize(body)
        super body
        @name = :__snippet__
      end

      def bytecode(g)
        super(g)

        container_bytecode(g) do
          @body.bytecode(g)
        end
      end

      def sexp_name
        :snippet
      end
    end

    class Script < Container
      def initialize(body)
        super body
        @name = :__script__
      end

      def bytecode(g)
        super(g)

        container_bytecode(g) do
          @body.bytecode(g)
          g.pop
          g.push :true
          g.ret
        end
      end

      def sexp_name
        :script
      end
    end

    class Defined < Node
      attr_accessor :expression

      def initialize(line, expr)
        @line = line
        @expression = expr
      end

      def bytecode(g)
        pos(g)

        @expression.defined(g)
      end

      def to_sexp
        [:defined, @expression.to_sexp]
      end
    end
  end
end
