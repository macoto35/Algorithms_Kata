#include <stdio.h>

/*
- Avoid to use break/continue in the program
- It breaks flow of program
*/
void main()
{
	printf("break\n");
	for(int i = 1; i <= 10; i++) {
		if (i == 5)
			break;
		printf("%d\t", i);
	}

	printf("\ncontinue\n");
	for(int i = 1; i <= 10; i++) {
		if (i == 5)
			continue;
		printf("%d\t", i);
	}
}
