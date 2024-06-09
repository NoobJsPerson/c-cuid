#include <stdio.h>
#include "c-cuid.h"
#include "c-cuid.h"
// test duplicate includes
int main(){
	char a[CUID_LENGTH];
	char b[SLUG_LENGTH];
	for(int i = 0; i < 10; i++) {
		cuid(a);
		slug(b);
		if(isCuid(a) == 0) {
			printf("CUID failed\n");
			return 1;
		}
		if(isSlug(b) == 0) {
			printf("SLUG failed\n");
			return 1;
		}
	}
	printf("%s %s %d %d\n", a, b, isCuid(a), isSlug(b));
}
