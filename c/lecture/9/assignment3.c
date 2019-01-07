#include <stdio.h>
#include <conio.h>

void main()
{
	int uc = 0, lc = 0, n = 0, e = 0;
	char c;

	while(1) {
		printf("enter a character: ");
		c = getche();
		printf("\n");

		if (c == 'q')
			break;

		if (c >= 'A' && c <= 'Z')
			uc++;
		else if (c >= 'a' && c <= 'z')
			lc++;
		else if (c >= '0' && c <= '9')
			n++;
		else
			e++;
	}

	printf("Upper case: %d, Lower case: %d, Number: %d and Etc.: %d\n", uc, lc, n, e);
}
