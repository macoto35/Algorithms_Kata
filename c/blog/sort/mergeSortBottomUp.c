#include <stdio.h>
#include <string.h>

void print(int* arr, int n)
{
	for (int i = 0; i < n ; i++)
		printf("%d ", *arr++);
	printf("\n");
}

void copyArray(int* a, int* b, int n)
{
	for (int i = 0; i < n; i++)
		a[i] = b[i];
}

void merge(int* a, int* b, int st, int mid, int ed)
{
	int i = st;
	int j = mid;

	for (int k = st; k < ed; k++) {
		if (i < mid && (j >= ed || a[i] <= a[j]))
			b[k] = a[i++];
		else
			b[k] = a[j++];
	}
}

void mergeSort(int* a, int* b, int n)
{
	for (int width = 1; width < n ; width *= 2) {
		for (int i = 0; i < n; i = i + 2 * width)
			merge(a, b, i, i + width, i + 2 * width);
		copyArray(a, b, n);
	}
}

void main()
{
	int a[] = {12, 59, 34, 23, 17, 61, 31, 14};
	int b[8];
	int n = sizeof(a) / sizeof(*a);
	memcpy(b, a, sizeof(a));

	printf("before merge sort: ");
	print(a, n);
	
	mergeSort(a, b, n);

	printf("after merge sort: ");
	print(a, n);
}
