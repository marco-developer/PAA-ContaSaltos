# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#  -03 gcc version
CFLAGS  = -g -Wall -O3

default: hops

ldde.o: ldde.c
	$(CC) $(CFLAGS) -c ldde.c -o ldde.o

hops: hops.c ldde.o
	$(CC) $(CFLAGS) hops.c ldde.o -o hops

run: clean hops
	./hops

clean:
	rm -f hops *.o core a.out *.*~ Makefile~

all: hops