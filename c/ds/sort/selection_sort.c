#include <stdio.h>
#include <stdlib.h>

void selection_sort(int* arr, int size)
{
	int min_idx;
	for (int i = 0; i < size - 1; i++) {
		min_idx = i;

		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[min_idx]) {
				min_idx = j;
			}
		}

		if (min_idx != i) {
			int tmp = arr[i];
			arr[i] = arr[min_idx];
			arr[min_idx] = tmp;
		}
	}
}

int main(int argc, char* argv[])
{
	int arr1[10] = {10, 8, 5, 2, 4, 6, 3, 7, 1, 9};
	selection_sort(arr1, 10);
	for(int i = 0; i < 10; i++)
		printf("%3d", *(arr1+i));
	printf("\n");

	int arr2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	selection_sort(arr2, 10);
	for(int i = 0; i < 10; i++)
		printf("%3d", *(arr2+i));
	printf("\n");

	int arr3[10] = {1, 2, 3, 4, 5, 6, 9, 7, 8, 10};
	selection_sort(arr3, 10);
	for(int i = 0; i < 10; i++)
		printf("%3d", *(arr3+i));
	printf("\n");
	
	return EXIT_SUCCESS;
}
