#include <stdio.h>
#include <string.h>

/*
copy string
e.g. "strcpy(str1, str2)" is equal to "str1 = str2"
*/
void main()
{
	char str1[80], str2[80];

	printf("please enter any two strings: ");
	gets(str1);
	gets(str2);

	printf("before strcpy - str1: %s\n", str1);
	printf("before strcpy - str2: %s\n", str2);

	strcpy(str1, str2);

	printf("after strcpy - str1: %s\n", str1);
	printf("after strcpy - str2: %s\n", str2);
}
