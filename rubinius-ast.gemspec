# coding: utf-8
require './lib/rubinius/code/ast/version'

Gem::Specification.new do |spec|
  spec.name          = "rubinius-ast"
  spec.version       = CodeTools::AST::VERSION
  spec.authors       = ["Brian Shirai"]
  spec.email         = ["brixen@gmail.com"]
  spec.description   = %q{An Abstract Syntax Tree for the Rubinius language platform.}
  spec.summary       = %q{An Abstract Syntax Tree for the Rubinius language platform.}
  spec.homepage      = "https://github.com/rubinius/rubinius-code"
  spec.license       = "MPL-2.0"

  spec.files         = `git ls-files lib/rubinius/code/ast*`.split($/)
  spec.test_files    = spec.files.grep(%r{^(test|spec|features)/})
  spec.require_paths = ["lib"]

  spec.add_development_dependency "bundler", "~> 1.3"
  spec.add_development_dependency "rake", ">= 12.3.3"
end
