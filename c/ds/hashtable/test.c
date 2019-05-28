
void run_all_tests()
{
	test_exists();
	test_add_get();
	test_add_remove();
}

void test_exists()
{
	hash_table* table = create_table(tableSize);

	assert(exists(table, "Texas") == false);

	key_value tx = {"Texas", "Austin"};
	add(table, "Texas", &tx);

	assert(exists(table, "Texas") == true);

	destroy_table(table);
}

void test_add_get()
{
	hash_table* table = create_table(tableSize);

	key_value kv1 = {"Texas", "Austin"};
	add(table, "Texas", &kv1);
	assert(strcmp(get(table, "Texas"), "Austin") == 0);

	key_value kv2 = {"C", "same key"};
	add(table, "C", &kv2);
	assert(strcmp(get(table, "C"), "same key") == 0);

	key_value kv3 = {"Louisiana", "Baton Rouge"};
	add(table, "Louisiana", &kv3);
	assert(strcmp(get(table, "Louisiana"), "Baton Rouge") == 0);

	key_value kv4 = {"Maine", "Augusta"};
	add(table, "Maine", &kv4);
	assert(strcmp(get(table, "Maine"), "Augusta") == 0);
	
	key_value kv5 = {"Louisiana", "New Orleans"};
	add(table, "Louisiana", &kv5);
	assert(strcmp(get(table, "Louisiana"), "New Orleans") == 0);
	
	// print_debug(table);
	destroy_table(table);
}

void test_add_remove()
{
	hash_table* table = create_table(tableSize);

	key_value kv1 = {"California", "Sacramento"};
	add(table, "California", &kv1);
	assert(exists(table, "California") == true);

	delete(table, "California");
	assert(exists(table, "California") == false);

	// print_debug(table);
	destroy_table(table);
}

