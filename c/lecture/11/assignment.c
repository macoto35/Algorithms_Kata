#include <stdio.h>
#include <string.h>

void main()
{
	char str[80];

	do {
		printf("please enter any string: ");
		gets(str);

		printf("%s\n", str);

	} while(strcmp(str, "stop"));
}
