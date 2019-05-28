#include <stdio.h> // IO
#include <stdlib.h> // malloc

#include "array.h"
#include "array.c"

void run_example();

int main(int argc, char* argv[])
{
	run_all_tests();
	run_example();

	return EXIT_SUCCESS;
}

void run_example()
{
	int capacity = 0;

	printf("enter many numbers would you like to store: ");
	scanf("%d", &capacity);
	printf("You'll be storing %d numbers.\n", capacity);

	SArray* arr = sarray_new(capacity);

	for (int i = 1; i <= capacity; i++)
		sarray_push(arr, i);

	int insert_value = 999;
	printf(" - Inserting %d at index %d.\n", insert_value, capacity - 1);
	sarray_insert(arr, capacity - 1, insert_value);

	printf(" - Prepending %d.\n", 12);
	sarray_prepend(arr, 12);

	printf(" - Poping an item: %d\n", sarray_pop(arr));

	sarray_print(arr);

	int index_to_remove = sarray_size(arr) - 3;
	printf(" - Deleting from index %d\n", index_to_remove);
	sarray_delete(arr, index_to_remove);

	sarray_push(arr, 12);
	sarray_push(arr, 12);

	sarray_print(arr);

	printf(" - Deleting 12s\n");
	sarray_remove(arr, 12);
	
	sarray_print(arr);

	sarray_destroy(arr);
}
