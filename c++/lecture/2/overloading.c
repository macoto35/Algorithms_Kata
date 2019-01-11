#include <stdio.h>

void print(int num);
void print(float num);
void print(double num);

int main(void)
{
	int i = 4;
	float f = -1.2;
	double d = 3.14;

	print(i);
	print(f);
	print(d);
}

void print(int num)
{
	printf("[int] %d\n", num);
}

void print(float num)
{
	printf("[float] %f\n", num);
}

void print(double num)
{
	printf("[double] %lf\n", num);
}
