#!/usr/bin/env rake
# require "bundler/gem_tasks"

namespace :compiler do
  task :spec do
    sh "bundle exec mspec -r spec/compiler/spec_helper spec/compiler"
  end
end

namespace :melbourne do
  def extension_dir
    Dir.chdir "ext/rubinius/code/melbourne" do
      yield
    end
  end

  def spec_ruby_version
    ".spec_ruby_version"
  end

  desc "Generate the parser"
  task :generate do
    extension_dir { sh "bison -o grammar.cpp grammar.y" }
  end

  namespace :spec do
    desc "Clean the parser extension"
    task :clean do
      extension_dir do
        unless File.exist? spec_ruby_version and
               File.read(spec_ruby_version) == RUBY_DESCRIPTION
          sh "make distclean" if File.exist? "Makefile"
          File.open(spec_ruby_version, "w") { |f| f.write RUBY_DESCRIPTION }
        end
      end
    end

    desc "Build the parser extension"
    task :build => :generate do
      extension_dir do
        ruby "-v extconf.rb"
        ruby "-e 'system %[make && make install]'"
      end
    end
  end

  desc "Run the specs"
  task :spec => %w[spec:clean spec:build] do
    ENV['RUBYLIB'] ||= "#{File.join(__dir__, 'lib')}:#{__dir__}"
    sh "mspec -r spec/melbourne/spec_helper spec/melbourne"
  end
end

namespace :toolset do
  task :spec do
    sh "bundle exec mspec -r spec/toolset/spec_helper spec/toolset"
  end
end

task :spec do
  sh "bundle exec rake compiler:spec"
  sh "bundle exec rake melbourne:spec"
  sh "bundle exec rake toolset:spec"
end

task :default => :spec
