#include <stdio.h>
#include "c-cuid.h"
int main(){
	char a[CUID_LENGTH];
	char b[SLUG_LENGTH];
	cuid(a);
	slug(b);
	printf("%s %s %d %d\n", a, b, isCuid(a), isSlug(b));
}
