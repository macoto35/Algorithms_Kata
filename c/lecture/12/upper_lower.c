#include <stdio.h>
#include <ctype.h>

void main()
{
	char str[80];

	printf("please enter a string: ");
	gets(str);

	for(int i = 0;str[i]; i++)
		str[i] = toupper(str[i]);
	printf("%s\n", str);

	for(int i = 0; str[i]; i++)
		str[i] = tolower(str[i]);
	printf("%s\n", str);
}

