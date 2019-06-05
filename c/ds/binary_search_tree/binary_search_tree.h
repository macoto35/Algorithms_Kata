#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#ifndef PROJECT_BINARY_SEARCH_TREE
#define PROJECT_BINARY_SEARCH_TREE

typedef struct Node {
	int val;
	struct Node* left;
	struct Node* right;
} node;

node* insert_tree(node* in_node, int val);
void print_tree(node* in_node);
void destroy_tree(node* in_node);
int get_node_count(node* in_node);
bool is_in_tree(node* in_node, int val);
int get_height(node* in_node);
int get_min(node* in_node);
int get_max(node* in_node);
bool is_binary_search_tree(node* in_node);
bool is_between(node* in_node, int min, int max);
node* delete_tree(node* in_node, int val);
int get_successor(node* in_node, int val);

#endif
