#include "priority_queue.c"

int main(int argc, char* argv[])
{
	// binary max heap
	maxHeap* heap = create_heap(15);

	insert(heap, 4);
	assert(get_size(heap) == 1);
	insert(heap, 14);
	assert(get_size(heap) == 2);
	insert(heap, 34);
	assert(get_size(heap) == 3);
	insert(heap, 15);
	insert(heap, 5);
	insert(heap, 12);
	insert(heap, 46);
	insert(heap, 19);
	insert(heap, 17);
	insert(heap, 11);
	insert(heap, 17);
	assert(get_size(heap) == 11);
	print_data(heap);

	assert(get_max(heap) == 46);

	remove_node(heap, 1);
	assert(get_size(heap) == 10);
	print_data(heap);

	assert(extract_max(heap) == 46);
	assert(get_size(heap) == 9);
	assert(extract_max(heap) == 34);
	assert(get_size(heap) == 8);
	assert(extract_max(heap) == 17);
	assert(extract_max(heap) == 17);
	assert(extract_max(heap) == 15);
	assert(extract_max(heap) == 14);
	assert(extract_max(heap) == 12);
	assert(extract_max(heap) == 11);
	assert(extract_max(heap) == 5);
	assert(get_size(heap) == 1);
	assert(extract_max(heap) == 4);
	assert(get_size(heap) == 0);

	assert(is_empty(heap));

	// heap sort
	int to_sort[10] = {10, 123, 43, 17, 13, 9, 422, 2477, 18, 53};
	int sorted[10] = {9, 10, 13, 17, 18, 43, 53, 123, 422, 2477};

	heap_sort(to_sort, 10);

	for (int i = 0; i < 10; i++)
		printf("%5d ", to_sort[i]);

	assert(memcmp(to_sort, sorted, sizeof(to_sort)) == 0);
	
	
	destroy_heap(heap);

	return EXIT_SUCCESS;
}
