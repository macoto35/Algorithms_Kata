#include <stdio.h>
#include <stdlib.h>

void main()
{
	char str[80];
	int i;
	double d;

	printf("please enter interger type string: ");
	gets(str);
	i = atoi(str);
	printf("converted from string to integer: %d\n", i);

	printf("please enter float type string: ");
	gets(str);
	d = atof(str);
	printf("converted froms stirng to double: %lf\n", d);
}
