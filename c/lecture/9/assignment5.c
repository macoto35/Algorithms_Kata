#include <stdio.h>
#include <math.h>

double mysqrt(double value, int input, int point);

void main()
{
	double value = 0;
	int input, point;
	printf("enter input and point integer values: ");
	scanf("%d %d", &input, &point);

	if (input == 1) {
		printf("result: 1\n");
		return;
	}

	for (int i = 0; i <= point; i++)
		value = mysqrt(value, input, i);
	
	printf("reslut: %.3lf\n", value);
}

double mysqrt(double value, int input, int point)
{
	double inc = 1 / (point == 0 ? 1 : pow(10, point));

	while(1) {
		if (value * value <= input) {
			value += inc;
		 } else {
			value -= inc;
			break;
		 }
	}

	return value;
}
