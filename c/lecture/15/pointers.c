#include <stdio.h>

void main()
{
	int *p, *q;
	int num = 10;

	p = &num;
	q = p;

	printf("%d, %d\n", *p, *q);
}
