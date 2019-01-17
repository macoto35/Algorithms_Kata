#include <stdio.h>

void print(int* arr, int len)
{
	for (int i = 0; i < len; i++)
		printf("%d ", *arr++);
	printf("\n");
}

void insertionSort(int* arr, int len)
{
	int tmp, j;

	for(int i = 1; i < len; i++) {
		tmp = arr[i];
		j = i - 1;

		while(j >= 0 && arr[j] > tmp) {
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = tmp;
	}
}

void main()
{
	int arr[] = {5,2,1,8,3,3};

	printf("before sort: ");
	print(arr, 6);
	
	insertionSort(arr, 6);

	printf("after sort: ");
	print(arr, 6);
}
