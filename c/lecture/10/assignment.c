#include <stdio.h>

void main()
{
	int i, sum = 0, tried[10];

	for (i = 0; i < 10; i++) {
		printf("please enter the score of %d exam: ", i + 1);
		scanf("%d", &tried[i]);
	}
	
	printf("\n");
	for (i = 0; i < 10; i++) {
		printf("%d exam score: %d\n", i + 1, tried[i]);
		sum += tried[i];
	}

	printf("sum: %d\n", sum);
	printf("average: %f\n", (float) sum / 10);
}
