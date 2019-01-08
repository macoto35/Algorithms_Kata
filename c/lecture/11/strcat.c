#include <stdio.h>
#include <string.h>

/*
concatenate str1 and str2
e.g. "strcat(str1, str2)" is equal to "str1 = str1 + str2"
*/
void main()
{
	char str1[80], str2[80];

	printf("please enter any two strings: ");
	gets(str1);
	gets(str2);

	printf("before strcat - str1: %s\n", str1);
	printf("before strcat - str2: %s\n", str2);

	strcat(str1, str2);

	printf("after strcat - str1: %s\n", str1);
	printf("after strcat - str2: %s\n", str2);
}
