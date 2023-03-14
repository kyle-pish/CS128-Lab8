CXX = clang++
override CXXFLAGS += -g -Wno-everything

all: main

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.cpp' -print)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

-include Makefile.deps

Makefile.deps: $(SRCS)
	$(CC) $(CFLAGS) -MM $(SRCS) > Makefile.deps

main: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o main

clean:
	rm -f $(OBJS) main
