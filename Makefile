.PHONY: default
default: all

CC := g++
#FFLAGS := -O3
FFLAGS := -O0 -g -DDEBUG_OUT
LFLAGS := -lreadline

main.o: main.cpp types.h main.h
	$(CC) -c main.cpp $(FFLAGS) -o main.o

reader.o: reader.cpp reader.h types.h
	$(CC) -c reader.cpp $(FFLAGS) -o reader.o

printer.o: printer.cpp printer.h types.h
	$(CC) -c printer.cpp $(CFLAGS) -o printer.o

all: main.o reader.o printer.o
	$(CC) main.o reader.o printer.o $(LFLAGS) -o jamal

run:
	./jamal

clean:
	rm -f *.o
	rm -f main.x
