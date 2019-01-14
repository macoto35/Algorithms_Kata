#include <stdio.h>
#include <stdlib.h>

void main()
{
	printf("sizeof int: %d, sizeof char: %d, sizeof double: %d\n", sizeof(int), sizeof(char), sizeof(double));

	int* arr;
	int size;

	printf("enter array size: ");
	scanf("%d", &size);

	arr = (int*) malloc(sizeof(int) * size);
	printf("%d size of array has been created!\n", size);

	free(arr);
	printf("after free, array has been deleted from the memory!\n");
}
