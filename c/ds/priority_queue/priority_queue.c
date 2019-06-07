#include "priority_queue.h"

maxHeap* create_heap(int capacity)
{
	maxHeap* heap = malloc(sizeof(heap));
	heap->capacity = capacity;
	heap->size = 0;
	heap->arr = malloc(sizeof(int) * capacity); 

	return heap;
}

void destroy_heap(maxHeap* heap)
{
	free(heap->arr);
	free(heap);
}

void print_data(maxHeap* heap)
{
	for (int i = 0; i < heap->size; i++)
		printf("%d ", heap->arr[i]);
	printf("\n");
}

void insert(maxHeap* heap, int val)
{
	if (heap->size == heap->capacity) {
		printf("Heap is full!\n");
		exit(EXIT_FAILURE);
	}

	heap->arr[heap->size++] = val;
	shift_up(heap, heap->size - 1);
}

void shift_up(maxHeap* heap, int idx)
{
	while (idx > 0) {
		int pidx = parent(idx);

		if (heap->arr[idx] > heap->arr[pidx]) {
			int tmp = heap->arr[idx];
			heap->arr[idx] = heap->arr[pidx];
			heap->arr[pidx] = tmp;

			idx = pidx;
		} else {
			break;
		}
	}
}

void shift_down(maxHeap* heap, int idx)
{
	int maxIdx = idx;

	int l = left_child(idx);
	if (l < heap->size && heap->arr[l] > heap->arr[maxIdx])
		maxIdx = l;

	int r = right_child(idx);
	if (r < heap->size && heap->arr[r] > heap->arr[maxIdx])
		maxIdx = r;

	if (maxIdx != idx) {
		int tmp = heap->arr[idx];
		heap->arr[idx] = heap->arr[maxIdx];
		heap->arr[maxIdx] = tmp;

		shift_down(heap, maxIdx);
	}
}

int parent(int idx)
{
	return floor((idx - 1) / 2);
}

int left_child(int idx)
{
	return idx * 2 + 1;
}

int right_child(int idx)
{
	return idx * 2 + 2;
}

int get_size(maxHeap* heap)
{
	return heap->size;
}

int get_max(maxHeap* heap)
{
	return heap->arr[0];
}

int extract_max(maxHeap* heap)
{
	int result = heap->arr[0];

	heap->arr[0] = heap->arr[--heap->size];
	shift_down(heap, 0);

	return result;
}

void remove_node(maxHeap* heap, int idx)
{
	if (idx >= heap->size) {
		printf("Out of Bound Index Exception!\n");
		exit(EXIT_FAILURE);
	}

	/*heap->arr[idx] = heap->arr[--heap->size];
	shift_down(heap, idx);*/

	heap->arr[idx] = heap->arr[0] + 1;
	shift_up(heap, idx);

	extract_max(heap);
}

bool is_empty(maxHeap* heap)
{
	return heap->size == 0;
}

void heap_sort(int* arr, int count)
{
	build_heap(arr, count);

	for (int i = count - 1; i >= 0; i--) {
		int tmp = arr[i];
		arr[i] = arr[0];
		arr[0] = tmp;

		shift_down_for_array(arr, i, 0);
	}
}

void build_heap(int* arr, int count)
{
	for (int i = floor(count/2)-1; i >= 0; i--)
		shift_down_for_array(arr, count, i);
}

void shift_down_for_array(int* arr, int count, int idx)
{
	int maxIdx = idx;

	int l = left_child(idx);
	if (l < count && arr[l] > arr[maxIdx])
		maxIdx = l;

	int r = right_child(idx);
	if (r < count && arr[r] > arr[maxIdx])
		maxIdx = r;

	if (maxIdx != idx) {
		int tmp = arr[idx];
		arr[idx] = arr[maxIdx];
		arr[maxIdx] = tmp;

		shift_down_for_array(arr, count, maxIdx);
	}
}


