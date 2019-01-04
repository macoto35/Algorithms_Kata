#include <stdio.h>

void main()
{
	int i = 0;
	while(i > 0) {
		printf("hello while!\n");
		i--;
	}

	// run do{} at least once
	do {
		printf("hello do-while!\n");
	} while (i > 0);
}
