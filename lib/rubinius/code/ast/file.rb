# -*- encoding: us-ascii -*-

module CodeTools
  module AST
    class File < Node
      def bytecode(g)
        pos(g)

        g.push_file
        g.string_dup
      end

      def defined(g)
        g.push_literal "expression"
      end

      def to_sexp
        [:file]
      end
    end
  end
end
