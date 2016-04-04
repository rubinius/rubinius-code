# -*- encoding: us-ascii -*-

module CodeTools
  module AST
    class Self < Node
      def bytecode(g)
        pos(g)

        g.push_self
      end

      def defined(g)
        g.push_literal "self"
      end

      def value_defined(g, f)
        g.push_self
      end

      def to_sexp
        [:self]
      end
    end
  end
end
