#include <stdio.h>

int add(int a, int b);

void main()
{
	int num1, num2, r;

	printf("please enter two numbers: ");
	scanf("%d %d", &num1, &num2);

	r = add(num1, num2);
	printf("result is %d\n", r);
}

int add(int a, int b)
{
	int result;
	result = a + b;
	
	return result;
}
