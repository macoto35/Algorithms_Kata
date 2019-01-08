#include <stdio.h>

void main()
{
	int max = -1, num[10];

	for (int i = 0; i < 10; i++) {
		printf("please enter a number for num[%d]: ", i);
		scanf("%d", &num[i]);

		if (num[i] > max)
		       max = num[i];
	}

	printf("max: %d\n", max);
}
