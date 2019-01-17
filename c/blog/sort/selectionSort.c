#include <stdio.h>

void print(int* arr, int len)
{
	for (int i = 0; i < len; i++)
		printf("%d ", *arr++);
	printf("\n");
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

	printf("before sort: ");
	print(arr, 5);

	selectionSort(arr, 5);
	
	printf("after sort: ");
	print(arr, 5);
}
