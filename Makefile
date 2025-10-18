.PHONY: default
default: all

CC := g++
FFLAGS := -O2

step0_repl.o: step0_repl.cpp
	$(CC) -c step0_repl.cpp $(FFLAGS) -o step0_repl.o

all: step0_repl.o
	$(CC) step0_repl.o $(FFLAGS) -o main.x

run:
	./main.x

clean:
	rm -f *.o
	rm -f main.x
