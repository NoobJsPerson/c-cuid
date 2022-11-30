# c-cuid
A C Port of the collision-resistant id generator [cuid](https://github.com/paralleldrive/cuid).
# Usage
You could use the library as follows
```c
#include <stdio.h>
#include "c-cuid.h"
int main(){
	char test[CUID_LENGTH];
	cuid(test);
	printf("%s\n",test);
}
```
# Testing
You could run the `test.sh` or the `test.bat` to test if the library will work on your device
If there's an error in compilation or unintended behaviour make an issue or a pull request if you know how to fix it
# Planned features
- Adding slug function
- Adding isCuid and isSlug functions
- Adjusting and Testing for macOS (i don't have a mac, so if you have one you could do that and do a pull request I will review it as soon as possible)
