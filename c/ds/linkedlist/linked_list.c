
int size(node* head)
{
	int size = 0;
	
	node* current = head;
	while (current) {
		current = current->next;
		size++;
	}

	return size;
}

void check_address(void* node)
{
	if (!node) {
		printf("Unable to allocate memory.");
		exit(EXIT_FAILURE);
	}
}

void destroy_list(node* head)
{
	node* current = head;

	while(current) {
		node* next = current->next;
		free(current);
		current = next;
	}
}

void push_front(node** head, int val)
{
	node* new = malloc(sizeof(node));
	new->val = val;
	new->next = *head;

	*head = new;
}

bool empty(node* head)
{
	return head == NULL;
}

int value_at(node* head, int idx)
{
	if (idx < 0 || idx > size(head) - 1)
		exit(EXIT_FAILURE);

	node* current = head;
	for (int i = 0; i < idx; i++)
		current = current->next;
	
	return current->val;
}

int pop_front(node** head)
{
	if (*head == NULL) {
		printf("Unable to pop_front an empty list.");
		exit(EXIT_FAILURE);
	}

	node* pop = *head;
	int pop_val = pop->val;

	*head = pop->next;
	free(pop);
	
	return pop_val;
}

void push_back(node** head, int val)
{
	node* new = malloc(sizeof(node));
	new->val = val;
	new->next = NULL;

	if (*head == NULL) {
		*head = new;
		return;
	}

	node* current = *head;
	while(current->next)
		current = current->next;

	current->next = new;
}

int pop_back(node** head)
{
	if (*head == NULL) {
		printf("Unable to pop_back an empty list.");
		exit(EXIT_FAILURE);
	}

	node* prev = NULL;
	node* current = *head;
	while(current->next) {
		prev = current;
		current = current->next;
	}

	int delete_value = current->val;

	if (prev) {
		prev->next = NULL;
	} else {
		*head = NULL;
	}
	free(current);

	return delete_value;
}

int front(node* head)
{
	if (head == NULL) {
		printf("Unable to get front element from empty list.");
		exit(EXIT_FAILURE);
	}

	return head->val;
}

int back(node* head)
{
	if (head == NULL) {
		printf("Unable to get back element from empty list.");
		exit(EXIT_FAILURE);
	}

	node* current = head;
	while (current->next)
		current = current -> next;
	
	return current->val;
}

void insert(node** head, int idx, int val)
{
	int length = size(*head);
	if (idx < 0 || idx > length) {
		printf("Given index out of bounds.");
		exit(EXIT_FAILURE);
	}

	if (idx == 0) {
		push_front(&*head, val);
	} else if (idx == length) {
		push_back(&*head, val);
	} else {
		node* new = malloc(sizeof(node));
		new->val = val;

		node* current = *head;
		node* prev = NULL;
		for (int i = 0; i < idx; i++) {
			prev = current;
			current = current->next;
		}

		prev->next = new;
		new->next = current;
	}
}

void erase(node** head, int idx)
{
	if (*head == NULL) {
		printf("Unable to erase from empty list.");
		exit(EXIT_FAILURE);
	}

	int length = size(*head) - 1;

	if (idx < 0 || idx > length) {
		printf("Given index out of bounds.");
		exit(EXIT_FAILURE);
	}

	if (idx == 0) {
		pop_front(&*head);
	} else if (idx == length) {
		pop_back(&*head);
	} else {
		node* current = *head;
		node* prev = NULL;

		for (int i = 0 ; i < idx; i++) {
			prev = current;
			current = current->next;
		}

		if (prev) {
			prev->next = current->next;
		} else {
			*head = current->next;
		}
		free(current);
	}
}

int value_n_from_end(node* head, int idx)
{
	if (idx < 1 || head == NULL) {
		printf("Cannot get nth item from end.");
		exit(EXIT_FAILURE);
	}

	node* current = head;
	node* match = head;

	int i;
	for (i = 0; i < idx && current; ++i)
		current = current->next;

	if (i != idx) {
		printf("List is too short to get nth item end.");
		exit(EXIT_FAILURE);
	}

	while (current) {
		current = current->next;
		match = match->next;
	}

	return match->val;
}

void reverse(node** head)
{
	node* prev = NULL;
	node* current = *head;
	node* next = *head;

	while (current) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head = prev;
}

void remove_value(node** head, int val)
{
	node* current = *head;
	node* prev = NULL;
	node* delete = NULL;

	while (current) {
		if (current->val == val) {
			delete = current;

			if (prev)
				prev->next = current = current->next;
			else
				*head = current = current->next;
			
			free(delete);
		} else {
			prev = current;
			current = current->next;
		}
	}
}

