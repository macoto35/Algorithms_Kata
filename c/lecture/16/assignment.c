#include <stdio.h>

void my_strcpy(char* s1, char* s2);

void main()
{
	char s1[80], s2[80];

	printf("please enter first string: ");
	gets(s1);

	printf("please enter second string: ");
	gets(s2);

	printf("[before my_strcpy] s1 = %s\n", s1);
	printf("[before my_strcpy] s2 = %s\n", s2);

	my_strcpy(s1, s2);
	
	printf("[after my_strcpy] s1 = %s\n", s1);
	printf("[after my_strcpy] s2 = %s\n", s2);

}

/*
Operator precedence and order of execution is not necessarily the same thing.

*s1++ = *s2++

Is evaluated by the compiler as follows:

1. Compiler sees "++" which has the highest precedence. As it is the post-increment operator, it simply makes note of the fact that the pointer needs to be incremented after the evaluation of the expression is done.
2. Compiler sees "*" operator, telling it that it should dereference s2, and use that as the RHS
3. Same on the left side of the assignment, the char at s1 is set to the char's value at s2
4. Compiler gets back to it's note that pointers need to be incremented after expression evaluation and does so.

Even if ++ is of higher precedence as *, it is still done last. Precedence here just means the post-increment operation has to be done to the pointer, and not to the value at the pointer
*/
void my_strcpy(char* s1, char* s2)
{
	while(*s2)
		*s1++ = *s2++;
	*s1 = '\0';
}
