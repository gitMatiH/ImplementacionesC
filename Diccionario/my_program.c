//gcc -o my_program my_program.c hash_table.c
#include "hash_table.h"
#include <stdio.h>

int main(int argc, char **argv) {
  hash_table *table = hash_table_create(10);

  hash_table_set(table, "key1", "value1");
  hash_table_set(table, "key2", "value2");
  hash_table_set(table, "key3", "value3");

  printf("%s\n", (char *) hash_table_get(table, "key1"));
  printf("%s\n", (char *) hash_table_get(table, "key2"));
  printf("%s\n", (char *) hash_table_get(table, "key3"));
  printf("%s\n", (char *) hash_table_get(table, "key4"));

  hash_table_remove(table, "key2");
  printf("%s\n", (char *) hash_table_get(table, "key2"));

  hash_table_destroy(table);

  return 0;
}
