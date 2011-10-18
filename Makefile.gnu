#
#  Makefile.gnu
#
#   Created on: 2011/8/19
#       Author: なつき
#


#release
#CFLAGS=-O2 -march=i686 -pipe
#debug
CFLAGS=-march=i686 -pipe -Wall -g -std=gnu++0x -pthread
CXXFLAGS=$(CFLAGS)
CC=g++

SOURCES=main.cpp Problem.cpp Answer.cpp AlgorithmBase.cpp AlgorithmFillOne.cpp
OBJECTS=$(SOURCES:.cpp=.o)
DEPENDS=$(SOURCES:.cpp=.d)
BIN=mio
GEN=gen

.PHONY: clean depend
.SUFFIXES: .o .d

all: $(BIN) $(GEN)

$(OBJECTS): prec.h.gch

$(BIN): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

prec.h.gch: prec.h
	$(CC) $(CXXFLAGS) $< -o $@

.cpp.o:
	$(CC) $(CXXFLAGS) -c $< -o $@


.cpp.d:
	@set -e; $(CC) -MM $(CXXFLAGS) $< \
		| sed 's/\($*\)\.o[ :]*/\1.o $@ : /g' > $@; \
		[ -s $@ ] || rm -f $@

-include $(DEPENDS)

$(GEN): gen.cpp
	$(CC) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(BIN) prec.h.gch $(OBJECTS) $(DEPENDS) $(GEN)
	rm -rf html latex

doc:
	doxygen Doxyfile

depend: $(DEPENDS)

