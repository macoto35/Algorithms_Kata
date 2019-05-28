#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef PROJECT_QUEUE_ARRAY
#define PROJECT_QUEUE_ARRAY

const int capacity = 6;

typedef struct {
	int read;
	int write;
	int data[6];
} queue;

queue* create_queue();
void check_memory(void* ptr);
bool empty(queue* q);
void enqueue(queue* q, int val);
bool full(queue* q);
void destroy(queue* q);
int dequeue(queue* q);
void print_debug(queue* q);

#endif
