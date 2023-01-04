#include <stdlib.h>
#include "rbtree.h"

struct rbtree {
  // implementation details go here
  int key;
  int value;
  int color;  // 0 for red, 1 for black
  RBTree* left;
  RBTree* right;
  RBTree* parent;
};

RBTree* rbtree_create(void) {
  RBTree* tree = malloc(sizeof(RBTree));
  if (tree == NULL) {
    return NULL;
  }

  tree->root = NULL;

  return tree;
}

