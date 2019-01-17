#include <iostream>

using namespace std;

void print(int* arr, int len)
{
	for (int i = 0 ; i < len; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void bubbleSort(int* arr, int len)
{
	bool swapped = true;
	int tmp;

	for (int i = len - 1; i > 0 && swapped; i--) {
		swapped = false;

		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j+1]) {
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;

				swapped = true;
			}
		}
	}
}

void main()
{
	int arr[] = {5, 2, 1, 8, 3, 3};

	cout << "before sort: ";
	print(arr, 6);
	
	bubbleSort(arr, 6);

	cout << "after sort: ";
	print(arr, 6);
}
