#include <stdio.h>

void main()
{
	int x, y, result;

	printf("enter x and y: ");
	scanf("%d %d", &x, &y);

	if (x == 0 && y == 0) {
		printf("N/A\n");
	        return;
	}
	
	if (x > 0)
		result = y > 0 ? 1 : 4;
	else
		result = y > 0 ? 2 : 3;
	printf("%d\n", result);
}
