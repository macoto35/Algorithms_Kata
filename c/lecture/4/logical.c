#include <stdio.h>

/*
A     | B     | A && B | A || B | !A
true  | true  | true   | true   | false
true  | false | false  | true   | false
false | true  | false  | true   | true
false | false | false  | false  | true

*/
void main()
{
	int num;

	printf("enter a number: ");
	scanf("%d", &num);

	if (num >= 0 && num <= 10) {
		printf("%d is between 0 and 10!\n", num);
	} else if (num < 0 || num > 100) {
		printf("%d is less than 0 OR greater than 100!\n", num);
	} else {
		printf("%d is greater than 10 AND less than 100!\n", num);
	}
}
