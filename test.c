#include <stdio.h>
#include "c-cuid.h"
int main(){
	char a[CUID_LENGTH];
	cuid(a);
	printf("%s\n", a);
}
