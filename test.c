#include <stdio.h>
#include "c-cuid.h"
#include "c-cuid.h"
// test duplicate includes
int main(){
	char a[CUID_LENGTH];
	char b[SLUG_LENGTH];
	cuid(a);
	slug(b);
	printf("%s %s %d %d\n", a, b, isCuid(a), isSlug(b));
}
