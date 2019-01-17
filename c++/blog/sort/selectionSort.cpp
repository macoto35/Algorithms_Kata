#include <iostream>

using namespace std;

void print(int* arr, int len)
{
	for (int i = 0; i < len; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void selectionSort(int* arr, int len)
{
	int idx, tmp;

	for(int i = 0; i < len - 1; i++) {
		idx = i;

		// search
		for (int j = i + 1; j < len; j++) {
			if (arr[j] < arr[idx])
				idx = j;
		}

		// swap
		if (i != idx) {
			tmp = arr[i];
			arr[i] = arr[idx];
			arr[idx] = tmp;
		}
	}
}

void main()
{
	int arr[] = {5, 2, 1, 8, 3};

	cout << "before sort: ";
	print(arr, 5);

	selectionSort(arr, 5);

	cout << "after sort: ";
	print(arr, 5);
}
