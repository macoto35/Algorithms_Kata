
node* insert_tree(node* in_node, int val)
{
	if (in_node == NULL) {
		node* new = malloc(sizeof(node));
		new->val = val;
		new->left = NULL;
		new->right = NULL;
		
		return new;
	}

	if (val < in_node->val)
		in_node->left = insert_tree(in_node->left, val);
	else
		in_node->right = insert_tree(in_node->right, val);
	
	return in_node;
}

void print_tree(node* in_node)
{
	if (in_node == NULL)
		return;

	print_tree(in_node->left);
	printf("%d ", in_node->val);
	print_tree(in_node->right);
}

void destroy_tree(node* in_node)
{
	if (in_node == NULL)
		return;

	destroy_tree(in_node->left);
	destroy_tree(in_node->right);
	free(in_node);
}

int get_node_count(node* in_node)
{
	if (in_node == NULL)
		return 0;
	return 1 + get_node_count(in_node->left) + get_node_count(in_node->right);
}

bool is_in_tree(node* in_node, int val)
{
	if (in_node == NULL)
		return false;

	if (val == in_node->val)
		return true;
	else if (val < in_node->val)
		return is_in_tree(in_node->left, val);
	else
		return is_in_tree(in_node->right, val);
}

int get_height(node* in_node)
{
	if (in_node == NULL)
		return 0;

	return 1 + max(get_height(in_node->left), get_height(in_node->right));
}

int get_min(node* in_node)
{
	// Left most
	if (in_node == NULL)
		return 0;

	node* current = in_node;
	while (current->left != NULL)
		current = current->left;

	return current->val;
}

int get_max(node* in_node)
{
	// right most
	if (in_node == NULL)
		return 0;

	node* current = in_node;
	while (current->right != NULL)
		current = current->right;

	return current->val;
}

bool is_binary_search_tree(node* in_node)
{
	if (in_node == NULL)
		return true;
	return is_between(in_node, INT_MIN, INT_MAX);
}

bool is_between(node* in_node, int min, int max)
{
	if (in_node == NULL)
		return true;
	return in_node->val > min &&
	       in_node->val < max &&
	       is_between(in_node->left, min, in_node->val) &&
	       is_between(in_node->right, in_node->val, max);
}

node* delete_tree(node* in_node, int val)
{
	if (in_node == NULL)
		return in_node;

	if (val < in_node->val) {
		in_node->left = delete_tree(in_node->left, val);
	} else if (val > in_node->val) {
		in_node->right = delete_tree(in_node->right, val);
	} else {
		if (in_node->left == NULL && in_node->right == NULL) {
			free(in_node);
			in_node = NULL;
		} else if (in_node->left == NULL) {
			node* tmp = in_node;
			in_node = in_node->right;
			free(tmp);
		} else if (in_node->right == NULL) {
			node* tmp = in_node;
			in_node = in_node->left;
			free(tmp);
		} else {
			int min = get_min(in_node->right);
			in_node->val = min;
			in_node->right = delete_tree(in_node->right, min);
		}
	}

	return in_node;
}

int get_successor(node* in_node, int val)
{
	if (in_node == NULL)
		return -1;

	node* target = in_node;

	while (target->val != val) {
		if (val < target->val)
			target = target->left;
		else
			target = target->right;
	}

	if (target->right != NULL) {
		return get_min(target->right);	
	} else {
		node* successor = NULL;
		node* ancestor = in_node;
		
		while (val != ancestor->val) {
			if (val < ancestor->val) {
				successor = ancestor;
				ancestor = ancestor->left;
			} else {
				ancestor = ancestor->right;
			}
		}

		return successor ? successor->val : -1;
	}
}


