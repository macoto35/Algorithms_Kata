#include <stdio.h>

void main()
{
	int num = 10;
	int* p;

	p = &num;

	printf("%d\n", num);
	printf("%d\n", *p);
	
	printf("%p\n", &num);
	printf("%p\n", p);
}
