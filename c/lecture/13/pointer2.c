#include <stdio.h>

int main(void)
{
	int* p;
	int num;

	p = &num;
	*p = 10;

	printf("%d\n", num);
	printf("%d\n", *p);
	
	printf("%p\n", &num);
	printf("%p\n", p);

	return 0;
}
