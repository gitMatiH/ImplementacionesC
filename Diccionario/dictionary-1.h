#define HASH_TABLE_SIZE 1000

typedef struct {
  char *key;
  void *value;
  struct dictionary_entry *next;
} dictionary_entry;

typedef struct {
  dictionary_entry *entries[HASH_TABLE_SIZE];
} dictionary;

unsigned int hash(char *key) {
  unsigned int hash = 5381;
  int c;
  while ((c = *key++)) {
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
  }
  return hash % HASH_TABLE_SIZE;
}

void dictionary_init(dictionary *dict) {
  memset(dict->entries, 0, sizeof(dict->entries));
}

int dictionary_set(dictionary *dict, char *key, void *value) {
  unsigned int hash_value = hash(key);
  dictionary_entry *entry = dict->entries[hash_value];
  while (entry != NULL) {
    if (strcmp(entry->key, key) == 0) {
      entry->value = value;
      return 1; // success
    }
    entry = entry->next;
  }

  // key not found, add a new entry
  dictionary_entry *new_entry = malloc(sizeof(dictionary_entry));
  new_entry->key = key;
  new_entry->value = value;
  new_entry->next = dict->entries[hash_value];
  dict->entries[hash_value] = new_entry;
  return 1; // success
}

void *dictionary_get(dictionary *dict, char *key) {
  unsigned int hash_value = hash(key);
  dictionary_entry *entry = dict->entries[hash_value];
  while (entry != NULL) {
    if (strcmp(entry->key, key) == 0) {
      return entry->value;
    }
    entry = entry->next;
  }
  return NULL; // key not found
}

void dictionary_remove(dictionary *dict, char *key) {
  unsigned int hash_value = hash(key);
  dictionary_entry *entry = dict->entries[hash_value];
  dictionary_entry *prev = NULL;
  while (entry != NULL) {
    if (strcmp(entry->key, key) == 0) {
      if (prev == NULL) {
        dict->entries[hash_value] = entry->next;
      } else {
        prev->next = entry->next;
      }
      free(entry);
      return;
    }
    prev = entry;
    entry = entry->next;
  }
}
