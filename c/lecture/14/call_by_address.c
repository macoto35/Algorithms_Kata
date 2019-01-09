#include <stdio.h>

void swap(int* x, int* y);

void main()
{
	int x = 3, y = 6;

	printf("[before swap] x = %d, y = %d\n", x, y);
	swap(&x, &y);
	printf("[after swap] x = %d, y = %d\n", x, y);
}

void swap(int* x, int* y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;

	printf("[swap] x = %d, y = %d\n", *x, *y);
}
