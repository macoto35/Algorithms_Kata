#include <stdio.h>

/*
the prefix ++ operator has the same precedence as *, and they associate right-to-left.
++*ptr == ++(*ptr)

the postfix ++ operator has higher precedence than the dereferrence operator *.
*ptr++ == *(ptr++)
*/
void main()
{
	printf("---> pointer arithmetic - array\n");
	int array[3] = {3, 6, 9};
	int* p = array;

	printf("array[0] = %d, *p = %d\n", array[0], *p);
	printf("array[1] = %d, *++p = %d\n", array[1], *++p);
	printf("array[2] = %d, *++p = %d\n", array[2], *++p);
	
	
	
	printf("\n---> pointer arithmetic - address\n");
	int i;
	int* p1;

	p1 = &i;
	i = 1;

	printf("[before arithmetic] address: %p, value: %d\n", p1, *p1);
	*p1++; // or p++;
	printf("[after arithmetic] address: %p, value: %d\n", p1, *p1);
	
	
	
	printf("\n---> pointer arithmetic - value\n");
	int j;
	int* p2;

	p2 = &j;
	j = 2;

	printf("[before arithmetic] address: %p, value: %d\n", p2, *p2);
	++*p2;
	printf("[after arithmetic1] address: %p, value: %d\n", p2, *p2);
	(*p2)++;
	printf("[after arithmetic2] address: %p, value: %d\n", p2, *p2);

}
