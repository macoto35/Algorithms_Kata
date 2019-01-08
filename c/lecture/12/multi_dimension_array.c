#include <stdio.h>
#include <string.h>

/*
box[2] 
-> box[0], box[1]

box[3][2]
-> box[0][0] box[0][1]
   box[1][0] box[1][1]
   box[2][0] box[2][1]

box[2][3][2]
-> box[0][0][0] box[0][0][1]
   box[0][1][0] box[0][1][1]
   box[0][2][0] box[0][2][1]
   
   box[1][0][0] box[1][0][1]
   box[1][1][0] box[1][1][1]
   box[1][2][0] box[1][2][1]
*/
void main()
{
	// multi-dimension array
	printf("multi-dimension array: \n");
	int num[2][4];

	for(int i = 0; i < 2; i++)
		for (int j = 0; j < 4; j++)
			num[i][j] = i * j;

	for(int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++)
			printf("%3d", num[i][j]);
		printf("\n");
	}

	// initialization
	printf("initialization type1: \n");
	int sqr1[3][3] = {
		3,4,5,
		5,2,5,
		7,8,2
	};
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++)
			printf("%2d", sqr1[i][j]);
		printf("\n");
	}
	
	printf("initialization type2: \n");
	int sqr2[3][3] = {{11, 12, 13}, {21, 22, 23}, {31, 32, 33}};
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++)
			printf("%3d", sqr2[i][j]);
		printf("\n");
	}

	// un-sized array
	printf("un-sized array:\n");
	int number[] = {3, 1, 4, 2, 5, 2, 3, 4};
	char str[] = "test test";

	printf("number array size? %d\n", sizeof(number)/sizeof(number[0]));
	printf("str size? %d\n", strlen(str));
}
