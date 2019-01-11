#include <stdio.h>

/*
cretae nickname
*/
typedef struct {
	int i;
	char c;
	float f;
} ABC;

int main(void)
{
	ABC abc;
	abc.i = 5;
	abc.c = 'A';
	abc.f = 1.1;
	printf("abc.i = %d, abc.c = %c, abc.f = %f\n", abc.i, abc.c, abc.f);

	typedef int my_int;
	typedef char my_char;
	my_int mi = 10;
	my_char mc = 'K';
	printf("mi = %d, mc = %c\n", mi, mc);

	return 0;
}
