rm test.exe test.o c-cuid.o
gcc -c -g c-cuid.c -Wno-implicit-function-declaration -Wno-incompatible-pointer-types
gcc -c -g test.c
g++ -c -g test.c
gcc -o test test.o c-cuid.o -lws2_32
./test.exe
time test.exe