#include <stdio.h>

/* global variables */
typedef struct Node Node;

struct Node {
	int data;
	Node* prev;
	Node* next;
};

Node* head = NULL;

Node* tail = NULL;

int length = 0;



/* Doubly Linked List functions */
void print()
{
	Node* tmp = head;
	for (int i = 0; i < length; i++) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
}

void tearDown()
{
	Node* tmp;
	for (int i = 0; i < length; i++) {
		tmp = head->next;
		free(head);
		head = tmp;
	}
	head = NULL;
	tail = NULL;
	length = 0;
	printf(" - successfully tear down!\n");
}

Node* createNode(int input)
{
	Node* node = (Node*) malloc(sizeof(Node));
	node->data = input;
	node->prev = NULL;
	node->next = NULL;

	return node;
}

void addFirst(int input)
{
	Node* node = createNode(input);

	if (head != NULL) {
		node->next = head;
		head->prev = node;
	}

	if (tail == NULL) {
		tail = node;
	}

	head = node;
	length++;
}

void addLast(int input)
{
	Node* node = createNode(input);

	if (tail != NULL) {
		tail->next = node;
		node->prev = tail;
	}

	if (head == NULL) {
		head = node;
	}

	tail = node;
	length++;
}

Node* getNode(int idx)
{
	if (idx < length/2) {
		Node* tmp = head;
		
		for (int i = 0; i < idx; i++) {
			if (tmp != NULL)
				tmp = tmp->next;
		}

		return tmp;
	} else {
		Node* tmp = tail;

		for (int i = length - 1; i > idx; i--)
			if (tmp != NULL)
				tmp = tmp->prev;
		
		return tmp;
	}
}

void addFront(int input, int idx)
{
	if (idx == 0) {
		addFirst(input);
	} else if (idx >= length) {
		addLast(input);
	} else {
		Node* node = createNode(input);
		Node* next = getNode(idx);
		Node* prev = next->prev;

		prev->next = node;
		node->prev = prev;

		node->next = next;
		next->prev = node;

		length++;
	}
}

void addBack(int input, int idx)
{
	if (idx >= length) {
		addLast(input);
	} else {
		Node* node = createNode(input);
		Node* prev = getNode(idx);
		Node* next = prev->next;

		prev->next = node;
		node->prev = prev;

		if (next != NULL) {
			node->next = next;
			next->prev = node;
		}

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
	int result = delete->data;
	Node* newHead = delete->next;

	head = newHead;
	if (newHead != NULL) {
		newHead->prev = NULL;
	} else {
		tail = NULL;
	}

	free(delete);
	length--;

	return result;
}

int remove1(int idx)
{
	if (empty() || idx < 0 || idx >= length) {
		return -1;
	} else if (idx == 0) {
		return removeFirst();
	} else {
		Node* delete = getNode(idx);
		int result = delete->data;
		Node* prev = delete->prev;
		Node* next = delete->next;

		if (prev != NULL)
			prev->next = next;
		else
			head = next;

		if (next != NULL)
			next->prev = prev;
		else
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
	return remove1(length - 1);
}

int size()
{
	return length;
}

int get(int idx)
{
	if (empty() || idx < 0 || idx >= length)
		return -1;
	return getNode(idx)->data;
}

int indexOf(int data)
{
	Node* tmp = head;
	for (int i = 0; i < length; i++) {
		if (data == tmp->data)
			return i;
		tmp = tmp->next;
	}
	return -1;
}



/* Test functions */
void addFirstTest()
{
	addFirst(1);
	addFirst(2);
	addFirst(3);
	addFirst(4);
	printf("add first: ");
	print();
	tearDown();
}

void addLastTest()
{
	addLast(1);
	addLast(2);
	addLast(3);
	addLast(4);
	printf("add last: ");
	print();
	tearDown();
}

void addFrontTest()
{
	addFront(1, 0);
	addFront(2, 0);
	addFront(3, 1);
	addFront(4, 2);
	addFront(5, 2);
	addFront(6, 3);
	printf("add front: ");
	print();
	tearDown();
}

void addBackTest()
{
	addBack(1, 0);
	addBack(2, 1);
	addBack(3, 1);
	addBack(4, 1);
	printf("add back: ");
	print();
	tearDown();
}

void getTestNodes()
{
	addLast(1);
	addLast(2);
	addLast(3);
	addLast(4);
	addLast(5);
}

void removeFirstTest()
{
	getTestNodes();

	printf("remove first: %d ", removeFirst());
	printf("%d ", removeFirst());
	printf("%d ", removeFirst());
	printf("%d ", removeFirst());
	printf("%d ", removeFirst());
	printf("%d ", removeFirst());

	getTestNodes();
	removeFirst();
	removeFirst();
	addFirst(6);
	addBack(7, 2);
	removeFirst();
	addFront(8, 3);
	addLast(9);
	print();
	tearDown();
}

void removeTest()
{
	getTestNodes();

	printf("remove: %d ", remove1(5));
	printf("%d ", remove1(-1));
	printf("%d ", remove1(4));
	printf("%d ", remove1(0));
	printf("%d ", remove1(1));
	printf("%d ", remove1(1));
	printf("%d ", remove1(0));
	tearDown();
}

void removeLastTest()
{
	getTestNodes();

	printf("remove last: %d ", removeLast());
	printf("%d ", removeLast());
	printf("%d ", removeLast());
	printf("%d ", removeLast());
	printf("%d ", removeLast());
	printf("%d ", removeLast());
	tearDown();
}

void emptyTest()
{
	printf("empty: %s ", empty() ? "true" : "false");

	addLast(1);
	printf("%s ", empty() ? "true" : "false");
	tearDown();
}

void sizeTest()
{
	printf("size: %d ", size());

	addBack(1, 1);
	addFirst(2);
	addLast(3);
	removeFirst();
	addFront(4, 2);
	addFirst(5);
	removeLast();
	addLast(6);
	addLast(7);
	addLast(8);
	remove1(3);
	print();
	printf("%d ", size());
	tearDown();
}

void getTest()
{
	getTestNodes();

	printf("get: %d ", get(-1));
	printf("%d ", get(0));
	printf("%d ", get(1));
	printf("%d ", get(2));
	printf("%d ", get(3));
	printf("%d ", get(4));
	printf("%d ", get(5));
	tearDown();
}

void indexOfTest()
{
	getTestNodes();

	printf("index of: %d ", indexOf(1));
	printf("%d ", indexOf(2));
	printf("%d ", indexOf(3));
	printf("%d ", indexOf(4));
	printf("%d ", indexOf(5));
	printf("%d ", indexOf(6));
	tearDown();
}



/* main function */
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
}
