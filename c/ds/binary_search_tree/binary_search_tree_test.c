
void run_all_tests()
{
	test_insert_tree();
	test_get_node_count();
	test_is_in_tree();
	test_get_height();
	test_get_min_and_max();
	test_is_binary_search_tree();
	test_delete_tree();
	test_get_successor();
}

void test_insert_tree()
{
	node* root = NULL;
	root = insert_tree(root, 4);
	root = insert_tree(root, 12);
	root = insert_tree(root, 3);
	root = insert_tree(root, 11);
	root = insert_tree(root, 16);
	
	// print_tree(root);

	destroy_tree(root);
}

void test_get_node_count()
{
	node* root = NULL;
	root = insert_tree(root, 4);
	root = insert_tree(root, 12);
	root = insert_tree(root, 3);
	root = insert_tree(root, 11);
	root = insert_tree(root, 16);

	assert(get_node_count(root) == 5);

	destroy_tree(root);
}

void test_is_in_tree()
{
	node* root = NULL;
	root = insert_tree(root, 4);
	root = insert_tree(root, 12);
	root = insert_tree(root, 3);
	root = insert_tree(root, 11);
	root = insert_tree(root, 16);

	assert(is_in_tree(root, 4) == true);
	assert(is_in_tree(root, 12) == true);
	assert(is_in_tree(root, 3) == true);
	assert(is_in_tree(root, 11) == true);
	assert(is_in_tree(root, 16) == true);
	assert(is_in_tree(root, 1) == false);

	destroy_tree(root);
}

void test_get_height()
{
	node* root = NULL;
	root = insert_tree(root, 4);
	root = insert_tree(root, 12);
	root = insert_tree(root, 3);
	root = insert_tree(root, 11);
	root = insert_tree(root, 16);

	assert(get_height(root) == 3);

	destroy_tree(root);
}

void test_get_min_and_max()
{
	node* root = NULL;
	root = insert_tree(root, 4);
	root = insert_tree(root, 12);
	root = insert_tree(root, 3);
	root = insert_tree(root, 11);
	root = insert_tree(root, 16);

	assert(get_min(root) == 3);
	assert(get_max(root) == 16);

	destroy_tree(root);
}

void test_is_binary_search_tree()
{
	node* root = NULL;
	root = insert_tree(root, 4);
	root = insert_tree(root, 12);
	root = insert_tree(root, 3);
	root = insert_tree(root, 11);
	root = insert_tree(root, 16);
	assert(is_binary_search_tree(root) == true);

	node* bad_root = malloc(sizeof(node));
	bad_root->val = 10;
	bad_root->left = NULL;
	bad_root->right = malloc(sizeof(node));
	bad_root->right->val = 9;
	bad_root->right->left = NULL;
	bad_root->right->right = NULL;
	assert(is_binary_search_tree(bad_root) == false);

	destroy_tree(root);
	destroy_tree(bad_root);
}

void test_delete_tree()
{
	node* root = NULL;
	root = insert_tree(root, 5);
	root = insert_tree(root, 12);
	root = insert_tree(root, 11);
	root = insert_tree(root, 16);
	root = insert_tree(root, 3);
	root = insert_tree(root, 2);
	root = insert_tree(root, 4);
	// print_tree(root);
	
	//printf("\nDelete 5 - ");
	root = delete_tree(root, root->val);
	assert(root->val == 11);
	// print_tree(root);
	
	//printf("\nDelete 11 - ");
	root = delete_tree(root, root->val);
	assert(root->val == 12);
	// print_tree(root);
	
	//printf("\nDelete 12 - ");
	root = delete_tree(root, root->val);
	assert(root->val == 16);
	// print_tree(root);
	
	//printf("\nDelete 16 - ");
	root = delete_tree(root, root->val);
	assert(root->val == 3);
	// print_tree(root);
	
	//printf("\nDelete 3 - ");
	root = delete_tree(root, root->val);
	assert(root->val == 4);
	// print_tree(root);

	//printf("\nDelete 4 - ");
	root = delete_tree(root, root->val);
	assert(root->val == 2);
	// print_tree(root);
	
	//printf("\nDelete 2 - ");
	root = delete_tree(root, root->val);
	assert(root == NULL);
	// print_tree(root);

	destroy_tree(root);
}

void test_get_successor()
{
	node* root = NULL;
	root = insert_tree(root, 11);
	root = insert_tree(root, 12);
	root = insert_tree(root, 16);
	root = insert_tree(root, 32);
	root = insert_tree(root, 3);
	root = insert_tree(root, 2);
	root = insert_tree(root, 5);
	root = insert_tree(root, 4);

	assert(get_successor(root, 2) == 3);
	assert(get_successor(root, 3) == 4);
	assert(get_successor(root, 4) == 5);
	assert(get_successor(root, 5) == 11);
	assert(get_successor(root, 11) == 12);
	assert(get_successor(root, 12) == 16);
	assert(get_successor(root, 16) == 32);
	assert(get_successor(root, 32) == -1);

	// printf("%d\n", get_successor(root, 32));

	destroy_tree(root);
}


