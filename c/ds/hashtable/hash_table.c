
hash_table* create_table(int size)
{
	hash_table* table = malloc(sizeof(hash_table));
	assert(table != 0);

	table->data = malloc(sizeof(key_value) * size);
	assert(table->data != 0);
	for (int i = 0; i < size; i++)
		table->data[i] = NULL;

	table->size = size;

	return table;
}

bool exists(hash_table* table, char* key)
{
	int idx = hash(key, table->size);

	key_value* current = table->data[idx];
	while (current) {
		if (strcmp(current->key, key) == 0)
			return true;
		current = current->next;
	}
	return false;
}

int hash(char* key, int m)
{
	int hash = 0;
	int x = 31;

	for (int i = 0; i < key[i] != '\0'; i++)
		hash = hash * x + key[i];

	return abs(hash % m);
}

void add(hash_table* table, char* key, key_value* object)
{
	int idx = hash(key, table->size);

	key_value* kv = malloc(sizeof(key_value));
	kv->key = strdup(object->key);
	kv->value = strdup(object->value);
	kv->next = NULL;
	
	if (table->data[idx] == NULL) {
		table->data[idx] = kv;
		return;
	}

	key_value* current = table->data[idx];
	key_value* prev = NULL;
	while (current) {
		if (strcmp(current->key, key) == 0) {
			current->value = strdup(object->value);
			return;
		}

		prev = current;
		current = current->next;
	}
	prev->next = kv;
}

void destroy_table(hash_table* table)
{
	for (int i = 0; i < table->size; i++) {
		if (table->data[i]) {
			key_value* current = table->data[i];
			while (current) {
				free(current->key);
				free(current->value);

				key_value* del = current;
				current = current->next;
				free(del);
			}
		}
	}

	free(table->data);
	free(table);
}

void print_debug(hash_table* table)
{
	for (int i = 0; i < table->size; i++) {
		if (table->data[i] == NULL) {
			printf("%d: \n", i);
		} else {
			key_value* current = table->data[i];
			
			while (current) {
				printf("%s: %s ->", current->key, current->value);
				current = current->next;
			}
			printf("\n");
		}
	}
	printf("=============================\n");
}

char* get(hash_table* table, char* key)
{
	int idx = hash(key, table->size);
	key_value* current = table->data[idx];

	while (current) {
		if (strcmp(current->key, key) == 0)
			return current->value;
		current = current->next;
	}

	return NULL;
}

void delete(hash_table* table, char* key)
{
	int idx = hash(key, table->size);

	key_value* prev = NULL;
	key_value* current = table->data[idx];

	while(current) {
		if (strcmp(current->key, key) == 0) {
			key_value* del = current;

			free(del->key);
			free(del->value);

			if (prev == NULL)
				table->data[idx] = del->next;
			else
				prev->next = del->next;
			
			free(del);
			break;
		}
		prev = current;
		current = current->next;
	}
}

