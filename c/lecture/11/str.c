#include <stdio.h>
#include <string.h>

void main()
{
	char str[80];
	printf("enter any string: ");
	// scanf("%s", str); // can't affort blank character
	gets(str);

	printf(str); // or printf("%s\n", str);
}
