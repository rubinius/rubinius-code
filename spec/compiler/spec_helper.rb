require 'rubinius/bridge'
require 'rubinius/code/toolset'

Rubinius::ToolSets.create :spec do
  require "rubinius/code/melbourne"
  require "rubinius/code/processor"
  require "rubinius/code/compiler"
  require "rubinius/code/ast"

  require 'spec/compiler/custom/matchers/compile_as'
  require 'spec/compiler/custom/runner/relates'
end
