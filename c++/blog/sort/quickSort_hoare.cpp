#include <iostream>

using namespace std;

void print(int* arr, int n) {
	for (int i = 0; i < n; i++)
		cout << *arr++ << " ";
	cout << endl;
}

void swap(int* arr, int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

int partition(int* arr, int left, int right) {
	int pivot = arr[(left + right) / 2];
	int i = left - 1;
	int j = right + 1;

	while (true) {
		do {
			i++;
		} while(i < right && arr[i] < pivot);

		do {
			j--;
		} while(j > left && arr[j] > pivot);

		cout << "i / j: " << i << " / " << j << endl;
		if (i >= j)
			return j;
		swap(arr, i, j);
	}
}

void quickSort(int* arr, int left, int right) {
	if (left >= right)
		return;

	int j = partition(arr, left, right);

	quickSort(arr, left, j);
	quickSort(arr, j+1, right);
}

void main() {
	int arr[] = {15, 20, 13, 30, 10, 25, 3, 24};
	int n = sizeof(arr) / sizeof(*arr);

	cout << "before quick sort: ";
	print(arr, n);

	quickSort(arr, 0, n - 1);

	cout << "after quick sort: ";
	print(arr, n);
}
