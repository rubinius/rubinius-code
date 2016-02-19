require 'rbconfig' unless defined?(RbConfig)

require File.expand_path("../../../../../lib/rubinius/code/melbourne/version", __FILE__)

path = File.expand_path "../namespace.h", __FILE__
File.open path, "wb" do |f|
  version = CodeTools::Melbourne::VERSION

  if ENV["MELBOURNE_SPEC_VERSION"]
    # Alter the version to not match any possible loaded version
    version << ".spec"
  end

  melbourne = "melbourne_#{version.gsub(/\./, "_")}"

  f.puts "#define MELBOURNE                 #{melbourne}"
  f.puts "#define MELBOURNE_FILE_TO_AST     #{melbourne}_file_to_ast"
  f.puts "#define MELBOURNE_STRING_TO_AST   #{melbourne}_string_to_ast"
end

unless File.exist? "Makefile" and
    File.mtime("Makefile") > File.mtime(__FILE__)
  cxx = ENV["CXX"] || RbConfig::CONFIG["CXX"] || "g++"
  cxxflags = "#{ENV["CXXFLAGS"] || ENV["CPPFLAGS"] ||
             RbConfig::CONFIG["CXXFLAGS"] || RbConfig::CONFIG["CPPFLAGS"]} -fPIC"

  incdirs = [
    RbConfig::CONFIG["arch_hdrdir"],
    RbConfig::CONFIG["rubyarchhdrdir"],
    RbConfig::CONFIG["topdir"],
    RbConfig::CONFIG["hdrdir"],
    RbConfig::CONFIG["rubyhdrdir"],
    RbConfig::CONFIG["srcdir"]
  ].compact.uniq

  archincdirs = []
  incdirs.each do |x|
    dir = "#{x}/#{RbConfig::CONFIG["arch"]}"
    archincdirs << dir if File.exist? dir
  end
  incdirs.concat archincdirs

  incflags = "-I. #{incdirs.map { |x| "-I#{x}" }.join(" ")}"
  objs = Dir["*.{c,cpp}"].map { |x| x.sub(/\.(c|cpp)$/, ".o") }.join(" ")

  ldsharedxx = ENV["LDSHAREDXX"] || RbConfig::CONFIG["LDSHAREDXX"]
  unless ldsharedxx
    # Courtesy of EventMachine. Thank you EventMachine and tmm1 !
    case RUBY_PLATFORM
    when /mswin32/, /mingw32/, /bccwin32/
      # TODO
      # check_heads(%w[windows.h winsock.h], true)
      # check_libs(%w[kernel32 rpcrt4 gdi32], true)

      # if GNU_CHAIN
      #   CONFIG['LDSHARED'] = "$(CXX) -shared -lstdc++"
      # else
      #   $defs.push "-EHs"
      #   $defs.push "-GR"
      # end

    when /solaris/
      cxxflags << " -DOS_SOLARIS8"

      # detect SUNWspro compiler
      if RbConfig::CONFIG['CC'] == 'cc' and `cc -flags 2>&1` =~ /Sun/
        # SUN CHAIN
        cxxflags << " -DCC_SUNWspro"
        cxxflags.gsub!(/-fPIC/, "")
        cxxflags << " -KPIC"
        ldsharedxx = "#{cxx} -G -KPIC -lCstd"
      else
        # GNU CHAIN
        # on Unix we need a g++ link, not gcc.
        ldsharedxx = "#{cxx} -shared"
      end

    when /openbsd/
      # OpenBSD branch contributed by Guillaume Sellier.

      # on Unix we need a g++ link, not gcc. On OpenBSD, linking against
      # libstdc++ have to be explicitly done for shared libs
      ldsharedxx = "#{cxx} -shared -lstdc++ -fPIC"

    when /darwin/
      # on Unix we need a g++ link, not gcc.
      # Ff line contributed by Daniel Harple.
      ldsharedxx = "#{cxx} #{RbConfig::CONFIG['LDSHARED'].split[1..-1].join(' ')}"

    when /aix/
      ldsharedxx = "#{cxx} -shared -Wl,-G -Wl,-brtl"

    else
      # on Unix we need a g++ link, not gcc.
      ldsharedxx = "#{cxx} -shared"
    end
  end

  dllib = "melbourne." + RbConfig::CONFIG["DLEXT"]
  dldflags = ENV["LDFLAGS"] || RbConfig::CONFIG["LDFLAGS"] || ""
  dldflags += " #{RbConfig::CONFIG["DLDFLAGS"]}"
  libpath = "-L. -L#{RbConfig::CONFIG["libdir"]}"
  libs = "#{RbConfig::CONFIG["LIBS"]} #{RbConfig::CONFIG["LIBRUBYARG_SHARED"]}"
  install_path = Dir.pwd.sub %r[/ext/rubinius/code/melbourne$], "/lib/rubinius/code/melbourne"

  File.open "Makefile", "wb" do |f|
    f.print <<-EOM
SHELL = /bin/sh

# V=0 quiet, V=1 verbose.  other values don't work.
V = 0
Q1 = $(V:1=)
Q = $(Q1:0=@)
ECHO1 = $(V:1=@:)
ECHO = $(ECHO1:0=@echo)

RM = rm -f
COPY = cp

CXX = #{cxx}
CXXFLAGS = #{cxxflags}
INCFLAGS = #{incflags}
OBJS = #{objs}

LDSHAREDXX = #{ldsharedxx}
DLLIB = #{dllib}
DLDFLAGS = #{dldflags}
LIBPATH = #{libpath}
LIBS = #{libs}

INSTALL_PATH = #{install_path}


.PHONY: all install

all:    $(DLLIB)

clean:
	-$(Q)$(RM) $(OBJS) $(DLLIB)

distclean:
	-$(Q)$(RM) $(OBJS) $(DLLIB) Makefile

install:
	-$(Q)$(COPY) $(DLLIB) $(INSTALL_PATH)


.SUFFIXES: .y .cpp .o

.cpp.o:
	$(ECHO) compiling $(<)
	$(Q) $(CXX) $(CXXFLAGS) $(INCFLAGS) -o $@ -c $<

$(DLLIB): $(OBJS) Makefile
	$(ECHO) linking shared-object $(DLLIB)
	-$(Q)$(RM) $(@)
	$(Q) $(LDSHAREDXX) -o $@ $(OBJS) $(LIBPATH) $(DLDFLAGS) $(LIBS)

    EOM
  end
end
