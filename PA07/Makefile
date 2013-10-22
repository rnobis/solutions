GCC = gcc
CLFAGS = -g -Wall -Wshadow

pa07: pa07.o answer07.o
	$(GCC) $(CFLAGS) pa07.o answer07.o -o pa07

answer07.o: answer07.c pa07.h
	$(GCC) $(CFLAGS) -c answer07.c

pa07.o: pa07.c pa07.h
	$(GCC) $(CFLAGS) -c pa07.c

test: test01 test02 test03 test04 test05 test06 test07 test08 test09 test10 test11

test01: pa07
	./pa07 inputs/input0_A inputs/input0_B >  outputs/test01
	diff outputs/test01 expected/expected0
	valgrind --leak-check=full --verbose --log-file=outputs/valgrindlog01 ./pa07 inputs/input0_A inputs/input0_B

test02: pa07
	./pa07 inputs/input1_A inputs/input1_B > outputs/test02
	diff outputs/test02 expected/expected1
	valgrind --leak-check=full --verbose --log-file=outputs/valgrindlog02 ./pa07 inputs/input1_A inputs/input1_B 

test03: pa07
	./pa07 inputs/input2_A inputs/input2_B > outputs/test03
	diff outputs/test03 expected/expected2
	valgrind --leak-check=full --verbose --log-file=outputs/valgrindlog03 ./pa07 inputs/input2_A inputs/input2_B 

test04: pa07
	./pa07 inputs/input3_A inputs/input3_B > outputs/test04
	diff outputs/test04 expected/expected3
	valgrind --leak-check=full --verbose --log-file=outputs/valgrindlog04 ./pa07 inputs/input3_A inputs/input3_B  

test05: pa07
	./pa07 inputs/input4_A inputs/input4_B > outputs/test05
	diff outputs/test05 expected/expected4
	valgrind --leak-check=full --verbose --log-file=outputs/valgrindlog05 ./pa07 inputs/input4_A inputs/input4_B 

test06: pa07
	./pa07 inputs/input5_A inputs/input5_B > outputs/test06
	diff outputs/test06 expected/expected5
	valgrind --leak-check=full --verbose --log-file=outputs/valgrindlog06 ./pa07 inputs/input5_A inputs/input5_B 

test07: pa07
	./pa07 inputs/input6_A inputs/input6_B > outputs/test07
	diff outputs/test07 expected/expected6
	valgrind --leak-check=full --verbose --log-file=outputs/valgrindlog07 ./pa07 inputs/input6_A inputs/input6_B 

test08: pa07
	./pa07 inputs/input7_A inputs/input7_B > outputs/test08
	diff outputs/test08 expected/expected7
	valgrind --leak-check=full --verbose --log-file=outputs/valgrindlog08 ./pa07 inputs/input7_A inputs/input7_B 

test09: pa07
	./pa07 inputs/input8_A inputs/input8_B > outputs/test09
	diff outputs/test09 expected/expected8
	valgrind --leak-check=full --verbose --log-file=outputs/valgrindlog09 ./pa07 inputs/input8_A inputs/input8_B

test10: pa07
	./pa07 inputs/input9_A inputs/input9_B > outputs/test10
	diff outputs/test10 expected/expected9
	valgrind --leak-check=full --verbose --log-file=outputs/valgrindlog10 ./pa07 inputs/input9_A inputs/input9_B 

test11: pa07
	./pa07 inputs/input10_A inputs/input10_B > outputs/test11
	diff outputs/test11 expected/expected10
	valgrind --leak-check=full --verbose --log-file=outputs/valgrindlog11 ./pa07 inputs/input10_A inputs/input10_B
