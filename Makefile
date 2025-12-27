.PHONY: default
default: all

CC := g++
FFLAGS := -O2
LFLAGS := 

step0_repl.o: step0_repl.cpp
	$(CC) -c step0_repl.cpp $(FFLAGS) -o step0_repl.o

step1_read_print.o: step1_read_print.cpp
	$(CC) -c step1_read_print.cpp $(FFLAGS) -o step1_read_print.o

reader.o: reader.cpp
	$(CC) -c reader.cpp $(FFLAGS) -o reader.o

all: step1_read_print.o reader.o
	$(CC) step1_repl.o reader.o $(LFLAGS) -o main.x

run:
	./main.x

clean:
	rm -f *.o
	rm -f main.x
