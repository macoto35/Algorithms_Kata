#include <stdio.h>
#include <string.h>

void print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", *arr++);
	printf("\n");
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

void mergeSort(int* b, int* a, int st, int ed)
{
	if (ed - st < 2)
		return;

	int mid = (st + ed) / 2;

	mergeSort(a, b, st, mid);
	mergeSort(a, b, mid, ed);

	merge(b, a, st, mid, ed);
}

void main()
{
	int a[] = {59, 12};//, 34, 23, 17, 61, 31, 14};
	int b[2];
	int n = sizeof(a) / sizeof(*a);
	memcpy(b, a, sizeof(a));

	printf("before merge sort: ");
	print(a, n);

	mergeSort(b, a, 0, n);
	
	printf("after merge sort: ");
	print(a, n);
}
