#include <stdio.h>
#include <conio.h>

void main()
{
	char key;

	printf("Let me introduce myself!\n");
	printf("You will see my name on the screen if you enter n\n");
	printf("You will see my birthday on the screen if you enter a\n");
	printf("You will see my school on the screen if you enter u\n");

	key = getch();

	switch(key) {
		case 'n':
			printf("macoto35!\n");
			break; // without this, program will print all 'printf' until the end
		case 'a':
			printf("1900-01-01!\n");
			break;
		case 'u':
			printf("school!\n");
			break;
		default:
			printf("error!\n");
	}
}
