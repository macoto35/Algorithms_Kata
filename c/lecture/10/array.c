#include <stdio.h>

void main()
{
	int initialization[3] = {12, 31, 45};
	printf("initialization[1] = %d\n", initialization[1]);
	
	int i;
	int carrier[12];

	for (i = 0; i < 12; i++) {
		printf("please enter a number for carrier[%d]:", i + 1);
		scanf("%d", &carrier[i]);
	}

	printf("\n");
	for(i = 0; i < 12; i++)
		printf("carrier[%d] = %d\n", i + 1, carrier[i]);
}
