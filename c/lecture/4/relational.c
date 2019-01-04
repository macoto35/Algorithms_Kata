#include <stdio.h>

void main()
{
	int num1, num2;
	
	printf("enter two numbers: ");
	scanf("%d %d", &num1, &num2);

	if (num1 > num2) {
		printf("%d is larger than %d\n", num1, num2);
	} else if (num1 < num2) {
		printf("%d is smaller than %d\n", num1, num2);
	} else if (num1 == num2) {
		printf("%d and %d are equal\n", num1, num2);
	}
}
