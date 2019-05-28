
queue* create_queue()
{
	queue* q = malloc(sizeof(queue));
	check_address(q);

	q->head = NULL;
	q->tail = NULL;

	return q;
}

void check_address(void* ptr)
{
	if (ptr == NULL) {
		printf("Unable to allowcate more memory.\n");
		exit(EXIT_FAILURE);
	}
}

bool empty(queue* q)
{
	return q->head == NULL;
}

void destroy_queue(queue* q)
{
	node* current = q->head;
	node* tmp = NULL;

	while(current) {
		tmp = current;
		current = current->next;
		free(tmp);
	}

	free(q);
}

void enqueue(queue* q, int val)
{
	node* new = malloc(sizeof(node));
	new->val = val;
	new->next = NULL;
	check_address(new);

	if (empty(q))
		q->head = new;
	else
		q->tail->next = new;

	q->tail = new;
}

int dequeue(queue* q)
{
	if (empty(q)) {
		printf("Unable to dequeue. Queue is empty.\n");
		exit(EXIT_FAILURE);
	}

	node* remove = q->head;
	int result = remove->val;
	
	q->head = remove->next;
	if (empty(q))
		q->tail = NULL;

	free(remove);
	return result;
}

void print_debug(queue* q)
{
	printf("Queue contents: ");

	node* current = q->head;

	while(current) {
		printf("%d,", current->val);
		current = current->next;
	}

	printf("\n");
}
