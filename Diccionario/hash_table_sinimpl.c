#include "hash_table.h"

#include <stdlib.h>
#include <string.h>

struct hash_table_entry {
  char *key;
  void *value;
  hash_table_entry *next;
};

struct hash_table {
  int size;
  int num_entries;
  hash_table_entry **entries;
};

unsigned int hash(char *key) {
  unsigned int hash = 5381;
  int c;
  while ((c = *key++)) {
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
  }
  return hash;
}

hash_table *hash_table_create(int size) {
  hash_table *table = malloc(sizeof(hash_table));
  table->size = size;
  table->num_entries = 0;
  table->entries = malloc(size * sizeof(hash_table_entry *));
  memset(table->entries, 0, size * sizeof(hash_table_entry *));
  return table;
}

void hash_table_set(hash_table *table, char *key, void *value) {
  // ...
}

void *hash_table_get(hash_table *table, char *key) {
  // ...
}

void hash_table_remove(hash_table *table, char *key) {
  // ...
}

void hash_table_destroy(hash_table *table) {
  // ...
}
