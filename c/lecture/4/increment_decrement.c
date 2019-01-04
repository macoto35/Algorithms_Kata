#include <stdio.h>

void main()
{
	int a = 5, b = a++;
	printf("a = %d, b = %d\n", a, b);
	
	int c = 5, d = ++c;
	printf("c = %d, d = %d\n", c, d);
}
