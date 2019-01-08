#include <stdio.h>


/*
num[0][0][0] num[0][0][1] num[0][0][2]       1  2  3
num[0][1][0] num[0][1][1] num[0][1][2]       4  5  6
num[0][2][0] num[0][2][1] num[0][2][2]       7  8  9

num[1][0][0] num[1][0][1] num[1][0][2]       10 11 12
num[1][1][0] num[1][1][1] num[1][1][2]   =   13 14 15
num[1][2][0] num[1][2][1] num[1][2][2]       16 17 18

num[2][0][0] num[2][0][1] num[2][0][2]       19 20 21
num[2][1][0] num[2][1][1] num[2][1][2]       22 23 24
num[2][2][0] num[2][2][1] num[2][2][2]       25 26 27
*/
void main()
{
	int num[3][3][3], seq = 1;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				num[i][j][k] = seq++;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++)
				printf("%3d", num[i][j][k]);
			printf("\n");
		}
		printf("\n");
	}
}
