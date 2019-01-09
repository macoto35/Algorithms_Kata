#include <stdio.h>

void main()
{
	int arr[3] = {3, 6, 9};

	// array pointer -> arr == &arr[0]
	printf("arr[0] = %d, *arr = %d\n", arr[0], *arr);
	printf("arr[1] = %d, *(arr+1) = %d\n", arr[1], *(arr+1));
	printf("arr[2] = %d, *(arr+2) = %d\n", arr[2], *(arr+2));

	// normal pointer
	int* p = arr;
	printf("arr[0] = %d, *arr = %d, *p = %d\n", arr[0], *arr, *p);
	printf("arr[1] = %d, *(arr+1) = %d, *(p+1) = %d\n", arr[1], *(arr+1), *(p+1));
	printf("arr[2] = %d, *(arr+2) = %d, *(p+2) = %d\n", arr[2], *(arr+2), *(p+2));
}
