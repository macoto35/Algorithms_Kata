#include <iostream>
#include <algorithm>

using namespace std;

void print(int* arr, int n)
{
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
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
	int a[] = {12, 59, 34, 23, 17, 61, 31, 14};
	const int n = sizeof(a) / sizeof(*a);
	int b[n];
	copy(a, a+n, b);

	cout << "before merge sort: ";
	print(a, n);

	mergeSort(b, a, 0, n);

	cout << "after merge sort: ";
	print(a, n);
}
