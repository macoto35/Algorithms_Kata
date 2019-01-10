#include <stdio.h>

/*
Or void print(int num[])
Or void print(int num[][5])
Or void print(int num[4][5])
*/
void print(int num[10]);

void main()
{
	int bags[10];

	for(int i = 0; i < 10; i++) {
		printf("please enter any number for %d: ", i + 1);
		scanf("%d", &bags[i]);
	}

	printf("\n");
	print(bags);
}

void print(int num[10])
{
	printf("-----------------------\n");

	for(int i = 0; i < 10; i++)
		printf("bags[%d] = %d\n", i, num[i]);
}
