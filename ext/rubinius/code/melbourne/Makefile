SHELL = /bin/sh

# V=0 quiet, V=1 verbose.  other values don't work.
V = 0
Q1 = $(V:1=)
Q = $(Q1:0=@)
ECHO1 = $(V:1=@:)
ECHO = $(ECHO1:0=@echo)

RM = rm -f
COPY = cp

CXX = c++
CXXFLAGS = -g -O2 -fPIC
INCFLAGS = -I. -I/Users/bshirai/.rubies/rbx-2.5.2/vm/include/capi -I/Users/bshirai/.rubies/rbx-2.5.2/library
OBJS = bstrlib.o grammar.o melbourne.o node_types.o quark.o symbols.o var_table.o visitor.o

LDSHAREDXX = clang++ -bundle -undefined suppress -flat_namespace
DLLIB = melbourne.bundle
DLDFLAGS =  
LIBPATH = -L. -L/Users/bshirai/.rubies/rbx-2.5.2/lib
LIBS =  

INSTALL_PATH = /source/rubinius/rubinius-melbourne/lib/rubinius/melbourne


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

