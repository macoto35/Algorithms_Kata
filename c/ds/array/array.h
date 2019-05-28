#ifndef PROJECT_ARRAY_H
#define PROJECT_ARRAY_H

#include <assert.h>
#include <stdbool.h>

const int minInitCapacity = 1;
const int minCapacity = 16;
const int growthFactor = 2;
const int shrinkFactor = 4;

typedef struct {
	int size;
	int capacity;
	int* data;
} SArray;

SArray* sarray_new(int capacity);
int sarray_size(SArray* arr);
void sarray_destroy(SArray* arr);
int sarray_determine_capacity(int capcity);
void check_address(void* arr);
void sarray_push(SArray* arr, int value);
void sarray_resize_for_size(SArray* arr, int candidate_size);
void sarray_upsize(SArray* arr);
void sarray_downsize(SArray* arr);
bool sarray_is_empty(SArray* arr);
int sarray_capacity(SArray* arr);
int sarray_pop(SArray* arr);
int sarray_at(SArray* arr, int idx);
void sarray_insert(SArray* arr, int idx, int val);
void sarray_prepend(SArray* arr, int val);
void sarray_remove(SArray* arr, int val);
void sarray_delete(SArray* arr, int idx);
int sarray_find(SArray* arr, int val);
void sarray_print(SArray* arr);

void run_all_tests();
void test_size_init();
void test_append();
void test_empty();
void test_resize();
void test_at();
void test_insert();
void test_prepend();
void test_pop();
void test_remove();
void test_find_exists();
void test_find_not_exists();

#endif
