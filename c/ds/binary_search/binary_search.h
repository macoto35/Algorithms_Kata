#include <math.h>

#ifndef PROJECT_BINARY_SEARCH
#define PROJECT_BINARY_SEARCH

int binary_search(int arr[], int size, int target)
{
	int min = 0, max = size - 1, guess = 0;

	while (min <= max) {
		guess = floor((min + max) / 2);

		if (arr[guess] == target)
			return guess;
		else if (arr[guess] < target)
			min = guess + 1;
		else
			max = guess - 1;
	}

	return -1;
}

int binary_search_recursive(int arr[], int target, int min, int max)
{
	if (max < min) {
		return -1;
	}

	int guess = floor((min + max) / 2);

	if (arr[guess] == target)
		return guess;
	else if (arr[guess] < target)
		return binary_search_recursive(arr, target, guess + 1, max);
	else
		return binary_search_recursive(arr, target, min, guess - 1);
}

#endif
