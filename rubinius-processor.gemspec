# coding: utf-8
require './lib/rubinius/processor/version'

Gem::Specification.new do |spec|
  spec.name          = "rubinius-processor"
  spec.version       = CodeTools::Processor::VERSION
  spec.authors       = ["Brian Shirai"]
  spec.email         = ["brixen@gmail.com"]
  spec.description   = %q{Converts Melbourne parse tree into an AST.}
  spec.summary       = %q{Converts Melbourne parse tree into an AST.}
  spec.homepage      = "https://github.com/rubinius/rubinius-processor"
  spec.license       = "BSD"

  spec.files         = `git ls-files`.split($/)
  spec.executables   = spec.files.grep(%r{^bin/}) { |f| File.basename(f) }
  spec.test_files    = spec.files.grep(%r{^(test|spec|features)/})
  spec.require_paths = ["lib"]

  spec.add_development_dependency "bundler", "~> 1.3"
  spec.add_development_dependency "rake", "~> 10.0"
end
