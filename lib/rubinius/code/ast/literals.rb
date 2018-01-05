# -*- encoding: us-ascii -*-

module CodeTools
  module AST
    class ArrayLiteral < Node
      attr_accessor :body

      def initialize(line, array)
        @line = line
        @body = array
      end

      def bytecode(g)
        pos(g)

        @body.each do |x|
          x.bytecode(g)
        end

        g.make_array @body.size
      end

      def defined(g)
        not_found = g.new_label
        done = g.new_label
        @body.each do |x|
          x.defined(g)
          g.goto_if_false not_found
        end
        g.push_literal "expression"
        g.goto done
        not_found.set!
        g.push_nil
        g.goto done

        done.set!
      end

      def to_sexp
        @body.inject([:array]) { |s, x| s << x.to_sexp }
      end
    end

    class EmptyArray < Node
      def bytecode(g)
        pos(g)

        g.make_array 0
      end

      def defined(g)
        g.push_literal "expression"
      end

      def to_sexp
        [:array]
      end
    end

    class FalseLiteral < Node
      def bytecode(g)
        pos(g)

        g.push_false
      end

      def defined(g)
        g.push_literal "false"
      end

      def to_sexp
        [:false]
      end
    end

    class TrueLiteral < Node
      def bytecode(g)
        pos(g)

        g.push_true
      end

      def defined(g)
        g.push_literal "true"
      end

      def to_sexp
        [:true]
      end
    end

    class FloatLiteral < Node
      attr_accessor :value

      def initialize(line, str)
        @line = line
        @value = str.to_f
      end

      def bytecode(g)
        pos(g)

        g.push_float @value
      end

      def defined(g)
        g.push_literal "expression"
      end

      def to_sexp
        [:lit, @value]
      end
    end

    class HashLiteral < Node
      attr_accessor :array

      def initialize(line, array)
        @line = line
        @array = array
      end

      def bytecode(g)
        pos(g)

        count = @array.size
        i = 0

        g.push_cpath_top
        g.find_const :Hash
        g.push_int count / 2
        g.send :new_from_literal, 1

        while i < count
          key = @array[i]
          value = @array[i + 1]

          if key
            g.dup
            key.bytecode(g)
            value.bytecode(g)
            g.send :[]=, 2
            g.pop
          else
            case value
            when HashLiteral
              value.merge_entries_bytecode(g)
            else
              g.push_rubinius
              g.find_const :Runtime
              g.swap
              value.bytecode(g)
              g.send :splat_hash_value, 2
            end
          end

          i += 2
        end
      end

      def merge_entries_bytecode(g)
        count = @array.size
        i = 0

        while i < count
          key = @array[i]
          value = @array[i + 1]
          if key
            g.push_rubinius
            g.find_const :Runtime
            g.swap
            key.bytecode(g)
            value.bytecode(g)
            g.send :splat_hash_entry, 3
          else
            case value
            when HashLiteral
              value.merge_entries_bytecode(g)
            else
              g.push_rubinius
              g.find_const :Runtime
              g.swap
              value.bytecode(g)
              g.send :splat_hash_value, 2
            end
          end

          i += 2
        end
      end

      def defined(g)
        g.push_literal "expression"
      end

      def to_sexp
        @array.inject([:hash]) { |s, x| s << (x ? x.to_sexp : [:hash_splat]) }
      end
    end

    class SymbolLiteral < Node
      attr_accessor :value

      def initialize(line, sym)
        @line = line
        @value = sym
      end

      def bytecode(g)
        pos(g)

        g.push_literal @value
      end

      def defined(g)
        g.push_literal "expression"
      end

      def to_sexp
        [:lit, @value]
      end
    end

    class NilLiteral < Node
      def bytecode(g)
        pos(g)

        g.push_nil
      end

      def defined(g)
        g.push_literal "nil"
      end

      def to_sexp
        [:nil]
      end
    end

    class NumberLiteral < Node
      attr_accessor :value

      def initialize(line, value)
        @line = line
        @value = value
      end

      def bytecode(g)
        pos(g)

        g.push_literal @value
      end

      def defined(g)
        g.push_literal "expression"
      end

      def to_sexp
        [:lit, @value]
      end
    end

    class FixnumLiteral < NumberLiteral
      def initialize(line, value)
        @line = line
        @value = value
      end

      def bytecode(g)
        pos(g)

        g.push_int @value
      end

      def defined(g)
        g.push_literal "expression"
      end
    end

    class RationalLiteral < NumberLiteral
      def bytecode(g)
        pos(g)

        g.push_literal @value
      end
    end

    class ImaginaryLiteral < NumberLiteral
      def bytecode(g)
        pos(g)

        g.push_literal @value
      end
    end

    class Range < Node
      attr_accessor :start, :finish

      def initialize(line, start, finish)
        @line = line
        @start = start
        @finish = finish
      end

      def bytecode(g)
        pos(g)

        g.push_cpath_top
        g.find_const :Range
        g.send :allocate, 0, true
        g.dup
        @start.bytecode(g)
        @finish.bytecode(g)
        g.send :initialize, 2, true
        g.pop
      end

      def defined(g)
        g.push_literal "expression"
      end

      def to_sexp
        [:dot2, @start.to_sexp, @finish.to_sexp]
      end
    end

    class RangeExclude < Range
      def initialize(line, start, finish)
        @line = line
        @start = start
        @finish = finish
      end

      def bytecode(g)
        pos(g)

        g.push_cpath_top
        g.find_const :Range
        g.send :allocate, 0, true
        g.dup
        @start.bytecode(g)
        @finish.bytecode(g)
        g.push_true
        g.send :initialize, 3, true
        g.pop
      end

      def to_sexp
        [:dot3, @start.to_sexp, @finish.to_sexp]
      end
    end

    class PEGLiteral < Node
      attr_accessor :source

      def initialize(line, str)
        @line = line
        @source = str
      end

      def bytecode(g)
        pos(g)
        build = g.new_label
        done = g.new_label

        g.push_nil

        build.set!
        g.push_memo nil
        g.dup
        g.goto_if_not_nil done

        g.pop
        g.push_rubinius
        g.find_const :PEG
        g.push_literal @source
        g.send :compile, 1
        g.goto build

        done.set!
      end
    end

    class RegexLiteral < Node
      attr_accessor :source, :options

      def initialize(line, str, flags)
        @line = line
        @source = str
        @options = flags
      end

      def bytecode(g)
        pos(g)

        build = g.new_label
        done = g.new_label

        g.push_nil

        build.set!
        g.push_memo nil
        g.dup
        g.goto_if_not_nil done

        g.pop
        g.push_cpath_top
        g.find_const :Regexp
        g.push_literal @source
        g.push_int @options
        g.send :new, 2
        g.goto build

        done.set!
      end

      def defined(g)
        g.push_literal "expression"
      end

      def to_sexp
        [:regex, @source, @options]
      end
    end

    class StringLiteral < Node
      attr_accessor :string

      def initialize(line, str)
        @line = line
        @string = str
      end

      def bytecode(g)
        pos(g)

        g.push_literal @string
        g.string_dup
      end

      def defined(g)
        g.push_literal "expression"
      end

      def to_sexp
        [:str, @string]
      end
    end

    class DynamicString < StringLiteral
      attr_accessor :array, :options

      def initialize(line, str, array)
        @line = line
        @string = str
        @array = array
      end

      # This extensive logic is 100% for optimizing rather ridiculous edge
      # cases for string interpolation and I (brixen) do not think it is
      # worthwhile.
      #
      # Some examples:
      #
      #  "#{}"
      #  "#{} foo"
      #  "foo #{}"
      #  "#{}#{}"
      #  "#{bar}"
      #
      # Also, as Zocx pointed out in IRC, the following code is not compatible
      # in Rubinius because we convert an empty evstr into "" directly in
      # Melbourne parse tree to AST processor rather than calling #to_s on
      # 'nil'.
      #
      # def nil.to_s; "hello"; end
      # a = "#{}" # => "hello" in MRI
      #
      # We also do not handle any case where #to_s does not actually return a
      # String instance.
      #
      def bytecode(g)
        pos(g)

        if @string.empty?
          if @array.size == 1
            case x = @array.first
            when StringLiteral
              x.bytecode(g)
            else
              x.bytecode(g)
              # string_build has some auto-conversion logic, use it.
              g.string_build 1
            end
            return
          end

          prefix = false
        else
          prefix = true
          g.push_literal @string
        end

        total = 0
        @array.each do |e|
          case e
          when StringLiteral
            unless e.string.empty?
              g.push_literal e.string
              total += 1
            end
          else
            e.bytecode(g)
            total += 1
          end
        end

        if prefix
          if total == 0
            g.string_dup
            return
          end
          total += 1
        else
          if total == 0
            g.push_literal ""
            g.string_dup
            return
          elsif total == 1
            g.string_build 1
            return
          end
        end

        g.string_build total
      end

      def defined(g)
        g.push_literal "expression"
        g.string_dup
      end

      def sexp_name
        :dstr
      end

      def to_sexp
        @array.inject([sexp_name, @string]) { |s, x| s << x.to_sexp }
      end
    end

    class DynamicSymbol < DynamicString
      def bytecode(g)
        super(g)
        g.send :to_sym, 0, true
      end

      def sexp_name
        :dsym
      end
    end

    class DynamicExecuteString < DynamicString
      def bytecode(g)
        g.push_self
        super(g)
        g.send :`, 1, true #`
      end

      def sexp_name
        :dxstr
      end
    end

    class DynamicRegex < DynamicString
      def initialize(line, str, array, flags)
        super line, str, array
        @options = flags || 0
      end

      def bytecode(g)
        g.push_cpath_top
        g.find_const :Regexp
        super(g)
        g.push_int @options
        g.send :new, 2
      end

      def sexp_name
        :dregx
      end

      def to_sexp
        sexp = super
        sexp << @options if @options != 0
        sexp
      end
    end

    class DynamicOnceRegex < DynamicRegex
      def bytecode(g)
        pos(g)

        build = g.new_label
        done = g.new_label

        g.push_nil

        build.set!
        g.push_memo nil
        g.dup
        g.goto_if_not_nil done

        g.pop
        super(g)
        g.goto build

        done.set!
      end

      def sexp_name
        :dregx_once
      end
    end

    class ExecuteString < StringLiteral
      def bytecode(g)
        pos(g)

        g.push_self
        super(g)
        g.send :`, 1, true # ` (silly vim/emacs)
      end

      def to_sexp
        [:xstr, @string]
      end
    end
  end
end
