GCC = gcc
CLFAGS = -g -Wall -Wshadow

pa06: pa06.o answer06.o
	$(GCC) $(CFLAGS) pa06.o answer06.o -o pa06

answer06.o: answer06.c pa06.h
	$(GCC) $(CFLAGS) -c answer06.c

pa06.o: pa06.c pa06.h
	$(GCC) $(CFLAGS) -c pa06.c

test: test01 test02 test03 test04 test05 test06 test07 test08 test09 test10 test11 test12 test13 test14

test01: pa06
	./pa06 images/01-unnormalized-smile.ee264 output/test01  
	valgrind --leak-check=full --verbose --log-file=output/valgrindlog01 ./pa06 images/01-unnormalized-smile.ee264 output/test01

test02: pa06
	./pa06 images/02-unnormalized-cat-chess.ee264 output/test02
	valgrind --leak-check=full --verbose --log-file=output/valgrindlog02 ./pa06 images/02-unnormalized-cat-chess.ee264 output/test02

test03: pa06
	./pa06 images/03-unnormalized-hawkes-bay-NZ.ee264 output/test03
	valgrind --leak-check=full --verbose --log-file=output/valgrindlog03 ./pa06 images/03-unnormalized-hawkes-bay-NZ.ee264 output/test03

test04: pa06
	./pa06 images/04-unnormalized-nelsonmandela.ee264 output/test04
	valgrind --leak-check=full --verbose --log-file=output/valgrindlog04 ./pa06 images/04-unnormalized-nelsonmandela.ee264 output/test04

test05: pa06
	./pa06 images/05-unnormalized-sagan-stamp.ee264 output/test05
	valgrind --leak-check=full --verbose --log-file=output/valgrindlog05 ./pa06 images/05-unnormalized-sagan-stamp.ee264 output/test05

test06: pa06
	! ./pa06 images/corrupt-testcases/bad-comment-len.ee264 output/test06
	! valgrind --leak-check=full --verbose --log-file=output/valgrindlog06 ./pa06 images/corrupt-testcases/bad-comment-len.ee264 output/test06

test07: pa06
	! ./pa06 images/corrupt-testcases/check-width-height.ee264 output/test07
	! valgrind --leak-check=full --verbose --log-file=output/valgrindlog07 ./pa06 images/corrupt-testcases/check-width-height.ee264 output/test07

test08: pa06
	! ./pa06 images/corrupt-testcases/check-magic-bits.ee264 output/test08
	! valgrind --leak-check=full --verbose --log-file=output/valgrindlog08 ./pa06 images/corrupt-testcases/check-mag-bits.ee264 output/test08

test09: pa06
	! ./pa06 images/corrupt-testcases/comment-has-no-null-byte.ee264 output/test09
	! valgrind --leak-check=full --verbose --log-file=output/valgrindlog09 ./pa06 images/corrupt-testcases/comment-has-no-null-byte.ee264 output/test09

test10: pa06
	! ./pa06 images/corrupt-testcases/height0.ee264 output/test10
	! valgrind --leak-check=full --verbose --log-file=output/valgrindlog10 ./pa06 images/corrupt-testcases/height0.ee264 output/test10

test11: pa06
	! ./pa06 images/corrupt-testcases/height-wrong.ee264 output/test11
	! valgrind --leak-check=full --verbose --log-file=output/valgrindlog11 ./pa06 images/corrupt-testcases/height-wrong.ee264 output/test11

test12: pa06
	! ./pa06 images/corrupt-testcases/incomplete-header.ee264 output/test12
	! valgrind --leak-check=full --verbose --log-file=output/valgrindlog12 ./pa06 images/corrupt-testcases/incomplete-header.ee264 output/test12

test13: pa06
	! ./pa06 images/corrupt-testcases/incomplete-image.ee264 output/test13
	! valgrind --leak-check=full --verbose --log-file=output/valgrindlog13 ./pa06 images/corrupt-testcases/incomplete-image.ee264 output/test13

test14: pa06
	! ./pa06 images/corrupt-testcases/width0.ee264 output/test14
	! valgrind --leak-check=full --verbose --log-file=output/valgrindlog14 ./pa06 images/corrupt-testcases/width0.ee264 output/test14