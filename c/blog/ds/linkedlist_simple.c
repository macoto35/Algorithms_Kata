#include <stdio.h>

typedef struct Node Node;

struct Node {
	int data;
	Node* next;
};

void main() {
	Node a, b;
	a.data = 1;
	b.data = 2;
	a.next = &b;
	printf("a = %d, b = %d\n", a.data, a.next->data);

	Node* ap = (struct Node*) malloc(sizeof(struct Node));
	Node* bp = (struct Node*) malloc(sizeof(struct Node));
	ap->data = 3;
	bp->data = 4;
	ap->next = bp;
	printf("ap = %d, bp = %d\n", ap->data, ap->next->data);

	free(ap);
	free(bp);

}
