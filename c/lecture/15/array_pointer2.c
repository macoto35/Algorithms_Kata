#include <stdio.h>

void main()
{
	int arr[5] = {5, 10, 15, 20, 25};
	int* p;

	p = arr;

	for (int i = 0; i < 5; i++) {
		printf("arr[%d] = %d\n", i, arr[i]);
		printf("*(arr + %d) = %d\n", i, *(arr+i));
		printf("p[%d] = %d\n", i, p[i]);
		printf("*(p + %d) = %d\n", i, *(p+i));
		printf("---------------------------\n");
	}
}
