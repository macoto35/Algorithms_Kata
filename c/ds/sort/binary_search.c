#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

int binary_search(int* arr, int size, int target)
{
	int st = 0, end = size - 1, mid = 0;
	while (st <= end) {
		mid = floor((st + end) / 2);
		if (target == arr[mid])
			return mid;
		else if (target < arr[mid])
			end = mid - 1;
		else 
			st = mid + 1;
	}

	return -1;
}

int main(int argc, char* argv[])
{
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	assert(binary_search(arr, 10, 7) == 6);
	assert(binary_search(arr, 10, 1) == 0);
	assert(binary_search(arr, 10, 10) == 9);
	assert(binary_search(arr, 10, 24) == -1);
	
	return EXIT_SUCCESS;
}
