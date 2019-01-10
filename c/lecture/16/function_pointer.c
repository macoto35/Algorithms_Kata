#include <stdio.h>

void print(int* num);

void main()
{
	int num[10];

	for (int i = 0; i < 10; i++) {
		printf("please enter any number for num[%d]: ", i);
		scanf("%d", (num + i));
	}

	print(num);
}

/*
void print(int num[]) : initial pointer address to 10 elements
void print(int* num): initial pointer address to infinite memory location

num[5][5] === *num[5] === **num
*/
void print(int* num)
{
	printf("\n-------------------------------\n");

	for(int i = 0; i < 10; i++)
		printf("num[%d] = %d\n", i, num[i]);
}
