#include <stdio.h>

/*
[data type]

type                   | format | memory(bytes) | range
-----------------------------------------------------------------
signed char            | %c     | 1             | -2^7 ~ 2^7-1
unsigned char          | %c     | 1             | 0 ~ 2^8 - 1

(signed) short int     | %hd    | 2             | -2^15 ~ 2^15-1
unsigned short int     | %hu    | 2             | 0 ~ 2^16 - 1

(signed) int           | %d     | 4             | -2^31 ~ 2^31-1
unsighed int           | %u     | 4             | 0 ~ 2^32 - 1

(signed) long int      | %ld    | 4             | -2^31 ~ 2^31-1
unsigned long int      | %lu    | 4             | 0 ~ 2^32 - 1

(signed) long long int | %lld   | 8             | -2^63 ~ 2^63-1
unsigned long long int | %llu   | 8             | 0 ~ 2^64 - 1

float                  | %f     | 4
double                 | %lf    | 8
long double            | %Lf    | 12

[naming rule]
- can use: alphabet, number and underline
- can NOT use: blank, special characters, reserved words (if, while, break, return)
- case sensitive
- number cannot be used at the start of file name
*/
void main()
{
	int i;
	char c;

	i = 100;
	c = 'a';
	i = 3;

	printf("%d, %c", i, c);
}
