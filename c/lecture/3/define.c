#include <stdio.h>

#define PI 3.141592

void main()
{
	double radius;
	double circumference, width;

	printf("enter the radius: ");
	scanf("%lf", &radius);

	circumference = 2 * PI* radius;
	width = PI * radius * radius;

	printf("circumference? %lf\n", circumference);
	printf("width? %lf\n", width);
}
