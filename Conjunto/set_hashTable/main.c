//gcc set.c main.c -o set_test
#include "set.h"
#include <stdio.h>

int main(int argc, char **argv) {
  set *s = set_create();

  set_add(s, "element1");
  set_add(s, "element2");
  set_add(s, "element3");

  printf("set contains element1: %d\n", set_contains(s, "element1"));
  printf("set contains element2: %d\n", set_contains(s, "element2"));
  printf("set contains element3: %d\n", set_contains(s, "element3"));
  printf("set contains element4: %d\n", set_contains(s, "element4"));

  set_remove(s, "element2");
  printf("set contains element2: %d\n", set_contains(s, "element2"));

  set_clear(s);
  printf("set is empty: %d\n", set_is_empty(s));

  set_destroy(s);

  return 0;
}
