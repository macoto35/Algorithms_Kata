
SArray* sarray_new(int capacity)
{
	int true_capacity = sarray_determine_capacity(capacity);
	
	SArray* arr = malloc(sizeof(SArray));
	check_address(arr);

	arr->size = 0;
	arr->capacity = true_capacity;
	arr->data = (int*) malloc(sizeof(int) * true_capacity);
	check_address(arr->data);

	return arr;
}

int sarray_size(SArray* arr)
{
	return arr->size;
}

void sarray_destroy(SArray* arr)
{
	free(arr->data);
	free(arr);
}

int sarray_determine_capacity(int capacity)
{
	int true_capacity = minCapacity;

	if (capacity < minInitCapacity) {
		exit(EXIT_FAILURE);
	}

	while (capacity > true_capacity / growthFactor) {
		true_capacity *= growthFactor;
	}

	return true_capacity;
}

void check_address(void* arr)
{
	if (arr == NULL) {
		printf("Unable to allocate memory.\n");
		exit(EXIT_FAILURE);
	}
}

void sarray_push(SArray* arr, int val)
{
	sarray_resize_for_size(arr, arr->size + 1);
	
	*(arr->data + arr->size) = val;
	arr->size++;
}

void sarray_resize_for_size(SArray* arr, int candidate_size)
{
	if (arr->size < candidate_size && arr->size == arr->capacity) {
		// growing
		sarray_upsize(arr);

	} else if (arr->size >= candidate_size && arr->size < arr->capacity / shrinkFactor) {
		// shrinking
		sarray_downsize(arr);
	}
}

void sarray_upsize(SArray* arr)
{
	int old_capacity = arr->capacity;
	int new_capacity = sarray_determine_capacity(old_capacity);

	int* new_data = (int*) malloc(sizeof(int) * new_capacity);
	check_address(new_data);

	for (int i = 0; i < old_capacity; i++)
		*(new_data + i) = *(arr->data + i);

	free(arr->data);

	arr->data = new_data;
	arr->capacity = new_capacity;
}

void sarray_downsize(SArray* arr)
{
	int old_capacity = arr->capacity;
	int new_capacity = arr->capacity / growthFactor;

	if (new_capacity < minCapacity)
		new_capacity = minCapacity;

	if (new_capacity != old_capacity) {
		int* new_data = (int*) malloc(sizeof(int) * new_capacity);
		check_address(new_data);

		for (int i = 0; i < arr->size; i++)
			*(new_data + i) = *(arr->data + i);

		free(arr->data);

		arr->data = new_data;
		arr->capacity = new_capacity;
	}
}

bool sarray_is_empty(SArray* arr)
{
	return arr->size == 0;
}

int sarray_capacity(SArray* arr)
{
	return arr->capacity;
}

int sarray_pop(SArray* arr)
{
	if (arr->size == 0)
		exit(EXIT_FAILURE);

	arr->size--;
	int popped_value = *(arr->data + arr->size);

	sarray_resize_for_size(arr, arr->size);

	return popped_value;
}

int sarray_at(SArray* arr, int idx)
{
	if (idx < 0 || idx > arr->size - 1)
		exit(EXIT_FAILURE);

	return *(arr->data + idx);
}

void sarray_insert(SArray* arr, int idx, int val)
{
	if (idx < 0 || idx > arr->size - 1)
		exit(EXIT_FAILURE);

	sarray_resize_for_size(arr, arr->size + 1);

	for (int i = arr->size; i > idx; i--)
		*(arr->data + i) = *(arr->data + i - 1);

	*(arr->data + idx) = val;
	arr->size++;
}

void sarray_prepend(SArray* arr, int val)
{
	sarray_insert(arr, 0, val);
}

void sarray_remove(SArray* arr, int val)
{
	int i = 0;
	while(i < arr->size) {
		if (*(arr->data + i) == val)
			sarray_delete(arr, i);
		else
			i++;
	}
}

void sarray_delete(SArray* arr, int idx)
{
	if (idx < 0 || idx > arr->size - 1)
		exit(EXIT_FAILURE);

	arr->size--;

	for (int i = idx; i < arr->size; i++)
		*(arr->data + i) = *(arr->data + i + 1);

	sarray_resize_for_size(arr, arr->size);
}

int sarray_find(SArray* arr, int val)
{
	int idx = -1;

	for (int i = 0; i < arr->size; i++) {
		if (*(arr->data + i) == val) {
			idx = i;
			break;
		}
	}

	return idx;
}

void sarray_print(SArray* arr)
{
	printf("Size: %d, Capacity: %d\n", arr->size, arr->capacity);
	printf("Items: \n");

	for(int i = 0; i < arr->size; i++)
		printf("%d: %d, ", i, *(arr->data + i));
	printf("\n-----\n");
}





void run_all_tests()
{
	test_size_init();
	test_append();
	test_empty();
	test_resize();
	test_at();
	test_insert();
	test_prepend();
	test_pop();
	test_remove();
	test_find_exists();
	test_find_not_exists();
}

void test_size_init()
{
	SArray* arr = sarray_new(5);
	int initial_size = sarray_size(arr);
	assert(initial_size == 0);
	sarray_destroy(arr);
}

void test_append()
{
	SArray* arr = sarray_new(2);
	sarray_push(arr, 2);
	sarray_push(arr, 12);
	int new_size = sarray_size(arr);
	assert(new_size == 2);
	sarray_destroy(arr);
}

void test_empty()
{
	SArray* arr = sarray_new(2);
	bool empty = sarray_is_empty(arr);
	assert(empty == 1);
	
	sarray_push(arr, 1);
	empty = sarray_is_empty(arr);
	assert(empty == 0);

	sarray_destroy(arr);
}

void test_resize()
{
	SArray* arr = sarray_new(2);
	int old_capacity = sarray_capacity(arr);
	assert(old_capacity == 16);

	for (int i = 0; i < 18; i++)
		sarray_push(arr, i);
	assert(sarray_capacity(arr) == 32);

	for (int i = 0; i < 16; i++)
		sarray_pop(arr);
	assert(sarray_capacity(arr) == 16);

	sarray_destroy(arr);
}

void test_at()
{
	SArray* arr = sarray_new(12);

	for (int i = 0; i < 12; i++)
		sarray_push(arr, i + 3);

	assert(sarray_at(arr, 6) == 9);
	sarray_destroy(arr);
}

void test_insert()
{
	SArray* arr = sarray_new(5);

	for (int i = 0; i < 5; i++)
		sarray_push(arr, i + 5);

	sarray_insert(arr, 2, 47);
	assert(sarray_at(arr, 2) == 47);
	assert(sarray_at(arr, 3) == 7);

	sarray_destroy(arr);
}

void test_prepend()
{
	SArray* arr = sarray_new(5);
	for (int i = 0; i < 5; i++)
		sarray_push(arr, i);

	sarray_prepend(arr, 15);
	assert(sarray_at(arr, 0) == 15);
	assert(sarray_at(arr, 1) == 0);

	sarray_destroy(arr);
}

void test_pop()
{
	SArray* arr = sarray_new(5);

	for (int i = 0; i < 5; i++)
		sarray_push(arr, i);
	assert(sarray_size(arr) == 5);

	for (int i = 0; i < 5; i++)
		sarray_pop(arr);
	assert(sarray_is_empty(arr) == 1);

	sarray_destroy(arr);
}

void test_remove()
{
	SArray* arr = sarray_new(5);
	sarray_push(arr, 12);
	sarray_push(arr, 3);
	sarray_push(arr, 41);
	sarray_push(arr, 12);
	sarray_push(arr, 12);

	sarray_remove(arr, 12);
	assert(sarray_size(arr) == 2);

	sarray_destroy(arr);
}

void test_find_exists()
{
	SArray* arr = sarray_new(5);
	for (int i = 0; i < 5; i++)
		sarray_push(arr, i + 1);
	
	assert(sarray_find(arr, 1) == 0);
	assert(sarray_find(arr, 4) == 3);
	assert(sarray_find(arr, 5) == 4);

	sarray_destroy(arr);
}

void test_find_not_exists()
{
	SArray* arr = sarray_new(3);
	for (int i = 0; i < 3; i++)
		sarray_push(arr, i + 3);

	assert(sarray_find(arr, 7) == -1);

	sarray_destroy(arr);
}


