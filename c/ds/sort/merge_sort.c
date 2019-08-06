#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void copy_array(int* arr, int* tmp, int st, int ed)
{
	int k = 0;
	for (int l = st; l <= ed; l++)
		arr[l] = tmp[k++];
}

void merge_top_down(int* arr, int st, int mid, int ed)
{
	int i = st, j = mid + 1;
	int* tmp = malloc(sizeof(int) * (ed + 1));

	for (int k = 0; k <= ed; k++) {
		if (j > ed || (i <= mid && arr[i] <= arr[j]))
			 tmp[k] = arr[i++];
		else
			tmp[k] = arr[j++];
	}

	copy_array(arr, tmp, st, ed);
	free(tmp);
}

void merge_sort_top_down(int* arr, int st, int ed)
{
	if (st < ed) {
		int mid = floor((st + ed) / 2);
		merge_sort_top_down(arr, st, mid);
		merge_sort_top_down(arr, mid + 1, ed);

		merge_top_down(arr, st, mid, ed);
	}
}

void merge_bottom_up(int* arr, int end1, int end2)
{
	int i = 0, j = end1;
	int* tmp = malloc(sizeof(int) * end2);

	for (int k = 0; k < end2; k++) {
		if (j >= end2 || (i < end1 && arr[i] <= arr[j]))
			tmp[k] = arr[i++];
		else
			tmp[k] = arr[j++];
	}

	copy_array(arr, tmp, 0, end2-1);
	free(tmp);
}

void merge_sort_bottom_up(int* arr, int size)
{
	for (int i = 1; i < size; i *= 2)
		for (int j = 0; j < size; j = j + 2*i)
			merge_bottom_up(&arr[j], i, min(2*i, size-j));
}

int main(int argc, char* argv[])
{
	int arr1[10] = {10, 8, 5, 2, 4, 6, 3, 7, 1, 9};
	//merge_sort_top_down(arr1, 0, 9);
	merge_sort_bottom_up(arr1, 10);
	for(int i = 0; i < 10; i++)
		printf("%3d", *(arr1+i));
	printf("\n");

	int arr2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	//merge_sort_top_down(arr2, 0, 9);
	merge_sort_bottom_up(arr2, 10);
	for(int i = 0; i < 10; i++)
		printf("%3d", *(arr2+i));
	printf("\n");

	int arr3[10] = {1, 2, 3, 4, 5, 6, 9, 7, 8, 10};
	//merge_sort_top_down(arr3, 0, 9);
	merge_sort_bottom_up(arr3, 10);
	for(int i = 0; i < 10; i++)
		printf("%3d", *(arr3+i));
	printf("\n");
	
	return EXIT_SUCCESS;
}
