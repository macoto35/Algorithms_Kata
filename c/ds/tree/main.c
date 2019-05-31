#include "binary_tree.h"
#include "binary_tree.c"

int main(int argc, char* argv[])
{
	tree_node* root = getNode('A');
	tree_node* left = root->left = getNode('B');
	tree_node* right = root->right = getNode('C');
	left->left = getNode('D');
	left->right = getNode('E');
	right->left = getNode('F');
	right->right = getNode('G');

	printf("pre order Depth First Search: ");
	preOrderDFS(root);

	printf("\npost order Depth First Search: ");
	postOrderDFS(root);
	
	printf("\nin order Depth First Search: ");
	inOrderDFS(root);

	printf("\nBreadth First Search: ");
	BFS(root);

	destruct_tree(root);
	
	return EXIT_SUCCESS;
}
