#include <stdio.h>

int add(int num1, int num2);
int sub(int num1, int num2);
int mul(int num1, int num2);
int div(int num1, int num2);

void main()
{
	int num1, num2, oper;

	printf("enter two integer numbers: ");
	scanf("%d %d", &num1, &num2);

	printf("select one of these options - 1: addition, 2: subtraction, 3: multiplication, 4: division\n");
	scanf("%d", &oper);

	switch (oper) {
		case 1:
			printf("%d + %d = %d\n", num1, num2, add(num1, num2));
			break;
		case 2:
			printf("%d - %d = %d\n", num1, num2, sub(num1, num2));
			break;
		case 3:
			printf("%d * %d = %d\n", num1, num2, mul(num1, num2));
			break;
		case 4:
			printf("%d / %d = %d\n", num1, num2, div(num1, num2));
			break;
		default:
			printf("error!");
	}
}

int add(int num1, int num2)
{
	return num1 + num2;
}

int sub(int num1, int num2)
{
	return num1 - num2;
}

int mul(int num1, int num2)
{
	return num1 * num2;
}

int div(int num1, int num2)
{
	return num2 == 0 ? 0 : num1 / num2;
}
