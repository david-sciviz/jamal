.PHONY: default
default: all

CC := g++
#FFLAGS := -O3
FFLAGS := -O0 -g -DDEBUG_OUT
LFLAGS := 

step0_repl.o: step0_repl.cpp
	$(CC) -c step0_repl.cpp $(FFLAGS) -o step0_repl.o

step1_read_print.o: step1_read_print.cpp types.h main.h
	$(CC) -c step1_read_print.cpp $(FFLAGS) -o step1_read_print.o

reader.o: reader.cpp reader.h types.h
	$(CC) -c reader.cpp $(FFLAGS) -o reader.o

printer.o: printer.cpp printer.h types.h

all: step1_read_print.o reader.o printer.o
	$(CC) step1_read_print.o reader.o printer.o $(LFLAGS) -o main.x

run:
	./main.x

clean:
	rm -f *.o
	rm -f main.x
