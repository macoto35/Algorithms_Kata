#include <iostream>
#include <cstdlib>
#include <ctime>
#include <tuple>

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

int findPivot(int* arr, int left, int right) {
	srand((unsigned) time(0));
	int i = rand() % (right - left) + left;
	swap(arr, left, i);

	return arr[left];
}

tuple<int, int> partition(int* arr, int left, int right) {
	int pivot = findPivot(arr, left, right);
	int j, k;
	j = k = left;

	for (int i=left+1; i < right; i++) {
		if (arr[i] < pivot) {
			k++;
			swap(arr, i, k);
			swap(arr, j, k);
			j++;
		} else if (arr[i] == pivot) {
			k++;
			swap(arr, i, k);
		}
	}
	
	return make_tuple(j, k);
}

void quickSort(int* arr, int left, int right) {
	if (left >= right)
		return;

	auto result = partition(arr, left, right);
	quickSort(arr, left, get<0>(result));
	quickSort(arr, get<1>(result)+1, right);
}

void main() {
	int arr[] = {15, 20, 13, 30, 10, 25, 3, 24};
	int n = sizeof(arr) / sizeof(*arr);

	cout << "before quick sort: ";
	print(arr, n);

	quickSort(arr, 0, n);

	cout << "after quick sort: ";
	print(arr, n);
}
