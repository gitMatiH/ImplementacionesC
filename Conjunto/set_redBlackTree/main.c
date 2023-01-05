// gcc -o test rbtree.c main.c

#include <stdio.h>
#include <stdlib.h>

#include "rbtree.h"

int main(int argc, char** argv) {
  rbtree_t* tree = rbtree_create();

  rbtree_insert(tree, 10, "ten");
  rbtree_insert(tree, 20, "twenty");
  rbtree_insert(tree, 30, "thirty");
  rbtree_insert(tree, 40, "fourty");
  rbtree_insert(tree, 50, "fifty");
  rbtree_insert(tree, 25, "twenty-five");

  rbtree_node_t* node = rbtree_find(tree, 30);
  printf("%s\n", (char*)node->value);  // thirty

  node = rbtree_find_min(tree);
  printf("%s\n", (char*)node->value);  // ten

  node = rbtree_find_max(tree);
  printf("%s\n", (char*)node->value);  // fifty

  rbtree_remove(tree, node);
  node = rbtree_find_max(tree);
  printf("%s\n", (char*)node->value);  // forty

  rbtree_destroy(tree);

  return 0;
}
