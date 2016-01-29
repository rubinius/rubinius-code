# -*- encoding: utf-8 -*-
require './lib/rubinius/code/melbourne/version'

Gem::Specification.new do |spec|
  spec.authors       = ["Brian Shirai"]
  spec.email         = ["brixen@gmail.com"]
  spec.description   = %q{Ruby parser extracted from MRI.}
  spec.summary       = %q{Rubinius Ruby Parser.}
  spec.homepage      = "https://github.com/rubinius/rubinius-code"
  spec.license       = "MPL-2.0"

  spec.files         = `git ls-files lib/rubinius/code/melbourne* ext/rubinius/code/melbourne*`.split($\)
  spec.extensions    = ["ext/rubinius/code/melbourne/extconf.rb"]
  spec.test_files    = spec.files.grep(%r{^(test|spec|features)/})
  spec.name          = "rubinius-melbourne"
  spec.require_paths = ["lib"]
  spec.version       = CodeTools::Melbourne::VERSION

  spec.add_development_dependency "redcard", "~> 1.0"
  spec.add_development_dependency "mspec", "~> 1.5"
  spec.add_development_dependency "rake",  "~> 10.0"
end
