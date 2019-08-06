#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// no duplication / random pivot
void quick_sort_1(int* arr, int size)
{
	if (size < 2)
		return;

	int pivot = arr[rand() % size];
	int l = 0, r = size - 1;

	while (l < r) {
		while (arr[l] < pivot)
			l++;
		while (arr[r] > pivot)
			r--;

		if (l != r) {
			int tmp = arr[l];
			arr[l] = arr[r];
			arr[r] = tmp;
		}
	}

	quick_sort_1(arr, l);
	quick_sort_1(&arr[l + 1], size-l-1);
}

void swap(int* arr, int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void search_mid(int* arr, int l, int r)
{
		int c = floor((l + r) / 2);
		int mid = max(min(arr[l], arr[c]), min(max(arr[l], arr[c]), arr[r]));
		
		printf("l/r/c: %d/%d/%d, mid: %d",l, r, c, mid);
		
		if (mid == arr[c])
			swap(arr, l, c);
		else if (mid == arr[r])
			swap(arr, l, r);
}

void partition(int* arr, int l, int r, int mids[])
{
	int x = arr[l];
	int m1 = l, m2 = l;
	
	for (int i = l + 1; i <= r; i++) {
		if (arr[i] < x) {
			m2++;
			swap(arr, m2, i);
			m1++;
			swap(arr, m1, m2);
		} else if (arr[i] == x) {
			m2++;
			swap(arr, m2, i);
		}
	}
	swap(arr, l, m1);
	
	printf("---------->pivot: %d, l: %d, r: %d, m1: %d, m2: %d, arr: ", x, l, r, m1, m2);
	for (int i = 0; i < 10; i++)
		printf("%3d", arr[i]);
	printf("\n");
	
	mids[0] = m1;
	mids[1] = m2;
}

// duplication / mid pivot
void quick_sort_2(int* arr, int l, int r)
{
	if (l >= r)
		return;
	
	search_mid(arr, l, r);
	
	int mids[2] = {0, 0};
	partition(arr, l, r, mids);
	
	quick_sort_2(arr, l, mids[0] - 1);
	quick_sort_2(arr, mids[1] + 1, r);
}

int main(int argc, char* argv[])
{
	srand(time(0));
	int arr1[10] = {10, 8, 5, 2, 4, 6, 3, 7, 1, 9};
	//quick_sort_1(arr1, 10);
	quick_sort_2(arr1, 0, 9);
	for(int i = 0; i < 10; i++)
		printf("%3d", *(arr1+i));
	printf("\n");

	int arr2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	//quick_sort_1(arr2, 10);
	quick_sort_2(arr2, 0, 9);
	for(int i = 0; i < 10; i++)
		printf("%3d", *(arr2+i));
	printf("\n");

	int arr3[10] = {1, 2, 3, 4, 5, 6, 9, 7, 8, 10};
	//quick_sort_1(arr3, 10);
	quick_sort_2(arr3, 0, 9);
	for(int i = 0; i < 10; i++)
		printf("%3d", *(arr3+i));
	printf("\n");
	
	int arr4[10] = {6, 9, 2, 0, 5, 5, 3, 0, 9, 3};
	quick_sort_2(arr4, 0, 9);
	for(int i = 0; i < 10; i++)
		printf("%3d", *(arr4+i));
	printf("\n");
	
	int arr5[10] = {3, 5, 5, 2, 3, 5, 3, 2, 2, 3};
	quick_sort_2(arr5, 0, 9);
	for(int i = 0; i < 10; i++)
		printf("%3d", *(arr5+i));
	printf("\n");
	
	return EXIT_SUCCESS;
}
