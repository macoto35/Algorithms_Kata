#include <stdio.h>

void print(int* arr, int len)
{
	for(int i = 0; i < len; i++)
		printf("%d ", *arr++);
	printf("\n");
}

void bubbleSort(int* arr, int len)
{
	int swapped = 1, tmp;

	for(int i = len - 1; i > 0 && swapped; i--) {
		swapped = 0;

		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j+1]) {
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;

				swapped = 1;
			}
		}
	}
}

void main()
{
	int arr[] = {5,2,1,8,3,3};

	printf("before sort: ");
	print(arr, 6);

	bubbleSort(arr, 6);
	
	printf("after sort: ");
	print(arr, 6);

}
