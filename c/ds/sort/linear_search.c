#include <stdio.h>
#include <stdlib.h>

int linear_search(int* arr, int size, int target)
{
	for (int i = 0; i < size; i++) {
		if (target == arr[i])
			return i;
	}

	return -1;
}

int main(int argc, char* argv[])
{
	int arr1[10] = {10, 8, 5, 2, 4, 6, 3, 7, 1, 9};
	printf("idx of 7: %d\n", linear_search(arr1, 10, 7));
	printf("idx of 24: %d\n", linear_search(arr1, 10, 24));

	int arr2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	printf("idx of 7: %d\n", linear_search(arr1, 10, 7));
	printf("idx of 24: %d\n", linear_search(arr1, 10, 24));
}
