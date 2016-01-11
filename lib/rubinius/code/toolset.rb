require "rubinius/toolset/version"

module Rubinius
  module ToolSets
    # Create a new ToolSet, with an optional name. The ToolSet is yielded to
    # the optional block.
    def self.create(name=nil)
      @current = Module.new
      @current.const_set :ToolSet, @current

      if name
        name = name.to_s.split("_").map { |x| x.capitalize }.join
        const_set name, @current
      end

      if block_given?
        begin
          loaded_features = $LOADED_FEATURES.dup
          $LOADED_FEATURES.clear

          yield @current

          @current.send :include, ::CodeTools
          ::Object.send :remove_const, :CodeTools
        ensure
          $LOADED_FEATURES.replace loaded_features
        end
      end

      @current
    end

    # Returns the current ToolSet.
    def self.current
      @current ||= create
    end
  end
end
