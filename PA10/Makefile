GCC = gcc
CFLAGS = -g -Wall -Wshadow

pa10: pa10.o answer10.o 
	$(GCC) $(CFLAGS) pa10.o answer10.o -o pa10

answer10.o: answer10.c pa10.h
	$(GCC) $(CFLAGS) -c answer10.c

pa10.o: pa10.c pa10.h
	$(GCC) $(CFLAGS) -c pa10.c


