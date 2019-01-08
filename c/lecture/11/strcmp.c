#include <stdio.h>
#include <string.h>

/*
compare str1 and str2

str1 == str2 -> return 0
str1 != str2 and str1 > str2 -> return positive
str1 != str2 and str1 < str2 -> return negative
*/
void main()
{
	char str1[80], str2[80];

	printf("please enter any two strings: ");
	gets(str1);
	gets(str2);

	int same = strcmp(str1, str2);

	if (!same)
		printf("2 strings are same!\n");
	else if (same > 0)
		printf("first string is larger than second string!\n");
	else
		printf("second string is larger than first string!\n");
}
