#include <stdio.h>

void main()
{
	int n1, n2;
	float result;

	printf("please enter two numbers: ");
	scanf("%d %d", &n1, &n2);

	result = (float)n1 / (float)n2;

	printf("%d / %d = %f\n", n1, n2, result);
}
