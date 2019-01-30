#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int j;
	int k;
} Result;

void print(int* arr, int n)
{
	for(int i = 0; i < n; i++)
		printf("%d ", *arr++);
	printf("\n");
}

void swap(int* arr, int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

int findPivot(int* arr, int left, int right)
{
	srand((unsigned) time(NULL));
	int i = rand() % (right - left) + left;
	swap(arr, left, i);

	return arr[left];
}

Result partition(int* arr, int left, int right)
{
	int pivot = findPivot(arr, left, right);
	int j, k;
	j = k = left;

	for(int i = left + 1; i < right; i++) {
		if (arr[i] < pivot) {
			k++;
			swap(arr, i, k);
			swap(arr, j, k);
			j++;
		} else if (arr[i] == pivot) {
			k++;
			swap(arr, i, k);
		}
	}

	Result result;
	result.j = j;
	result.k = k;

	return result;
}

void quickSort(int* arr, int left, int right)
{
	if (left >= right)
		return;

	Result result = partition(arr, left, right);

	quickSort(arr, left, result.j);
	quickSort(arr, result.k+1, right);
}

void main()
{
	int arr[] = {15, 20, 13, 30, 10, 25, 3, 24};
	int n = sizeof(arr) / sizeof(*arr);

	printf("before quick sort: ");
	print(arr, n);

	quickSort(arr, 0, n);
	
	printf("after quick sort: ");
	print(arr, n);
}
