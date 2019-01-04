#include <stdio.h>

void main()
{
	int tmp;
	for (int i = 1; i <= 29; i++) {
		tmp = i % 10;
		if (tmp == 3 || tmp == 6 || tmp == 9) {
			printf("Clap!\n");
		} else {
			printf("%d\n", i);
		}
	}
}
