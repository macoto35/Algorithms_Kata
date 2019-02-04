#include <stdio.h>

typedef struct Node Node;

struct Node {
	int data;
	Node* next;
};

Node* head = NULL;
Node* tail = NULL;
int length = 0;

void toString()
{
	Node* tmp = head;
	for(int i = 0; i < length; i++) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

void removeAll()
{
	Node* tmp = head;
	Node* next;
	for(int i = 0; i < length; i++) {
		next = tmp->next;
		free(tmp);
		tmp = next;
	}

	head = NULL;
	tail = NULL;
	length = 0;
}

void addFirst(int input)
{
	Node* node = (Node*)malloc(sizeof(Node*));
	node->data = input;

	if (node != NULL)
		node->next = head;

	if (tail == NULL)
		tail = node;

	head = node;
	length++;
}

void addLast(int input)
{
	Node* node = (Node*)malloc(sizeof(Node*));
	node->data = input;

	if (tail != NULL)
		tail->next = node;

	if (head == NULL)
		head = node;

	tail = node;
	length++;
}

Node* getNode(int idx)
{
	Node* tmp = head;
	for(int i = 0; i < idx; i++) {
		if (tmp->next != NULL)
			tmp = tmp->next;
	}

	return tmp;
}

void addFront(int input, int idx)
{
	if (idx == 0) {
		addFirst(input);
	} else if (idx >= length) {
		addLast(input);
	} else {
		Node* prev = getNode(idx - 1);

		Node* node = (Node*) malloc(sizeof(Node*));
		node->data = input;

		node->next = prev->next;
		prev->next = node;
		length++;
	}
}

void addBack(int input, int idx)
{
	if (idx >= length) {
		addLast(input);
	} else {
		Node* current = getNode(idx);

		Node* node = (Node*) malloc(sizeof(Node*));
		node->data = input;

		node->next = current->next;
		current->next = node;
		
		if (node->next == NULL)
			tail = node;
		
		length++;
	}
}

void main()
{
	// add first - 4,3,2,1
	addFirst(1);
	addFirst(2);
	addFirst(3);
	addFirst(4);
	printf("add first: ");
	toString();

	removeAll();

	// add last - 1,2,3,4
	addLast(1);
	addLast(2);
	addLast(3);
	addLast(4);
	printf("add last: ");
	toString();

	removeAll();

	// add front - 1,3,4,2
	addFront(1, 0);
	addFront(2, 1);
	addFront(3, 1);
	addFront(4, 2);
	printf("add front: ");
	toString();

	removeAll();

	// add back - 1,2,4,3
	addBack(1, 0);
	addBack(2, 1);
	addBack(3, 1);
	addBack(4, 1);
	printf("add back: ");
	toString();

	removeAll();
}
