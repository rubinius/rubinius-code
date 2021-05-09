# coding: utf-8
require './lib/rubinius/code/toolset/version'

Gem::Specification.new do |spec|
  spec.name          = "rubinius-toolset"
  spec.version       = Rubinius::ToolSets::VERSION
  spec.authors       = ["Brian Shirai"]
  spec.email         = ["brixen@gmail.com"]
  spec.description   = <<-EOD
Rubinius::ToolSet provides a registry for code tools. These include
the Rubinius bytecode compiler and parser. These, in turn, depend on
other components like the AST and bytecode emitter and serializer.

ToolSets provide a mechanism for other languages to reuse as much of
the Rubinius code tools as are suitable for that language.
  EOD
  spec.summary       = %q{A registry for Rubinius code tools}
  spec.homepage      = "https://github.com/rubinius/rubinius-code"
  spec.license       = "MPL-2.0"

  spec.files         = `git ls-files lib/rubinius/code/toolset*`.split($/)
  spec.test_files    = spec.files.grep(%r{^(test|spec|features)/})
  spec.require_paths = ["lib"]

  spec.add_development_dependency "bundler", "~> 1.3"
  spec.add_development_dependency "rake", ">= 12.3.3"
  spec.add_development_dependency "mspec", "~> 1.5"
  spec.add_development_dependency "rubinius-bridge", "~> 1.0"
end
