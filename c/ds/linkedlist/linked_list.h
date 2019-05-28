#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef PROJECT_LINKED_LIST_H
#define PROJECT_LINKED_LIST_H

typedef struct Node {
	int val;
	struct Node *next;
} node;

int size(node* head);
void check_address(void* node);
void destroy_list(node* head);
void push_front(node** head, int val);
bool empty(node* head);
int value_at(node* head, int idx);
int pop_front(node** head);
void push_back(node** head, int val);
int pop_back(node** head);
int front(node* head);
int back(node* head);
void insert(node** head, int idx, int val);
void erase(node** head, int idx);
int value_n_from_end(node* head, int idx);
void reverse(node** head);
void remove_value(node** head, int val);

#endif
