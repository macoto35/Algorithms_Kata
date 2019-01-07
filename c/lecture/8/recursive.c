#include <stdio.h>

void banbok(int num);

void main()
{
	banbok(0);
}

void banbok(int num)
{
	if (num < 10) {
		banbok(num + 1);
		printf("num = %d\n", num);
	}
}
