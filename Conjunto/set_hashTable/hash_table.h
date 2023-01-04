#ifndef HASH_TABLE_H
#define HASH_TABLE_H

typedef struct hash_table_entry hash_table_entry;
typedef struct hash_table hash_table;

hash_table *hash_table_create(int size);
void hash_table_set(hash_table *table, char *key, void *value);
void *hash_table_get(hash_table *table, char *key);
void hash_table_remove(hash_table *table, char *key);
void hash_table_destroy(hash_table *table);

int hash_table_get_num_entries(hash_table *table);
void hash_table_clear(hash_table *table);

#endif
