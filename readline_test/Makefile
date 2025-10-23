.PHONY: default
default: all

CC := gcc
FFLAGS := -O2
LFLAGS := -lreadline

read.o: read.c
	$(CC) -c read.c $(FFLAGS) -o read.o

all: read.o
	$(CC) read.o $(LFLAGS) -o read.x

run:
	./read.x

clean:
	rm -f *.o
	rm -f read.x
