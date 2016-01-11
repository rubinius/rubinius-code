# coding: utf-8
require './lib/rubinius/instructions/version'

Gem::Specification.new do |spec|
  spec.name          = "rubinius-instructions"
  spec.version       = Rubinius::Instructions::VERSION
  spec.authors       = ["Brian Shirai"]
  spec.email         = ["brixen@gmail.com"]
  spec.summary       = %q{Support tools for Rubinius instruction set.}
  spec.description   = <<-EOD
The Rubinius virtual machine instructions are defined using a special
structure that is then used to generate documentation and implementations for
the bytecode interpreter and JIT compiler.
  EOD
  spec.homepage      = "https://github.com/rubinius-instructions"
  spec.license       = "BSD"

  spec.files         = `git ls-files -z`.split("\x0")
  spec.executables   = spec.files.grep(%r{^bin/}) { |f| File.basename(f) }
  spec.test_files    = spec.files.grep(%r{^(test|spec|features)/})
  spec.require_paths = ["lib"]

  spec.add_development_dependency "bundler", "~> 1.5"
  spec.add_development_dependency "rake"
end
