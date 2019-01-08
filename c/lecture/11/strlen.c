#include <stdio.h>
#include <string.h>

/*
get length of string
*/
void main()
{
	char str[80];

	printf("please enter any string: ");
	gets(str);

	printf(str);
	printf("\nlength: %d\n", strlen(str));
}
