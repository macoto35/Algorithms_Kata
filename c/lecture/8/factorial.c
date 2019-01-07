#include <stdio.h>

int factorial(int num);

void main()
{
	int num, facto;

	printf("enter a number: ");
	scanf("%d", &num);

	facto = factorial(num);

	printf("%d! = %d\n", num, facto);
}

int factorial(int num)
{
	if (num == 1 || num == 0)
		return 1;
	return num * factorial(num - 1);
}
