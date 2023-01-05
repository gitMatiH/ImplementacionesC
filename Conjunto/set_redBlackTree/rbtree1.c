#include <stdlib.h>
#include "rbtree.h"

struct rbtree {
  // implementation details go here
};

RBTree* rbtree_create(void) {
  RBTree* tree = malloc(sizeof(RBTree));
  if (tree == NULL) {
    return NULL;
  }

  tree->root = NULL;

  return tree;
}


void rbtree_destroy_helper(RBTree* node) {
  if (node == NULL) return;

  rbtree_destroy_helper(node->left);
  rbtree_destroy_helper(node->right);
  free(node);
}

void rbtree_destroy(RBTree* tree) {
  rbtree_destroy_helper(tree->root);
  free(tree);
}

RBTree* rbtree_find_node(RBTree* tree, int key) {
  RBTree* node = tree->root;
  while (node != NULL) {
    if (key == node->key) {
      return node;
    } else if (key < node->key) {
      node = node->left;
    } else {
      node = node->right;
    }
  }
  return NULL;
}

int rbtree_remove(RBTree* tree, int key) {
  RBTree* node = rbtree_find_node(tree, key);
  if (node == NULL) {
    return -1;  // key not found
  }

  // implementation of the remove operation goes here

  return 0;
}

#include "rbtree.h"

RBTree* rbtree_find_node(RBTree* tree, int key) {
  RBTree* node = tree->root;
  while (node != NULL) {
    if (key == node->key) {
      return node;
    } else if (key < node->key) {
      node = node->left;
    } else {
      node = node->right;
    }
  }
  return NULL;
}

int rbtree_get(RBTree* tree, int key) {
  RBTree* node = rbtree_find_node(tree, key);
  if (node == NULL) {
    return -1;  // key not found
  }
  return node->value;
}


/*
In order to implement a red-black tree, you will need to implement the following functions:

rbtree_insert: This function is responsible for inserting a new element into the tree and maintaining its red-black properties. It will involve creating a new node, inserting it into the tree in the correct position, and possibly rotating and coloring nodes to maintain the red-black properties of the tree.

rbtree_remove: This function is responsible for removing an element from the tree and maintaining its red-black properties. It will involve finding the node to be removed, unlink it from the tree, and possibly rotating and coloring nodes to maintain the red-black properties of the tree.

rbtree_find_node: This function is a helper function that is used by rbtree_get and rbtree_remove to locate the node with the specified key in the tree. It will involve traversing the tree and comparing the keys of the nodes until the node with the specified key is found, or NULL is returned if the node is not found.

rbtree_get: This function returns the value of the element with the specified key in the tree. It uses the rbtree_find_node function to locate the node with the specified key, and returns its value if the node is found.

rbtree_destroy: This function destroys the tree by freeing all of its nodes and the tree itself. It will involve writing a helper function that traverses the tree in a pre-order fashion and frees each node.

I hope this helps! Let me know if you have any questions.
*/

