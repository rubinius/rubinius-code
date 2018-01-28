# -*- encoding: us-ascii -*-

module CodeTools
  class Generator
    include GeneratorMethods

    ##
    # Jump label for the branch instructions. The use scenarios for labels:
    #   1. Used and then set
    #        g.goto_if_false label
    #        ...
    #        label.set!
    #   2. Set and then used
    #        label.set!
    #        ...
    #        g.goto_if_true label
    #   3. 1, 2
    #
    # Many labels are only used once. This class employs two small
    # optimizations. First, for the case where a label is used once then set,
    # the label merely records the point it was used and updates that location
    # to the concrete IP when the label is set. In the case where the label is
    # used multiple times, it records each location and updates them to an IP
    # when the label is set. In both cases, once the label is set, each use
    # after that updates the instruction stream with a concrete IP at the
    # point the label is used. This avoids the need to ever record all the
    # labels or search through the stream later to change symbolic labels into
    # concrete IP's.

    class Label
      attr_accessor :position
      attr_reader :used, :basic_block
      alias_method :used?, :used

      def initialize(generator, basic_block=true)
        @generator   = generator
        @basic_block = basic_block ? generator.new_basic_block : nil
        @position    = nil
        @used        = false
        @location    = nil
        @locations   = nil
      end

      def place
        @position = @generator.ip
      end

      def set!
        @position = @generator.ip
        if @locations
          @locations.each { |x| @generator.stream[x] = @position }
        elsif @location
          @generator.stream[@location] = @position
        end

        @generator.current_block.left = @basic_block
        @generator.current_block.close
        @generator.current_block = @basic_block
        @basic_block.open
      end

      def used_at(ip)
        if @position
          @generator.stream[ip] = @position
        elsif !@location
          @location = ip
        elsif @locations
          @locations << ip
        else
          @locations = [@location, ip]
        end
        @used = true
      end
    end

    class BasicBlock
      attr_accessor :left
      attr_accessor :right

      def initialize(generator)
        @generator  = generator
        @ip         = generator.ip
        @enter_size = nil
        @max_size   = 0
        @min_size   = 0
        @exit_ip    = 0
        @exit_size  = nil
        @stack      = 0
        @left       = nil
        @right      = nil
        @visited    = false
        @closed     = false
      end

      def add_stack(read, write)
        read_change = @stack - read
        @min_size = read_change if read_change < @min_size

        @stack += (write - read)

        @max_size = @stack if @stack > @max_size
      end

      def open
        @ip = @generator.ip
      end

      def close(record_exit=false)
        @closed = true

        if record_exit
          @exit_size = @stack
          @exit_ip = @generator.ip - 1
        end
      end

      def location(ip=nil)
        ip ||= @ip
        line = @generator.ip_to_line(ip)
        "#{@generator.name}: line: #{line}, IP: #{ip}"
      end

      SEPARATOR_SIZE = 40

      def invalid(message)
        puts message
        name = @generator.name.inspect
        size = (SEPARATOR_SIZE - name.size - 2) / 2
        size = 1 if size <= 0
        puts "\n#{"=" * size} #{name} #{"=" * (size + name.size % 2)}"

        literals = @generator.literals
        names = @generator.local_names
        stream = @generator.stream
        i = 0
        n = stream.size
        stack = 0

        while i < n
          insn = Rubinius::InstructionSet[stream[i]]
          printf "[%3d] %04d  %-28s" % [stack, i, insn.opcode.inspect]

          args = stream[i+1, insn.size-1]
          if insn.size > 1
            insn.args.each_with_index do |kind, index|
              arg = args[index]
              case kind
              when :literal
                printf "%s " % literals[arg].inspect
              when :local
                printf "%s " % (names ? names[arg] : arg)
              else
                printf "%d " % arg
              end
            end
          end

          puts

          if insn.variable_stack?
            use = insn.stack_consumed
            if use.kind_of? Array
              use = args[use[1] - 1] + use[0]
            end

            pro = insn.stack_produced
            if pro.kind_of? Array
              pro = (args[pro[1] - 1] * pro[2]) + pro[0]
            end

            stack += pro - use
          else
            stack += insn.stack_difference
          end

          i += insn.size
        end

        puts "-" * SEPARATOR_SIZE

        raise CompileError, message
      end

      def visited?
        @visited
      end

      def validate_stack
        @enter_size = 0

        stack = [self]
        until stack.empty?
          bb = stack.shift
          bb.flow_stack_size stack
        end
      end

      def flow_stack_size(stack)
        unless @visited
          @visited = true

          @generator.accumulate_stack(@enter_size + @max_size)

          net_size = @enter_size + @stack

          if net_size < 0
            invalid "net stack underflow in block starting at #{location}"
          end

          if @enter_size + @min_size < 0
            invalid "minimum stack underflow in block starting at #{location}"
          end

          if @exit_size and @enter_size + @exit_size < 1
            invalid "exit stack underflow in block starting at #{location(@exit_ip)}"
          end

          if @left
            @left.check_stack net_size
            stack.push @left unless @left.visited?
          end

          if @right
            @right.check_stack net_size
            stack.push @right unless @right.visited?
          end
        end
      end

      def check_stack(stack_size)
        if @enter_size
          unless stack_size == @enter_size
            invalid "unbalanced stack at #{location}: #{stack_size} != #{@enter_size}"
          end
        else
          if not @closed
            invalid "control fails to exit properly at #{location}"
          end

          @enter_size = stack_size
        end
      end
    end

    def initialize
      @stream = []
      @literals_map = Hash.new { |h,k| h[k] = add_literal(k) }
      @literals = []
      @ip = 0
      @modstack = []
      @break = nil
      @redo = nil
      @next = nil
      @retry = nil
      @last_line = nil
      @file = nil
      @lines = []
      @primitive = nil
      @instruction = nil
      @for_block = nil
      @for_module_body = nil

      @required_args = 0
      @post_args = 0
      @total_args = 0
      @arity = 0

      @detected_args = 0
      @detected_locals = 0

      @splat_index = nil
      @local_names = nil
      @block_index = nil
      @keywords = nil
      @kwrest_index = nil
      @local_count = 0
      @registers = 0

      @state = []
      @generators = []

      @stack_locals = 0

      @enter_block = new_basic_block
      @current_block = @enter_block
      @max_stack = 0
    end

    attr_reader   :ip, :stream, :iseq, :literals
    attr_accessor :break, :redo, :next, :retry, :file, :name,
                  :required_args, :post_args, :total_args, :splat_index,
                  :local_count, :local_names, :primitive, :for_block, :for_module_body,
                  :current_block, :detected_args, :detected_locals,
                  :block_index, :arity, :keywords, :kwrest_index, :registers

    def execute(node)
      node.bytecode self
    end

    alias_method :run, :execute

    # Formalizers

    def encode
      @iseq = Rubinius::InstructionSequence.new @stream.to_tuple

      begin
        # Validate the stack and calculate the max depth
        @enter_block.validate_stack
      rescue Exception => e
        if $DEBUG
          puts "Error computing stack for #{@name}: #{e.message} (#{e.class})"
        end
        raise e
      end

      @generators.each { |x| @literals[x].encode }
    end

    def package(klass)
      @generators.each { |x| @literals[x] = @literals[x].package klass }

      code = klass.new
      code.iseq           = @iseq
      code.literals       = @literals.to_tuple
      code.lines          = @lines.to_tuple

      code.required_args  = @required_args
      code.post_args      = @post_args
      code.total_args     = @total_args
      code.splat          = @splat_index
      code.arity          = @arity
      code.local_count    = @local_count
      code.local_names    = @local_names.to_tuple if @local_names
      code.keywords       = @keywords.to_tuple if @keywords
      code.registers      = @registers

      code.add_metadata :block_index, @block_index if @block_index
      code.add_metadata :kwrest_index, @kwrest_index if @kwrest_index

      code.stack_size     = max_stack_size
      code.file           = @file
      code.name           = @name
      code.primitive      = @primitive

      if @for_block
        code.add_metadata :for_block, true
      end

      if @for_module_body
        code.add_metadata :for_module_body, true
      end

      code
    end

    def use_detected
      if @required_args < @detected_args
        @required_args = @detected_args
      end

      if @total_args < @detected_args
        @total_args = @detected_args
      end

      if @local_count < @detected_locals
        @local_count = @detected_locals
      end
    end

    # Commands (these don't generate data in the stream)

    def state
      @state.last
    end

    def push_state(scope)
      @state << AST::State.new(scope)
    end

    def pop_state
      @state.pop
    end

    def push_modifiers
      @modstack << [@break, @redo, @next, @retry]
    end

    def pop_modifiers
      @break, @redo, @next, @retry = @modstack.pop
    end

    def definition_line(line)
      unless @stream.empty?
        raise Exception, "only use #definition_line first"
      end

      @lines << -1
      @lines << line

      @last_line = line
    end

    def set_line(line)
      raise Exception, "source code line cannot be nil" unless line

      if !@last_line
        @lines << @ip
        @lines << line
        @last_line = line
      elsif line != @last_line
        if @lines[-2] == @ip
          @lines[-1] = line
        else
          @lines << @ip
          @lines << line
        end

        @last_line = line
      end
    end

    def line
      @last_line
    end

    def ip_to_line(ip)
      total = @lines.size - 2
      i = 0

      while i < total
        if ip >= @lines[i] and ip <= @lines[i+2]
          return @lines[i+1]
        end

        i += 2
      end
    end

    def close
      if @lines.empty?
        msg = "closing a method definition with no line info: #{file}:#{line}"
        raise Exception, msg
      end

      @lines << @ip
    end

    def send_primitive(name)
      @primitive = name
    end

    def new_label
      Label.new(self)
    end

    def new_register
      (@registers += 1) - 1
    end

    # Helpers

    def new_basic_block
      BasicBlock.new self
    end

    def accumulate_stack(size)
      @max_stack = size if size > @max_stack
    end

    def max_stack_size
      size = @max_stack + @local_count + @stack_locals
      size += 1 if @for_block
      size
    end

    def new_stack_local
      idx = @stack_locals
      @stack_locals += 1
      return idx
    end

    def push_generator(generator)
      index = @literals.size
      push_literal generator
      @generators << index
      index
    end

    def add_generator(generator)
      index = add_literal generator
      @generators << index
      index
    end

    def find_literal(literal)
      @literals_map[literal]
    end

    def add_literal(literal)
      index = @literals.size
      @literals << literal
      index
    end

    def push_float(float)
      emit_push_literal add_literal(float)
    end

    def push_literal(literal)
      super find_literal(literal)
    end

    def r_load_literal(reg, literal)
      super reg, find_literal(literal)
    end

    # Minor meta operations that can be used to detect
    # the number of method arguments needed
    def push_arg(idx)
      push_local(idx)
      @detected_args = @detected_locals
    end

    def push_local(index)
      if @detected_locals <= index
        @detected_locals = index + 1
      end

      super
    end

    def set_arg(idx)
      set_local(idx)
      @detected_args = @detected_locals
    end

    def set_local(index)
      if @detected_locals <= index
        @detected_locals = index + 1
      end

      super
    end

    def last_match(mode, which)
      push_int Integer(mode)
      push_int Integer(which)
      invoke_primitive :regexp_last_match_result, 2
    end

    def send(meth, count, priv=false)
      allow_private if priv

      unless count.kind_of? Fixnum
        raise CompileError, "count must be a number"
      end

      if count == 0
        send_method meth
      else
        send_stack meth, count
      end
    end

    def send_with_block(meth, count, priv=false)
      allow_private if priv

      unless count.kind_of? Fixnum
        raise CompileError, "count must be a number"
      end

      send_stack_with_block meth, count
    end

    def send_with_splat(meth, args, priv=false, concat=false)
      val = 0
      val |= Rubinius::InstructionSet::CALL_FLAG_CONCAT if concat
      set_call_flags val unless val == 0

      allow_private if priv

      send_stack_with_splat meth, args
    end

    def send_super(meth, args, splat=false)
      if splat
        send_super_stack_with_splat meth, args
      else
        send_super_stack_with_block meth, args
      end
    end

    def ret
      super 0
    end

    # instructions that can cause stack unwinding

    def cast_array
      super
      unwind
    end

    def cast_for_multi_block_arg
      super
      unwind
    end

    def cast_for_single_block_arg
      super
      unwind
    end

    def cast_for_splat_block_arg
      super
      unwind
    end

    def cast_multi_value
      super
      unwind
    end

    def check_frozen
      super
      unwind
    end

    def create_block(literal)
      super
      unwind
    end

    def ensure_return
      super
      unwind
    end

    def find_const(literal)
      super
      unwind
    end

    def invoke_primitive(literal, count)
      super
      unwind
    end

    def object_to_s(literal)
      super
      unwind
    end

    def passed_arg(index)
      super
      unwind
    end

    def passed_blockarg(count)
      super
      unwind
    end

    def push_block_arg
      super
      unwind
    end

    def push_const(literal)
      super
      unwind
    end

    def push_ivar(literal)
      super
      unwind
    end

    def push_local_depth(depth, index)
      super
      unwind
    end

    def push_proc
      super
      unwind
    end

    def raise_break
      super
      unwind
    end

    def raise_exc
      super
      unwind
    end

    def raise_return
      super
      unwind
    end

    def reraise
      super
      unwind
    end

    def send_method(literal)
      super
      unwind
    end

    def send_stack(literal, count)
      super
      unwind
    end

    def send_stack_with_block(literal, count)
      super
      unwind
    end

    def send_stack_with_splat(literal, count)
      super
      unwind
    end

    def send_super_stack_with_block(literal, count)
      super
      unwind
    end

    def send_super_stack_with_splat(literal, count)
      super
      unwind
    end

    def send_vcall(literal)
      super
      unwind
    end

    def set_ivar(literal)
      super
      unwind
    end

    def set_local_depth(depth, index)
      super
      unwind
    end

    def string_build(count)
      super
      unwind
    end

    def string_dup
      super
      unwind
    end

    def unwind
      super 0
    end

    def yield_splat(count)
      super
      unwind
    end

    def yield_stack(count)
      super
      unwind
    end

    def zsuper(literal)
      super
      unwind
    end
  end
end
