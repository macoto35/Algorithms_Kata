#include <stdio.h>

void func();

int num;

void main()
{
	num = 3;
	printf("num? %d\n", num);
	func();
	printf("num? %d\n", num);
}

void func()
{
	num = 33;
	printf("num? %d\n", num);
}
