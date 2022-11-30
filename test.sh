gcc -c -g c-cuid.c -Wimplicit-function-declaration -Wno-incompatible-pointer-types
gcc -c -g test.c 
gcc -o test test.o c-cuid.o -lws2_32
./test.exe