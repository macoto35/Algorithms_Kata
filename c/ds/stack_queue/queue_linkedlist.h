#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef PROJECT_QUEUE_LINKEDLIST
#define PROJECT_QUEUE_LINKEDLIST

typedef struct Node {
	int val;
	struct Node* next;
} node;

typedef struct {
	node* head;
	node* tail;
} queue;

queue* create_queue();
void check_address(void* ptr);
bool empty(queue* q);
void destroy_queue(queue* q);
void enqueue(queue* q, int val);
int dequeue(queue* q);
void print_debug(queue* q);

#endif
