# coding: utf-8

Gem::Specification.new do |spec|
  spec.name          = "rubinius-code"
  spec.version       = "2.0"
  spec.authors       = ["Brian Shirai"]
  spec.email         = ["brixen@gmail.com"]
  spec.description   = %q{A suite of tools for working with code on the Rubinius language platform.}
  spec.summary       = %q{A suite of tools for working with code on the Rubinius language platform.}
  spec.homepage      = "https://github.com/rubinius/rubinius-code"
  spec.license       = "MPL-2.0"

  spec.required_ruby_version = ">= 1.9.2"

  spec.add_dependency "rubinius-ast", "~> 2"
  spec.add_dependency "rubinius-compiler", "~> 2"
  spec.add_dependency "rubinius-instructions", "~> 2"
  spec.add_dependency "rubinius-melbourne", "~> 2"
  spec.add_dependency "rubinius-processor", "~> 2"
  spec.add_dependency "rubinius-toolset", "~> 2"
end
