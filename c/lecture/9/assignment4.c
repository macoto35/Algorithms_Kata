#include <stdio.h>

int change(int value, int coin);

void main()
{
	int input;
	int coins[] = {500, 100, 50, 10};

	printf("enter value: ");
	scanf("%d", &input);

	if (input <= 3000) {
		for(int i = 0; i < 4; i++)
			input = change(input, coins[i]);
	} else {
		printf("input value is more than 3000!\n");
	}
}

int change(int value, int coin)
{
	printf("%d: %d, ", coin, value/coin);
	return value % coin;
}
