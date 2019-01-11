#include <stdio.h>

struct student {
	int middle;
	int final;
};

void main()
{
	struct student s[5];

	for (int i = 0; i < 5; i++) {
		printf("please enter %d student's middle exam score: ", i);
		scanf("%d", &s[i].middle);
		printf("please enter %d student's final exam score: ", i);
		scanf("%d", &s[i].final);
	}

	for (int i = 0; i < 5; i++)
		printf("sum of %d student's scores: %d\n", i, s[i].middle + s[i].final);
}
