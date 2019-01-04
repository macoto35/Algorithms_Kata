#include <stdio.h>

void main()
{
	int i1, i2, isum;
	double f1, f2, fsum;

	printf("enter first int value: ");
	scanf("%d", &i1);
	printf("enter second int value: ");
	scanf("%d", &i2);

	isum = i1 + i2;
	printf("sum of two int values is %d\n", isum);


	printf("enter first float value: ");
	scanf("%lf", &f1);
	printf("enter second float value: ");
	scanf("%lf", &f2);

	fsum = f1 + f2;
	printf("sum of two float values is %lf\n", fsum);
}
