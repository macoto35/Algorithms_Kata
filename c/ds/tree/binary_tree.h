#include <stdio.h>
#include <stdlib.h>

#ifndef PROJECT_BINARY_TREE
#define PROJECT_BINARY_TREE

typedef struct TreeNode {
	char val;
	struct TreeNode* left;
	struct TreeNode* right;
} tree_node;

tree_node* getNode(char val);
void destruct_tree(tree_node* root);
void preOrderDFS(tree_node* root);
void postOrderDFS(tree_node* root);
void inOrderDFS(tree_node* root);
void BFS(tree_node* root);

#endif
