#include "set.h"
#include "hash_table.h"
#include <stdlib.h>

struct set {
  hash_table *table;
};

set *set_create(void) {
  set *s = malloc(sizeof(set));
  s->table = hash_table_create(10);
  return s;
}

void set_add(set *s, void *element) {
  hash_table_set(s->table, element, element);
}

void set_remove(set *s, void *element) {
  hash_table_remove(s->table, element);
}

int set_contains(set *s, void *element) {
  return hash_table_get(s->table, element) != NULL;
}

int set_is_empty(set *s) {
  return hash_table_get_num_entries(s->table) == 0;
}

void set_clear(set *s) {
  hash_table_clear(s->table);
}

void set_destroy(set *s) {
  hash_table_destroy(s->table);
  free(s);
}
