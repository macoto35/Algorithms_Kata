#include <stdio.h>
#include <string.h>

void main()
{
	char original[30], result[30];
	int loc = 0;

	printf("please enter a string: ");
	gets(original);

	for(int i = 0; i < strlen(original); i++) {
		if (original[i] != ' ')
			result[loc++] = original[i];
	}

	result[loc] = '\0'; // insert NULL character at the end
	
	printf("original: %s\n", original);
	printf("result: %s\n", result);
}
