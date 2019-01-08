#include <stdio.h>

/*
 - string has NULL character at the end: end of string flag
 - so length should be (string_length + 1)
*/
void main()
{
	char str[13] = "abcde fghijk"; // size is 13 because of NULL at the end not 12
	printf("%s\n", str);
}
