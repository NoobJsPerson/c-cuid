﻿# c-cuid
A C Port of the collision-resistant id generator [cuid](https://github.com/paralleldrive/cuid).
# Features
This library provides all the four functions as the original cuid<br>
`char* cuid(char* buff)` writes a new null terminated cuid into given buffer (buffer size must be atleast `CUID_LENGTH` which is 26 bytes in order to fit the cuid)<br>
`char* slug(char* buff)` writes a new null terminated slug ranging from 7 to 10 characters long into given buffer (buffer size must be atleast `SLUG_LENGTH` which is 11 bytes in order to fit the slug)<br>
`_Bool isCuid(char* buff)` checks if given buffer is a valid cuid (returns 1 if yes, 0 if no)<br>
`_Bool isSlug(char* buff)` checks if given buffer is a valid slug (returns 1 if yes, 0 if no)
# Usage
You could use the library as follows
```c
#include <stdio.h>
#include "c-cuid.h"
int main(){
	char cuidTest[CUID_LENGTH];
	char slugTest[SLUG_LENGTH];
	cuid(cuidTest);
	slug(slugTest);
	printf("CUID: %s\nisCuid: %s\nSLUG: %d\nisSlug:%d\n", cuidTest, slugTest, isCuid(cuidTest), isSlug(slugTest));
	// output (for example):
	// CUID: clb411w4100003s4f6y437nbt
	// isCuid: 1
	// SLUG: 632434s4 
	// isSlug: 1
}
```
# Testing
You could run the `test.sh` or the `test.bat` to test if the library will work on your device
If there's an error in compilation or unintended behaviour make an issue, or a pull request if you know how to fix it
# Planned features
- Adjusting and Testing for macOS (i don't have a mac, so if you have one you could do that and do a pull request I will review it as soon as possible)
