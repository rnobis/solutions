GCC = gcc
CLFAGS = -g -Wall -Wshadow

pa06: pa06.o answer06.o
	$(GCC) $(CFLAGS) pa06.o answer06.o -o pa06

answer06.o: answer06.c pa06.h
	$(GCC) $(CFLAGS) -c answer06.c

pa06.o: pa06.c pa06.h
	$(GCC) $(CFLAGS) -c pa06.c

test1: pa06
	./pa06 
	valgrind --leak-check=full --verbose --log-file=valgrindlog01 ./pa06 
