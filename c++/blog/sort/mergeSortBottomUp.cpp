#include <iostream>
#include <algorithm>

using namespace std;

void print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		cout << *arr++ << " ";
	cout << endl;
}

void copyArray(int* b, int* a, int n)
{
	for (int i = 0; i < n; i++)
		a[i] = b[i];
}

void merge(int* b, int* a, int st, int mid, int ed)
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

void mergeSort(int* b, int* a, int n)
{
	for (int width = 1; width < n; width *= 2) {
		for (int i = 0; i < n; i = i + 2 * width)
			merge(b, a, i, i + width, i + 2 * width);
		copyArray(b, a, n);
	}
}

void main()
{
	int a[] = {12, 59, 34, 23, 17, 61, 31, 14};
	const int n = sizeof(a) / sizeof(*a);
	int b[n];
	copy(a, a+n, b);

	cout << "before sort: ";
	print(a, n);

	mergeSort(b, a, n);
	
	cout << "after sort: ";
	print(a, n);
}
