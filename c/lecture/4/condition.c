#include <stdio.h>

void main()
{
	int num;

	printf("enter int number: ");
	scanf("%d", &num);

	if (num > 0) {
		if (num%2 == 0) {
			printf("%d is positive, even\n", num);
		} else {
			printf("%d is positive, odd\n", num);
		}
	} else if (num < 0) {
		if (num%2 == 0) {
			printf("%d is negative, even\n", num);
		} else {
			printf("%d is negative, odd\n", num);
		}
	} else {
		printf("%d is zero\n", num);
	}
}
