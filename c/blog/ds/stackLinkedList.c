#include <stdio.h>
#define NOT_FOUND -1
typedef struct Node Node;

struct Node {
	int data;
	Node* next;
};

Node* head = NULL;

void print()
{
	Node* tmp = head;
	while(tmp != NULL) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

// addFirst
void push(int data)
{
	Node* node = (Node*) malloc(sizeof(Node));
	node->data = data;
	node->next = head;

	head = node;
}

int empty()
{
	return head == NULL;
}

// removeFirst
int pop()
{
	if (empty()) {
		return NOT_FOUND;
	} else {
		Node* del = head;
		int result = del->data;
		Node* newHead = del->next;

		head = newHead;

		free(del);

		return result;
	}
}

int peek()
{
	if (empty())
		return NOT_FOUND;
	return head->data;
}

int search(int data)
{
	Node* tmp = head;
	int idx = 0;

	while(tmp != NULL) {
		if (data == tmp->data)
			return idx;
		idx++;
		tmp = tmp->next;
	}

	return NOT_FOUND;
}

void main()
{
	printf("[before] empty? %s\n", (empty() ? "true" : " false"));

	for (int i = 1; i < 6; i++) {
		push(i);
		printf("%d, peek? %d\n", i, peek());
	}
	for (int i = 1; i < 6; i++)
		printf("%d, search? %d\n", i, search(i));
	printf("after push: ");
	print();
	
	printf("empty? %s\n", (empty() ? "true" : " false"));

	for (int i = 1; i < 6; i++)
		printf("pop: %d ", pop());
	
	printf("\n[blank] pop? %d, peek? %d, search? %d\n", pop(), peek(), search(0));
}
