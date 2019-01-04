#include <stdio.h>

void main()
{
	for (int i = 0; i < 5; i++)
		printf("A");
	printf("B~!\n");
	
	for (int i = 0; i < 5; i++) {
		printf("A");
	        printf("B~!");
	}
}
