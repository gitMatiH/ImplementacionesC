#define HASH_TABLE_SIZE 1000

typedef struct {
  char *key;
  void *value;
} hash_table_entry;

typedef struct {
  hash_table_entry entries[HASH_TABLE_SIZE];
} hash_table;

unsigned int hash(char *key) {
  unsigned int hash = 5381;
  int c;
  while ((c = *key++)) {
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
  }
  return hash % HASH_TABLE_SIZE;
}

void hash_table_set(hash_table *table, char *key, void *value) {
  unsigned int hash_value = hash(key);
  table->entries[hash_value].key = key;
  table->entries[hash_value].value = value;
}

void *hash_table_get(hash_table *table, char *key) {
  unsigned int hash_value = hash(key);
  return table->entries[hash_value].value;
}
