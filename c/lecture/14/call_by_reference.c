#include <stdio.h>

/*
int a = b is setting a's VALUE to b's VALUE
int* a = &b is setting a's VALUE to the ADDRESS of b
int& a = b is setting a's ADDRESS to b's ADDRESS (a is a reference to b)
*/

void swap(int &x, int &y);

void main()
{
	// example 1
	int b = 10;
	int &a = b;

	printf("[value] a = %d, b = %d\n", a, b);
	printf("[address] a = %p, b = %p\n", &a, &b);

	// swap
	int x = 10, y = 20;
	printf("[before swap] x = %d, y = %d\n", x, y);
	swap(x, y);
	printf("[after swap] x = %d, y = %d\n", x, y);
}

void swap(int &x, int &y)
{
	int tmp;

	tmp = x;
	x = y;
	y = tmp;
	
	printf("[swap] x = %d, y = %d\n", x, y);
}
