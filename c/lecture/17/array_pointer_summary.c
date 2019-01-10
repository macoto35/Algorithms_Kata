#include <stdio.h>

void main()
{
	printf("---> array\n");

	/*
	 char   | str[0] | str[1] | str[2] | str[3] | str[4] |
	------------------------------------------------------
	address |   1    |   2    |   3    |   4    |   5    | 
	value   |   ?    |   ?    |   ?    |   ?    |   ?    |
	*/
	char str[5];


	/*
	 char   | str[0] | str[1] | str[2] | str[3] | str[4] |
	------------------------------------------------------
	address |   1    |   2    |   3    |   4    |   5    | 
	value   |   b    |   a    |   b    |   o    |  \0    |
	*/
	strcpy(str, "babo\0");
	printf("%s, %d\n", str, strlen(str));
	
	
	
	printf("\n---> pointer\n");
	/*
	 int    | num    |        |        |   *p   |  **q   |
	------------------------------------------------------
	address |   54   |   55   |   56   |   57   |   58   | 
	value   |   5    |   ?    |   ?    |   54   |   57   |
	*/
	int num =  5;
	int* p = &num;
	int** q = &p;
	printf("[num] value: %d, address: %p\n", num, &num, p, &p);
	printf("[p] *p: %d, p: %p, &p: %p\n", *p, p, &p);
	printf("[q] q: %p, *q: %p, **q: %d, &q: %p\n", q, *q, **q, &q);



	printf("\n---> array and pointer\n");
	/*
	 char   |c / c[0]|  c[1]  |  c[2]  |  c[3]  |  c[4]  |
	------------------------------------------------------
	address |   1    |   2    |   3    |   4    |   5    | 
	value   |   b    |   a    |   b    |   o    |   \0   |

	 char   |   *r   |        |        |        |        |
	------------------------------------------------------
	address |  1196  |  1197  |  1198  |  1199  |  1200  | 
	value   |   1    |   ?    |   ?    |   ?    |   ?    |
	*/
	char c[5] = "babo\0";
	char* r = c;
	printf("[before arithmetic operation] c: %p, c[0]: %c\n", c, c[0]);
	printf("[before arithmetic operation] r: %p, *r: %c\n", r, *r);

	/*
	 char   |c / c[0]|  c[1]  |  c[2]  |  c[3]  |  c[4]  |
	------------------------------------------------------
	address |   1    |   2    |   3    |   4    |   5    | 
	value   |   b    |   a    |   b    |   o    |   \0   |

	 char   |   *r   |        |        |        |        |
	------------------------------------------------------
	address |  1196  |  1197  |  1198  |  1199  |  1200  | 
	value   |   2    |   ?    |   ?    |   ?    |   ?    |
	*/
	r++;
	printf("[after arithmetic operation] c: %p, c[1]: %c\n", c+1, c[1]);
	printf("[after arithmetic operation] r: %p, *r: %c\n", r, *r);



	printf("\n---> pointer array\n");
	/*
	 - equals to ch[3][?]
	 - flexible / save memory
	   e.g. ch[3][20]:  3 lines of 19 characters strings
	        *ch[3]: 3 lines of unlimited characters strings
	*/
	char *ch[3];

}
