#include <stdio.h>

void main()
{
	int num1, num2, oper;

	printf("enter two integer numbers: ");
	scanf("%d %d", &num1, &num2);

	printf("select one of these options - 1: addition, 2: subtraction, 3: multiplication, 4: division\n");
	scanf("%d", &oper);

	if (oper == 1) {
		printf("%d + %d = %d\n", num1, num2, num1 + num2);
	} else if (oper == 2) {
		printf("%d - %d = %d\n", num1, num2, num1 - num2);
	} else if (oper == 3) {
		printf("%d * %d = %d\n", num1, num2, num1 * num2);
	} else if (oper == 4) {
		printf("%d / %d = %d\n", num1, num2, num1 / num2);
	} else {
		printf("error!");
	}
}
