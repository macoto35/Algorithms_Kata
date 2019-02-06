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

void tearDown()
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

/* SINGLY LINKED LIST FUNCTION ------------------------------------------------------------------ */
void addFirst(int input)
{
	Node* node = (Node*)malloc(sizeof(Node*));
	node->data = input;
	node->next = NULL;

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
	node->next = NULL;

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
		node->next = NULL;

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
		node->next = NULL;

		node->next = current->next;
		current->next = node;
		
		if (node->next == NULL)
			tail = node;
		
		length++;
	}
}

int empty()
{
	return head == NULL;
}

int removeFirst()
{
	if (empty())
		return -1;
	
	Node* delete = head;
	head = head->next;
	int result = delete->data;

	if (head == NULL)
		tail = NULL;

	free(delete);
	length--;

	return result;
}

int removeN(int idx)
{
	if (idx == 0) {
		return removeFirst();
	} else if (idx >= length) {
		return -1;
	} else {
		Node* prev = getNode(idx - 1);
		Node* delete = prev->next;
		int result = delete->data;

		prev->next = delete->next;
		if (prev->next == NULL)
			tail = prev;

		free(delete);
		length--;

		return result;
	}
}

int removeLast()
{
	if (empty())
		return -1;
	return removeN(length - 1);
}

int size()
{
	return length;
}

int get(int idx)
{
	if (idx < 0 || idx >= length)
		return -1;
	return getNode(idx)->data;
}

int indexOf(int data)
{
	Node* tmp = head;
	
	for (int i = 0; i < length; i++) {
		if (tmp->data == data)
			return i;
		tmp = tmp->next;
	}
	
	return -1;
}

/* TEST FUNCTION ------------------------------------------------------------------ */
void addFirstTest()
{
	// add first - 4,3,2,1
	addFirst(1);
	addFirst(2);
	addFirst(3);
	addFirst(4);
	printf("add first: ");
	toString();

	tearDown();
}

void addLastTest()
{
	// add last - 1,2,3,4
	addLast(1);
	addLast(2);
	addLast(3);
	addLast(4);
	printf("add last: ");
	toString();

	tearDown();
}

void addFrontTest()
{
	// add front - 1,3,4,2
	addFront(1, 0);
	addFront(2, 1);
	addFront(3, 1);
	addFront(4, 2);
	printf("add front: ");
	toString();

	tearDown();
}

void addBackTest()
{
	// add back - 1,2,4,3
	addBack(1, 0);
	addBack(2, 1);
	addBack(3, 1);
	addBack(4, 1);
	printf("add back: ");
	toString();

	tearDown();
}

void removeFirstTest()
{
	addLast(1);
	addLast(2);
	addLast(3);
	addLast(4);
	addLast(5);

	printf("remove first: %d ", removeFirst());
	printf("%d ", removeFirst());
	printf("%d ", removeFirst());
	printf("%d ", removeFirst());
	printf("%d ", removeFirst());
	printf("%d\n", removeFirst());

	tearDown();
}

void removeTest()
{
	addLast(1);
	addLast(2);
	addLast(3);
	addLast(4);
	addLast(5);
	
	printf("remove: %d ", removeN(5));
	printf("%d ", removeN(4));
	printf("%d ", removeN(0));
	printf("%d ", removeN(1));
	printf("%d ", removeN(1));
	printf("%d\n", removeN(0));

	tearDown();
}

void removeLastTest()
{
	addLast(1);
	addLast(2);
	addLast(3);
	addLast(4);
	addLast(5);
	
	printf("remove last: %d ", removeLast());
	printf("%d ", removeLast());
	printf("%d ", removeLast());
	printf("%d ", removeLast());
	printf("%d ", removeLast());
	printf("%d\n", removeLast());

	tearDown();
}

void emptyTest()
{
	printf("empty: %s ", empty() ? "true" : "false");

	addLast(1);
	printf("%s\n", empty() ? "true" : "false");

	tearDown();
}

void sizeTest()
{
	printf("size: %d ", size());
	
	addLast(1);
	printf("%d\n", size());

	tearDown();
}

void getTest()
{
	addLast(1);
	addLast(2);
	addLast(3);
	addLast(4);
	addLast(5);

	printf("get: %d ", get(-1));
	printf("%d ", get(0));
	printf("%d ", get(1));
	printf("%d ", get(2));
	printf("%d ", get(3));
	printf("%d ", get(4));
	printf("%d\n", get(5));

	tearDown();
}

void indexOfTest()
{
	addLast(1);
	addLast(2);
	addLast(3);
	addLast(4);
	addLast(5);

	printf("indexOf: %d ", indexOf(1));
	printf("%d ", indexOf(2));
	printf("%d ", indexOf(3));
	printf("%d ", indexOf(4));
	printf("%d ", indexOf(5));
	printf("%d\n", indexOf(6));

	tearDown();
}

void main()
{
	addFirstTest();
	addLastTest();
	addFrontTest();
	addBackTest();

	removeFirstTest();
	removeTest();
	removeLastTest();

	emptyTest();
	sizeTest();
	getTest();
	indexOfTest();

	printf("\65");
}
