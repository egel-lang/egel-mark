# compiler and compile options
CC=g++ --std=c++0x
CFLAGS=-c -Wall -pedantic
LIBS= \
	  -lcmark \
	  $(shell pkg-config --libs --cflags icu-uc icu-io)
LDFLAGS=$(LIBS)

# source files and objects
SOURCES= \
	cmark.cpp

OBJECTS=$(SOURCES:.cpp=.o)

# dynamic object
SHARED=cmark.ego

# targets
all: CC=g++ --std=c++0x
all: $(SOURCES) $(SHARED)

O3: CC=g++ --std=c++0x -O3
O3: $(SOURCES) $(SHARED)

gprof: CC=g++ -std=c++0x -O3 -pg
gprof: $(SOURCES) $(SHARED)

debug: CC=g++ -std=c++0x -g
debug: $(SOURCES) $(SHARED)

$(SHARED): $(OBJECTS) 
	$(CC) -shared $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) -fPIC $(CFLAGS) $< -o $@

clean:
	-rm -f $(OBJECTS) $(SHARED) gmon.out massive.out out
