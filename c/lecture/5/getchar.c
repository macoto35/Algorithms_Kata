#include <stdio.h>
#include <conio.h> // for getch(), getche()

void main()
{
	char c;
	
	/*printf("please enter a character: ");
	scanf("%c", &c);
	printf("[scanf] you typed %c\n", c);*/

	// need enter
	printf("\nplease enter a character: ");
	c = getchar();
	printf("[getchar()] you typed %c\n", c);
	
	// no need enter
	printf("\nplease enter a character: ");
	c = getche();
	printf("\n[getcha()] you typed %c\n", c);
	
	// no need enter && not display typing character
	printf("\nplease enter a character: ");
	c = getch();
	printf("\n[getch()] you typed %c\n", c);
}
