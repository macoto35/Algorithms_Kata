#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "binary_search.h"

int main(int argc, char* argv[])
{
	// while
	int test1[10] = {0, 12, 23, 53, 66, 81, 244, 1244, 9929, 10121};
	int size1 = sizeof(test1) / sizeof(test1[0]);
	assert(binary_search(test1, size1, 23) == 2);
	assert(binary_search(test1, size1, 0) == 0);
	assert(binary_search(test1, size1, 10121) == 9);
	assert(binary_search(test1, size1, 155) == -1);
	assert(binary_search(test1, size1, -1) == -1);
	assert(binary_search(test1, size1, 10122) == -1);

	int test2[2] = {0, 1};
	int size2 = sizeof(test2) / sizeof(test2[0]);
	assert(binary_search(test2, size2, 0) == 0);
	assert(binary_search(test2, size2, 1) == 1);
	assert(binary_search(test2, size2, 2) == -1);

	int test3[1] = {123};
	int size3 = sizeof(test3) / sizeof(test3[0]);
	assert(binary_search(test3, size3, 123) == 0);
	assert(binary_search(test3, size3, 1) == -1);
	assert(binary_search(test3, size3, -45) == -1);

	int test4[3] = {12, 34, 56};
	int size4 = sizeof(test4) / sizeof(test4[0]);
	assert(binary_search(test4, size4, 12) == 0);
	assert(binary_search(test4, size4, 34) == 1);
	assert(binary_search(test4, size4, 56) == 2);

	int test5[5] = {12, 34, 56, 78, 90};
	int size5 = sizeof(test5) / sizeof(test5[0]);
	assert(binary_search(test5, size5, 12) == 0);
	assert(binary_search(test5, size5, 34) == 1);
	assert(binary_search(test5, size5, 56) == 2);
	assert(binary_search(test5, size5, 78) == 3);
	assert(binary_search(test5, size5, 90) == 4);
	assert(binary_search(test5, size5, -1) == -1);
	assert(binary_search(test5, size5, -45) == -1);
	assert(binary_search(test5, size5, 45) == -1);
	assert(binary_search(test5, size5, 999) == -1);

	// recursive
	int test6[10] = {0, 12, 23, 53, 66, 81, 244, 1244, 9929, 10121};
	int size6 = sizeof(test6) / sizeof(test6[0]);
	assert(binary_search(test6, size6, 23) == 2);
	assert(binary_search(test6, size6, 0) == 0);
	assert(binary_search(test6, size6, 10121) == 9);
	assert(binary_search(test6, size6, 155) == -1);
	assert(binary_search(test6, size6, -1) == -1);
	assert(binary_search(test6, size6, 10122) == -1);

	int test7[2] = {0, 1};
	int size7 = sizeof(test7) / sizeof(test7[0]);
	assert(binary_search(test7, size7, 0) == 0);
	assert(binary_search(test7, size7, 1) == 1);
	assert(binary_search(test7, size7, -1) == -1);
	assert(binary_search(test7, size7, 2) == -1);

	int test8[1] = {123};
	int size8 = sizeof(test8) / sizeof(test8[0]);
	assert(binary_search(test8, size8, 123) == 0);
	assert(binary_search(test8, size8, 1) == -1);
	assert(binary_search(test8, size8, -45) == -1);

	int test9[3] = {12, 34, 56};
	int size9 = sizeof(test9) / sizeof(test9[0]);
	assert(binary_search(test9, size9, 12) == 0);
	assert(binary_search(test9, size9, 34) == 1);
	assert(binary_search(test9, size9, 56) == 2);
	assert(binary_search(test9, size9, 0) == -1);
	assert(binary_search(test9, size9, 5) == -1);
	assert(binary_search(test9, size9, 44) == -1);
	assert(binary_search(test9, size9, 999) == -1);

	int test10[5] = {12, 34, 56, 78, 90};
	int size10 = sizeof(test10) / sizeof(test10[0]);
	assert(binary_search(test10, size10, 12) == 0);
	assert(binary_search(test10, size10, 34) == 1);
	assert(binary_search(test10, size10, 56) == 2);
	assert(binary_search(test10, size10, 78) == 3);
	assert(binary_search(test10, size10, 90) == 4);
	assert(binary_search(test10, size10, 0) == -1);
	assert(binary_search(test10, size10, 27) == -1);
	assert(binary_search(test10, size10, 44) == -1);
	assert(binary_search(test10, size10, 999) == -1);


	return EXIT_SUCCESS;
}
