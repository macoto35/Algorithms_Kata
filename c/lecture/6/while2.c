#include <stdio.h>
#include <conio.h>

void main()
{
	char c;

	printf("Please enter A or B!");
	c = getche();

	while(c != 'A' && c != 'B') {
		printf("\nWrong! Please enter A or B!");
		c = getche();
	}

	printf("\nWell done!");
}
