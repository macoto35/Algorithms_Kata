#include <stdio.h>

typedef struct Node Node;

struct Node {
	int data;
	Node* next;
};

Node* head = NULL;

Node* tail = NULL;

void print()
{
	Node* tmp = head;
	while(tmp != NULL) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

void enqueue(int data)
{
	// addLast
	Node* node = (Node*) malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	if (tail != NULL)
		tail->next = node;

	if (head == NULL)
		head = node;

	tail = node;
}

int empty()
{
	return head == NULL;
}

int dequeue()
{
	// removeFirst
	if (empty())
		return -1;

	Node* delete = head;
	int result = delete->data;
	Node* newHead = delete->next;

	head = newHead;

	if (newHead == NULL)
		tail = NULL;

	free(delete);
	return result;
}

void main()
{
	for (int i = 1; i <= 10; i++)
		enqueue(i);
	
	printf("[enqueue] ");
	print();
	
	printf("[dequeue]: ");
	for (int i = 1; i <= 10; i++)
		printf("%d ", dequeue());

	printf("\n[empty queue] %d\n", dequeue());
}
