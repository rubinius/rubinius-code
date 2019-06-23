# -*- encoding: us-ascii -*-

module CodeTools
  module AST
    class And < Node
      attr_accessor :left, :right

      def initialize(line, left, right)
        @line = line
        @left = left
        @right = right
      end

      def bytecode(g, use_gif=true)
        @left.bytecode(g)
        g.dup
        lbl = g.new_label

        if use_gif
          g.goto_if_false lbl
        else
          g.goto_if_true lbl
        end

        g.pop
        @right.bytecode(g)
        lbl.set!
      end

      def defined(g)
        g.push_literal "expression"
        g.string_dup
      end

      def sexp_name
        :and
      end

      def to_sexp
        [sexp_name, @left.to_sexp, @right.to_sexp]
      end
    end

    class Or < And
      def bytecode(g)
        super(g, false)
      end

      def sexp_name
        :or
      end
    end

    class Not < Node
      attr_accessor :value

      def initialize(line, value)
        @line = line
        @value = value
      end

      def bytecode(g)
        true_label = g.new_label
        end_label = g.new_label

        @value.bytecode(g)
        g.goto_if_true true_label

        g.push_true
        g.goto end_label

        true_label.set!
        g.push_false
        end_label.set!
      end

      def defined(g)
        t = g.new_label
        f = g.new_label
        done = g.new_label

        case @value
        when GlobalVariableAccess, InstanceVariableAccess
          g.goto t
        else
          @value.value_defined(g, f)
          g.pop
        end

        t.set!
        g.push_literal "expression"
        g.goto done

        f.set!
        g.push_tagged_nil 0

        done.set!
      end

      def to_sexp
        [:not, @value.to_sexp]
      end
    end

    class OpAssignElement < Node
      attr_accessor :receiver, :op, :arguments, :value

      def initialize(line, receiver, arguments, op, value)
        @line = line
        @receiver = receiver
        @op = op
        arguments = nil if arguments.is_a?(EmptyArray)
        @arguments = Arguments.new line, arguments
        @value = value
      end

      def bytecode(g)
        pos(g)

        # X: Snippet used for explanation: h[:a] += 3
        # X: given h = { :a => 2 }
        # X: Pull h onto the stack
        @receiver.bytecode(g)
        # X: Pull :a in
        @arguments.bytecode(g)
        recv_stack = @arguments.stack_size + 1

        # Dup the receiver and arguments to use later
        g.dup_many recv_stack

        #
        # X: Call [](:a) on h
        #
        # @arguments.size will be 1

        if @arguments.splat?
          g.push_tagged_nil 0
          g.send_with_splat :[], @arguments.size
        else
          g.send :[], @arguments.size
        end

        # X: 2 is now on the top of the stack (TOS)

        # A special case, where we use the value as boolean
        if @op == :or or @op == :and
          fnd = g.new_label
          fin = g.new_label
          assign = g.new_label

          # We dup the value from [] to leave it as the value of the
          # expression

          g.dup
          if @op == :or
            g.goto_if_true fnd
          else
            g.goto_if_false fnd
          end

          # Ok, take the extra copy off and pull the value onto the stack
          g.pop

          # The receiver and arguments are still on the stack

          old_break = g.break
          new_break = g.new_label
          g.break = new_break

          @value.bytecode(g)

          g.goto assign

          new_break.set!
          if old_break
            g.pop_many recv_stack + 1
            g.push_tagged_nil 0
            g.goto old_break
          end

          g.break = old_break

          assign.set!

          # retain the rhs as the expression value
          g.dup
          g.move_down recv_stack + 1

          if @arguments.splat?
            g.send :push, 1
            g.push_tagged_nil 0
            g.send_with_splat :[]=, @arguments.size
          else
            g.send :[]=, @arguments.size + 1
          end
          g.pop

          # Leaves the value we moved down the stack on the top
          g.goto fin

          fnd.set!

          # Clean up the stack but retain return value from :[]
          g.move_down recv_stack
          g.pop_many recv_stack

          fin.set!
        else
          assign = g.new_label

          old_break = g.break
          new_break = g.new_label
          g.break = new_break

          # @op is something like + or -
          # We pull in @value to the stack
          @value.bytecode(g)
          # X: 3 TOS

          g.goto assign

          new_break.set!
          if old_break
            g.pop_many recv_stack + 2
            g.push_tagged_nil 0
            g.goto old_break
          end

          g.break = old_break

          assign.set!

          # ... then call it as an argument to @or, called on the return
          # from [].
          # X: 2 + 3

          g.send @op, 1
          # X: 5 TOS

          # The new value is on the stack now. It is the last argument to the call
          # to []= because your dupd versions of recv and arguments are still on the stack.

          # retain the rhs as the expression value
          g.dup
          g.move_down recv_stack + 1

          # X: Call []=(:a, 5) on h
          if @arguments.splat?
            g.send :push, 1
            g.push_tagged_nil 0
            g.send_with_splat :[]=, @arguments.size
          else
            g.send :[]=, @arguments.size + 1
          end
          g.pop
        end
      end

      def to_sexp
        arguments = [:arglist]

        case @arguments
        when PushArguments
          arguments << @arguments.to_sexp
        else
          arguments += @arguments.to_sexp
        end

        case @op
        when :or
          op = :"||"
        when :and
          op = :"&&"
        else
          op = @op
        end
        [:op_asgn1, @receiver.to_sexp, arguments, op, @value.to_sexp]
      end
    end

    class OpAssignAttribute < Node
      attr_accessor :receiver, :name, :assign, :op, :value

      def initialize(line, receiver, name, op, value)
        @line = line
        @receiver = receiver
        @name = name
        @op = op
        @value = value
        @assign = name.to_s[-1] == ?= ? name : :"#{name}="
      end

      def bytecode(g, anddot=false)
        pos(g)

        # X: h.a += 3, given h.a == 2
        @receiver.bytecode(g) unless anddot
        # X: TOS = h
        g.dup
        g.send @name, 0
        # X: TOS = 2

        if @op == :or or @op == :and
          fnd = g.new_label
          fin = g.new_label
          assign = g.new_label

          g.dup
          if @op == :or
            g.goto_if_true fnd
          else
            g.goto_if_false fnd
          end

          # Remove the copy of 2 and push @value on the stack
          g.pop

          old_break = g.break
          new_break = g.new_label
          g.break = new_break

          @value.bytecode(g)

          g.goto assign

          new_break.set!
          if old_break
            g.pop_many 2
            g.push_tagged_nil 0
            g.goto old_break
          end

          g.break = old_break

          assign.set!

          # Retain the this value to use as the expression value
          g.dup
          g.move_down 2

          # Call the assignement method, passing @value as the argument
          g.send @assign, 1
          g.pop

          g.goto fin

          fnd.set!

          # Clean up the stack
          g.swap
          g.pop

          fin.set!
        else
          assign = g.new_label

          old_break = g.break
          new_break = g.new_label
          g.break = new_break

          @value.bytecode(g)

          g.goto assign

          new_break.set!
          if old_break
            g.pop_many 3
            g.push_tagged_nil 0
            g.goto old_break
          end

          g.break = old_break

          assign.set!

          # X: TOS = 3
          # X: 2 + 3
          g.send @op, 1

          # Retain the this value to use as the expression value
          g.dup
          g.move_down 2
          # X: TOS = 5
          g.send @assign, 1
          # X: TOS = 5 (or whatever a=() returns)

          # Discard the methods return value
          g.pop
        end
      end

      def sexp_name
        :op_asgn2
      end

      def to_sexp
        case @op
        when :or
          op = :"||"
        when :and
          op = :"&&"
        else
          op = @op
        end
        [sexp_name, @receiver.to_sexp, :"#{@name}=", op, @value.to_sexp]
      end
    end

    class AndOpAssignAttribute < OpAssignAttribute
      def bytecode(g)
        done = g.new_label

        @receiver.bytecode(g)

        g.dup
        g.goto_if_nil done

        super(g, true)

        done.set!
      end

      def sexp_name
        :and_op_asgn2
      end
    end

    class OpAssignAnd < Node
      attr_accessor :left, :right

      def initialize(line, left, right)
        @line = line
        @left = left
        @right = right
      end

      def bytecode(g)
        pos(g)

        @left.bytecode(g)
        lbl = g.new_label
        g.dup
        g.goto_if_false lbl
        g.pop
        @right.bytecode(g)
        lbl.set!
      end

      def defined(g)
        g.push_literal "assignment"
      end

      def sexp_name
        :op_asgn_and
      end

      def to_sexp
        [sexp_name, @left.to_sexp, @right.to_sexp]
      end
    end

    class OpAssignOr < OpAssignAnd
      def bytecode(g)
        pos(g)

        g.state.push_op_asgn
        @left.or_bytecode(g) do
          g.state.pop_op_asgn
          @right.bytecode(g)
        end
      end

      def sexp_name
        :op_asgn_or
      end
    end
  end
end
