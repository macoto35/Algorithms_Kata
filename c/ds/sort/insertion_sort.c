#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int* arr, int size)
{
	int cnt = 0;

	for (int i = 1; i < size; i++) {
		int j = i;
		int data = arr[i];
		while (j > 0 && data < arr[j-1]) {
			arr[j] = arr[j-1];
			j--;
			cnt++;
		}
		arr[j] = data;
	}

	printf("insertion sort loop cnt: %d\n", cnt);
}

int main(int argc, char* argv[])
{
	int arr1[10] = {10, 8, 5, 2, 4, 6, 3, 7, 1, 9};
	insertion_sort(arr1, 10);
	for(int i = 0; i < 10; i++)
		printf("%3d", *(arr1+i));
	printf("\n");

	int arr2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	insertion_sort(arr2, 10);
	for(int i = 0; i < 10; i++)
		printf("%3d", *(arr2+i));
	printf("\n");

	int arr3[10] = {1, 2, 3, 4, 5, 6, 9, 7, 8, 10};
	insertion_sort(arr3, 10);
	for(int i = 0; i < 10; i++)
		printf("%3d", *(arr3+i));
	printf("\n");

	return EXIT_SUCCESS;
}
