#include <stdio.h>

void main()
{
	int i;
	int* p;

	p = &i;

	for (i = 1; i <= 20; i++)
		printf("%d %d\n", i, *p);
}
