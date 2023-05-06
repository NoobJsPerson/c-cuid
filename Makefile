test: test.o c-cuid.o cpp_test
		gcc -o test test.o c-cuid.o -lws2_32
		@echo C test passed
cpp_test: test.c c-cuid.h
		g++ -c -g test.c
		@echo C++ test passed
test.o: test.c c-cuid.h
		gcc -c -g test.c
c-cuid.o: c-cuid.c c-cuid.h
		gcc -c -g c-cuid.c