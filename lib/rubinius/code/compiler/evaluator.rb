# -*- encoding: us-ascii -*-

##
# Used for the Rubinius::asm Compiler hook.

module CodeTools
  module AST
    class Node
    end

    class ClosedScope < Node
    end

    class VariableAccess < Node
    end

    class VariableAssignment < Node
    end

    class Evaluator
      attr_accessor :self

      def initialize(generator, names, arguments)
        @self = generator
        @locals = {}

        names.each_with_index do |name, index|
          set_local name, arguments[index]
        end
      end

      def execute(node)
        node.execute self
      end

      def get_local(name)
        @locals[name]
      end

      def set_local(name, value)
        @locals[name] = value
      end
    end

    class Container < ClosedScope
      def execute(e)
        @body.execute(e)
        return true
      end
    end

    class TrueLiteral < Node
      def execute(e)
        true
      end
    end

    class FalseLiteral < Node
      def execute(e)
        false
      end
    end

    class NilLiteral < Node
      def execute(e)
        nil
      end
    end

    class Self < Node
      def execute(e)
        e.self
      end
    end

    class And < Node
      def execute(e)
        @left.execute(e) and @right.execute(e)
      end
    end

    class Or < And
      def execute(e)
        @left.execute(e) or @right.execute(e)
      end
    end

    class Not < Node
      def execute(e)
        not @child.execute(e)
      end
    end

    class Negate < Node
      def execute(e)
        -@child.execute(e)
      end
    end

    class NumberLiteral < Node
      def execute(e)
        @value
      end
    end

    class Literal < Node
      def execute(e)
        @value
      end
    end

    class RegexLiteral < Node
      def execute(e)
        ::Regexp.new(@source, @options)
      end
    end

    class StringLiteral < Node
      def execute(e)
        @string.dup
      end
    end

    class DynamicString < StringLiteral
      def execute(e)
        str = @string.dup
        @body.each do |x|
          str << x.execute(e)
        end

        str
      end
    end

    class DynamicRegex < DynamicString
      def execute(e)
        ::Regexp.new super(e)
      end
    end

    class DynamicOnceRegex < DynamicRegex
      def execute(e)
        @value ||= super(e)
      end
    end

    class If < Node
      def execute(e)
        if @condition.execute(e)
          @then.execute(e) if @then
        else
          @else.execute(e) if @else
        end
      end
    end

    class While < Node
      def execute(e)
        if @check_first
          while @condition.execute(e)
            @body.execute(e)
          end
        else
          begin
            @body.execute(e)
          end while @condition.execute(e)
        end
      end
    end

    class Until < While
      def execute(e)
        if @check_first
          until @condition.execute(e)
            @body.execute(e)
          end
        else
          begin
            @body.execute(e)
          end until @condition.execute(e)
        end
      end
    end

    class Block < Node
      def execute(e)
        val = nil
        @array.each do |x|
          val = x.execute(e)
        end

        return val
      end
    end

    class LocalVariableAccess < VariableAccess
      def execute(e)
        e.get_local @name
      end
    end

    class LocalVariableAssignment < VariableAssignment
      def execute(e)
        e.set_local @name, @value.execute(e)
      end
    end

    class ArrayLiteral < Node
      def execute(e)
        @body.map { |x| x.execute(e) }
      end
    end

    class EmptyArray < Node
      def execute(e)
        []
      end
    end

    class HashLiteral < Node
      def execute(e)
        args = @array.map { |x| x.execute(e) }
        Hash[*args]
      end
    end

    class SymbolLiteral < Node
      def execute(e)
        @value
      end
    end

    class InstanceVariableAccess < VariableAccess
      def execute(e)
        e.self.instance_variable_get @name
      end
    end

    class InstanceVariableAssignment < VariableAssignment
      def execute(e)
        e.self.instance_variable_set @name, @value.execute(e)
      end
    end

    class GlobalVariableAccess < VariableAccess
      def execute(e)
        ::Rubinius::Globals[@name]
      end
    end

    class GlobalVariableAssignment < VariableAssignment
      def execute(e)
        ::Rubinius::Globals[@name] = @value.execute(e)
      end
    end

    class ConstantAccess < Node
      def execute(e)
        Object.const_get @name
      end
    end

    class ScopedConstant < Node
      def execute(e)
        parent = @parent.execute(e)
        parent.const_get @name
      end
    end

    class ToplevelConstant < Node
      def execute(e)
        Object.const_get @name
      end
    end

    class Send < Node
      def execute_receiver(e)
        if @receiver.kind_of? Self
          e.self
        else
          @receiver.execute(e)
        end
      end

      def execute(e)
        receiver = execute_receiver(e)

        receiver.__send__ @name
      end
    end

    class SendWithArguments < Send
      def execute(e)
        arguments = @arguments.execute(e)
        receiver = execute_receiver(e)

        receiver.__send__ @name, *arguments
      end
    end

    class ActualArguments < Node
      def execute(e)
        array = @array.map { |x| x.execute(e) }
        array << @splat.execute if @splat.kind_of? SplatValue
        array
      end
    end

    class Yield < SendWithArguments
      def execute(e)
        # TODO
        e.block.call(*@arguments.execute(e))
      end
    end

    class ExecuteString < StringLiteral
      def execute(e)
        `#{@string.execute(e)}`
      end
    end

    class ToString < Node
      def execute(e)
        @child.execute(e).to_s
      end
    end

    class DynamicExecuteString < DynamicString
      def execute(e)
        `#{super(e)}`
      end
    end
  end
end
