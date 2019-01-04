#include <stdio.h>

/*

\n: newline 
\t: tab
\b: backward
\a: beep
*/
void main()
{
	int i = 369;
	double d = 369.369;

	printf("\ttab\n");
	printf("backward\b\n");
	printf("beep\a\n");

	printf("i = %d\n", i);
	printf("i = %5d\n", i);
	printf("i = %05d\n\n", i);

	printf("d = %lf\n", d);
	printf("d = %.2lf\n", d);
}
