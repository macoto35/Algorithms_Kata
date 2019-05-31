
tree_node* getNode(char val)
{
	tree_node* node = malloc(sizeof(tree_node));
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	
	return node;
}

void destruct_tree(tree_node* root)
{
	if (root == NULL)
		return;

	destruct_tree(root->left);
	destruct_tree(root->right);

	free(root);
}

void preOrderDFS(tree_node* root)
{
	if (root == NULL)
		return;
	
	printf("%c ", root->val);
	preOrderDFS(root->left);
	preOrderDFS(root->right);
}

void postOrderDFS(tree_node* root)
{
	if (root == NULL)
		return;
	
	postOrderDFS(root->left);
	postOrderDFS(root->right);
	printf("%c ", root->val);
}

void inOrderDFS(tree_node* root)
{
	if (root == NULL)
		return;
	
	inOrderDFS(root->left);
	printf("%c ", root->val);
	inOrderDFS(root->right);
}

void BFS(tree_node* root)
{
	tree_node** arr = malloc(sizeof(tree_node) * 10);
	int r = 0, w = 0;

	arr[w++] = root;

	while (r != w) {
		tree_node* node = arr[r++];
		printf("%c ", node->val);

		if (node->left != NULL)
			arr[w++] = node->left;
		
		if (node->right != NULL)
			arr[w++] = node->right;
	}

	free(arr);
}

