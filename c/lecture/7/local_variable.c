#include <stdio.h>

void func();

int main()
{
	int num = 3;
	printf("num? %d\n", num);
	func();
	printf("num? %d\n", num);

	return 0;
}

void func()
{
	int num = 33;
	printf("num? %d\n", num);
}
