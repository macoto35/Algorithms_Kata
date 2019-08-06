#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int* arr, int size)
{
	int cnt = 0;
	int last_swap_idx = 0;

	for (int i = size - 1; i > 0; ) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j+1]) {
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;

				last_swap_idx = j;
			}
			cnt++;
		}
		i = last_swap_idx;
		last_swap_idx = 0;
	}
	printf("bubble sort loop cnt: %d\n", cnt);
}

int main(int argc, char* argv[])
{
	int arr1[10] = {10, 8, 5, 2, 4, 6, 3, 7, 1, 9};
	bubble_sort(arr1, 10);
	for(int i = 0; i < 10; i++)
		printf("%3d", *(arr1+i));
	printf("\n");

	int arr2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	bubble_sort(arr2, 10);
	for(int i = 0; i < 10; i++)
		printf("%3d", *(arr2+i));
	printf("\n");

	int arr3[10] = {1, 2, 3, 4, 5, 6, 9, 7, 8, 10};
	bubble_sort(arr3, 10);
	for(int i = 0; i < 10; i++)
		printf("%3d", *(arr3+i));
	printf("\n");

	return exit_success;
}
