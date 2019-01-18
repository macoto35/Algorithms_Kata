#include <iostream>

using namespace std;

void print(int * arr, int len)
{
	for(int i = 0 ; i < len; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void shellSort(int* arr, int len)
{
	int tmp, j, gap = len;

	while(gap > 1) {
		gap = gap / 3 + 1;
		for (int i = gap; i < len; i++) {
			tmp = arr[i];
			for (j = i; j >= gap && arr[j - gap] > tmp; j -= gap)
				arr[j] = arr[j - gap];
			arr[j] = tmp;
		}
	}
}

void main()
{
	int arr1[] = {5, 2, 3, 8, 1};

	cout << "before sort: ";
	print(arr1, 5);

	shellSort(arr1, 5);

	cout << "after sort: ";
	print(arr1, 5);



	int arr2[] = {62, 83, 18, 53, 7, 17, 95, 86, 47, 69, 25, 28};
	
	cout << "before sort: ";
	print(arr2, 12);

	shellSort(arr2, 12);

	cout << "after sort: ";
	print(arr2, 12);
}
