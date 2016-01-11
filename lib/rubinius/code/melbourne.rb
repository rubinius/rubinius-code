require "rubinius/melbourne/version"
require "rubinius/melbourne/melbourne"

module CodeTools
  class Melbourne
    attr_accessor :transforms
    attr_accessor :magic_handler
    attr_accessor :references
    attr_reader   :pre_exe

    def self.parse_string(string, name="(eval)", line=1)
      new(name, line).parse_string string
    end

    def self.parse_file(name, line=1)
      new(name, line).parse_file
    end

    def initialize(name, line, transforms=[])
      @name = name
      @line = line
      @transforms = transforms
      @magic_handler = nil
      @data_offset = nil
      @pre_exe = []

      # There can be multiple reported, we need to track them all.
      @syntax_errors = []
    end

    attr_reader :syntax_errors

    def add_pre_exe(node)
      @pre_exe << node if node
    end

    def add_magic_comment(str)
      if @magic_handler
        @magic_handler.add_magic_comment str
      end
    end

    def process_data(offset)
      @data_offset = offset
    end

    def syntax_error
      raise @syntax_errors[0] unless @syntax_errors.empty?
    end

    def parse_string(string)
      syntax_error unless ast = string_to_ast(string, @name, @line)
      ast
    end

    def parse_file
      unless @name and File.exist? @name
        raise Errno::ENOENT, @name.inspect
      end

      syntax_error unless ast = file_to_ast(@name, @line)
      ast = AST::EndData.new @data_offset, ast if @data_offset
      ast
    end

    def process_transforms(line, receiver, name, arguments, privately=false)
      @transforms.each do |transform|
        next unless transform.transform_kind == :call

        if node = transform.match?(line, receiver, name, arguments, privately)
          unless node.kind_of? AST::Node
            node = transform.new line, receiver, name, arguments, privately
          end
          return node
        end
      end
      nil
    end
  end
end
