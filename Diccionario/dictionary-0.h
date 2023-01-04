#define MAX_ENTRIES 1000

typedef struct {
  char *key;
  void *value;
} dictionary_entry;

typedef struct {
  dictionary_entry entries[MAX_ENTRIES];
  int num_entries;
} dictionary;

void dictionary_init(dictionary *dict) {
  dict->num_entries = 0;
}

int dictionary_set(dictionary *dict, char *key, void *value) {
  if (dict->num_entries == MAX_ENTRIES) {
    return 0; // failed to set value
  }

  dict->entries[dict->num_entries].key = key;
  dict->entries[dict->num_entries].value = value;
  dict->num_entries++;
  return 1; // success
}

void *dictionary_get(dictionary *dict, char *key) {
  for (int i = 0; i < dict->num_entries; i++) {
    if (strcmp(dict->entries[i].key, key) == 0) {
      return dict->entries[i].value;
    }
  }
  return NULL; // key not found
}

void dictionary_remove(dictionary *dict, char *key) {
  for (int i = 0; i < dict->num_entries; i++) {
    if (strcmp(dict->entries[i].key, key) == 0) {
      dict->entries[i] = dict->entries[dict->num_entries - 1];
      dict->num_entries--;
      return;
    }
  }
}
