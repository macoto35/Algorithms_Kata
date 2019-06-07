#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#ifndef PROJECT_PRIORITY_QUEUE
#define PROJECT_PRIORITY_QUEUE

typedef struct {
	int capacity;
	int size;
	int* arr;
} maxHeap;

maxHeap* create_heap(int capacity);
void destroy_heap(maxHeap* heap);
void print_data(maxHeap* heap);
void insert(maxHeap* heap, int val);
void shift_up(maxHeap* heap, int idx);
void shift_down(maxHeap* heap, int idx);
int parent(int idx);
int left_child(int idx);
int right_child(int idx);
int get_size(maxHeap* heap);
int get_max(maxHeap* heap);
int extract_max(maxHeap* heap);
void remove_node(maxHeap* heap, int idx);
bool is_empty(maxHeap* heap);
void heap_sort(int* arr, int count);
void build_heap(int* arr, int count);
void shift_down_for_array(int* arr, int count, int idx);

#endif
