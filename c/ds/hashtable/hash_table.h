#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#ifndef PROJECT_HASH_TABLE
#define PROJECT_HASH_TABLE

const int tableSize = 10;

typedef struct KeyValue {
	char* key;
	char* value;
	struct KeyValue* next;
} key_value;

typedef struct HashTable {
	key_value** data;
	int size;
} hash_table;

hash_table* create_table(int size);
bool exists(hash_table* table, char* key);
int hash(char* key, int m);
void add(hash_table* table, char* key, key_value* object);
void destroy_table(hash_table* table);
void print_debug(hash_table* table);
char* get(hash_table* table, char* key);
void delete(hash_table* table, char* key);

#endif
