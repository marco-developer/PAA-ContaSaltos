# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#  -03 gcc version
CFLAGS  = -g -Wall -O3

default: main

ldde.o: ldde.c
	$(CC) $(CFLAGS) -c ldde.c -o ldde.o

main: main.c ldde.o
	$(CC) $(CFLAGS) main.c ldde.o -o main

run: clean main
	./main

clean:
	rm -f main *.o core a.out *.*~ Makefile~

all: main