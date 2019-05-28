
queue* create_queue()
{
	queue* q = malloc(sizeof(queue));
	check_memory(q);

	q->read = 0;
	q->write = 0;

	return q;
}

void check_memory(void* ptr)
{
	if (ptr == NULL) {
		printf("Unable to allocate memory.\n");
		exit(EXIT_FAILURE);
	}
}

bool empty(queue* q)
{
	return q->read == q->write;
}

void enqueue(queue* q, int val)
{
	if (full(q)) {
		printf("Cannot enqueue another item.\n");
		exit(EXIT_FAILURE);
	}

	q->data[q->write] = val;
	q->write = (q->write + 1) % capacity;
}

bool full(queue* q)
{
	return (q->write + 1) % capacity == q->read;
}

void destroy(queue* q)
{
	free(q);
}

int dequeue(queue* q)
{
	if (empty(q)) {
		printf("Queue is empty. Cannot dequeue.\n");
		exit(EXIT_FAILURE);
	}

	int result = q->data[q->read];
	q->read = (q->read + 1) % capacity;

	return result;
}

void print_debug(queue* q)
{
	printf("Queue contents (old to new): ");

	for (int i = q->read; i != q->write; i = (i + 1) % capacity)
		printf("%d,", q->data[i]);

	printf("\n");
}

