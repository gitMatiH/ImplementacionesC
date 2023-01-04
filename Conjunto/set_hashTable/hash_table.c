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
  unsigned int hash_value = hash(key) % table->size;
  hash_table_entry *entry = table->entries[hash_value];
  while (entry != NULL) {
    if (strcmp(entry->key, key) == 0) {
      entry->value = value;
      return;
    }
    entry = entry->next;
  }

  // key not found, add a new entry
  hash_table_entry *new_entry = malloc(sizeof(hash_table_entry));
  new_entry->key = key;
  new_entry->value = value;
  new_entry->next = table->entries[hash_value];
  table->entries[hash_value] = new_entry;
  table->num_entries++;

  // check if we need to resize the table
  if (table->num_entries > table->size * 0.75) {
    // resize the table
    int new_size = table->size * 2;
    hash_table_entry **new_entries = malloc(new_size * sizeof(hash_table_entry *));
    memset(new_entries, 0, new_size * sizeof(hash_table_entry *));
    for (int i = 0; i < table->size; i++) {
      hash_table_entry *entry = table->entries[i];
      while (entry != NULL) {
        hash_table_entry *next = entry->next;
        unsigned int new_hash_value = hash(entry->key) % new_size;
        entry->next = new_entries[new_hash_value];
        new_entries[new_hash_value] = entry;
        entry = next;
      }
    }
    free(table->entries);
    table->entries = new_entries;
    table->size = new_size;
  }
}

void *hash_table_get(hash_table *table, char *key) {
  unsigned int hash_value = hash(key) % table->size;
  hash_table_entry *entry = table->entries[hash_value];
  while (entry != NULL) {
    if (strcmp(entry->key, key) == 0) {
      return entry->value;
    }
    entry = entry->next;
  }
  return NULL; // key not found
}

void hash_table_remove(hash_table *table, char *key) {
  unsigned int hash_value = hash(key) % table->size;
  hash_table_entry *entry = table->entries[hash_value];
  hash_table_entry *prev = NULL;
  while (entry != NULL) {
    if (strcmp(entry->key, key) == 0) {
      if (prev == NULL) {
        // first element in the linked list
        table->entries[hash_value] = entry->next;
      } else {
        prev->next = entry->next;
      }
      free(entry);
      table->num_entries--;
      return;
    }
    prev = entry;
    entry = entry->next;
  }
}

void hash_table_destroy(hash_table *table) {
  for (int i = 0; i < table->size; i++) {
    hash_table_entry *entry = table->entries[i];
    while (entry != NULL) {
      hash_table_entry *next = entry->next;
      free(entry);
      entry = next;
    }
  }
  free(table->entries);
  free(table);
}

int hash_table_get_num_entries(hash_table *table) {
  return table->num_entries;
}

void hash_table_clear(hash_table *table) {
  for (int i = 0; i < table->size; i++) {
    hash_table_entry *entry = table->entries[i];
    while (entry != NULL) {
      hash_table_entry *next_entry = entry->next;
      free(entry);
      entry = next_entry;
    }
    table->entries[i] = NULL;
  }
  table->num_entries = 0;
}

