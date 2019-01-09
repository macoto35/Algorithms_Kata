#include <stdio.h>

void main()
{
	printf("---> string pointer\n");
	char str[80];
	char* p;

	p = str;

	printf("enter any string!");
	gets(str);

	printf("%s\n", str);
	printf("%s\n", p);
	


	printf("\n---> use pointer as array\n");
	char* cp = "test string 123!";

	while(*cp) { // true if *cp != '\0'
		printf("%c", *cp++);
	}
}
