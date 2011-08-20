#
#  Makefile.gnu
#
#   Created on: 2011/8/19
#       Author: なつき
#


#release
#CFLAGS=-O2 -march=i686 -pipe
#debug
CFLAGS=-march=i686 -pipe -Wall -g
CXXFLAGS=$(CFLAGS)
CC=g++

SOURCES=main.cpp
OBJECTS=${SOURCES:.cpp=.o}
BIN=mio

all: $(BIN)

$(OBJECTS): prec.h.gch

$(BIN): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

prec.h.gch: prec.h
	$(CC) $(CXXFLAGS) $< -o $@

.cpp.o:
	$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(BIN) prec.h.gch $(OBJECTS)
