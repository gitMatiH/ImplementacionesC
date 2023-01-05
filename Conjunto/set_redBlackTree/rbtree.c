#include <stdlib.h>

#include "rbtree.h"

struct rbtree_node {
  int key;
  void* value;
  int is_red;
  rbtree_node_t* left;
  rbtree_node_t* right;
  rbtree_node_t* parent;
};

struct rbtree {
  rbtree_node_t* root;
};

rbtree_t* rbtree_create() {
  rbtree_t* tree = malloc(sizeof(rbtree_t));
  tree->root = NULL;
  return tree;
}

void rbtree_destroy(rbtree_t* tree) {
  if (tree->root) {
    rbtree_node_t* node = rbtree_find_min(tree);
    while (node) {
      rbtree_remove(tree, node);
      node = rbtree_find_min(tree);
    }
  }
  free(tree);
}

static void rbtree_rotate_left(rbtree_t* tree, rbtree_node_t* node) {
  rbtree_node_t* right = node->right;
  node->right = right->left;
  if (right->left) {
    right->left->parent = node;
  }
  right->parent = node->parent;
  if (!node->parent) {
    tree->root = right;
  } else if (node == node->parent->left) {
    node->parent->left = right;
  } else {
    node->parent->right = right;
  }
  right->left = node;
  node->parent = right;
}

static void rbtree_rotate_right(rbtree_t* tree, rbtree_node_t* node) {
  rbtree_node_t* left = node->left;
  node->left = left->right;
  if (left->right) {
    left->right->parent = node;
  }
  left->parent = node->parent;
  if (!node->parent) {
    tree->root = left;
  } else if (node == node->parent->left) {
    node->parent->left = left;
  } else {
    node->parent->right = left;
  }
  left->right = node;
  node->parent = left;
}

int rbtree_insert(rbtree_t* tree, rbtree_node_t* node) {
  rbtree_node_t* current = tree->root;
  rbtree_node_t* parent = NULL;
  while (current) {
    parent = current;
    if (node->key < current->key) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
  node->parent = parent;
  if (!parent) {
    tree->root = node;
  } else if (node->key < parent->key) {
    parent->left = node;
  } else {
    parent->right = node;
  }
  node->left = NULL;
  node->right = NULL;
  node->is_red = 1;
  rbtree_fixup_insert(tree, node);
  return 0;
}

rbtree_node_t* rbtree_find(rbtree_t* tree, int key) {
  return rbtree_find_node(tree, key);
}

static void rbtree_fixup_insert(rbtree_t* tree, rbtree_node_t* node) {
  rbtree_node_t* current = node;
  while (current->parent && current->parent->is_red) {
    rbtree_node_t* grandparent = current->parent->parent;
    if (current->parent == grandparent->left) {
      rbtree_node_t* uncle = grandparent->right;
      if (uncle && uncle->is_red) {
        /* Case 1: uncle is red */
        current->parent->is_red = 0;
        uncle->is_red = 0;
        grandparent->is_red = 1;
        current = grandparent;
      } else {
        if (current == current->parent->right) {
          /* Case 2: uncle is black, current is right child */
          current = current->parent;
          rbtree_rotate_left(tree, current);
        }
        /* Case 3: uncle is black, current is left child */
        current->parent->is_red = 0;
        grandparent->is_red = 1;
        rbtree_rotate_right(tree, grandparent);
      }
    } else {
      rbtree_node_t* uncle = grandparent->left;
      if (uncle && uncle->is_red) {
        /* Case 1: uncle is red */
        current->parent->is_red = 0;
        uncle->is_red = 0;
        grandparent->is_red = 1;
        current = grandparent;
      } else {
        if (current == current->parent->left) {
          /* Case 2: uncle is black, current is left child */
          current = current->parent;
          rbtree_rotate_right(tree, current);
        }
        /* Case 3: uncle is black, current is right child */
        current->parent->is_red = 0;
        grandparent->is_red = 1;
        rbtree_rotate_left(tree, grandparent);
      }
    }
  }
  tree->root->is_red = 0;
}

static void rbtree_fixup_remove(rbtree_t* tree, rbtree_node_t* node) {
  rbtree_node_t* sibling;
  while (node != tree->root && !node->is_red) {
    if (node == node->parent->left) {
      sibling = node->parent->right;
      if (sibling->is_red) {
        /* Case 1: sibling is red */
        sibling->is_red = 0;
        node->parent->is_red = 1;
        rbtree_rotate_left(tree, node->parent);
        sibling = node->parent->right;
      }
      if ((!sibling->left || !sibling->left->is_red) &&
          (!sibling->right || !sibling->right->is_red)) {
        /* Case 2: sibling is black, both children are black */
        sibling->is_red = 1;
        node = node->parent;
      } else {
        if (!sibling->right || !sibling->right->is_red) {
          /* Case 3: sibling is black, left child is red, right child is black */
          sibling->left->is_red = 0;
          sibling->is_red = 1;
          rbtree_rotate_right(tree, sibling);
          sibling = node->parent->right;
        }
        /* Case 4: sibling is black, right child is red */
        sibling->is_red = node->parent->is_red;
        node->parent->is_red = 0;
        sibling->right->is_red = 0;
        rbtree_rotate_left(tree, node->parent);
        node = tree->root;
      }
      } else {
        sibling = node->parent->left;
        if (sibling->is_red) {
          /* Case 1: sibling is red */
          sibling->is_red = 0;
          node->parent->is_red = 1;
          rbtree_rotate_right(tree, node->parent);
          sibling = node->parent->left;
        }
        if ((!sibling->left || !sibling->left->is_red) &&
            (!sibling->right || !sibling->right->is_red)) {
          /* Case 2: sibling is black, both children are black */
          sibling->is_red = 1;
          node = node->parent;
        } else {
          if (!sibling->left || !sibling->left->is_red) {
            /* Case 3: sibling is black, right child is red, left child is black */
            sibling->right->is_red = 0;
            sibling->is_red = 1;
            rbtree_rotate_left(tree, sibling);
            sibling = node->parent->left;
          }
          /* Case 4: sibling is black, left child is red */
          sibling->is_red = node->parent->is_red;
          node->parent->is_red = 0;
          sibling->left->is_red = 0;
          rbtree_rotate_right(tree, node->parent);
          node = tree->root;
        }
      }
    }
  }
  node->is_red = 0;
}

static rbtree_node_t* rbtree_find_node(rbtree_t* tree, int key) {
  rbtree_node_t* current = tree->root;
  while (current) {
    if (key == current->key) {
      return current;
    } else if (key < current->key) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
  return NULL;
}

int rbtree_remove(rbtree_t* tree, rbtree_node_t* node) {
  rbtree_node_t* successor;
  if (!node->left || !node->right) {
    /* node has 0 or 1 children */
    successor = node;
  } else {
    /* node has 2 children */
    successor = rbtree_find_successor(node);
  }
  rbtree_node_t* child;
  if (successor->left) {
    child = successor->left;
  } else {
    child = successor->right;
  }
  if (child) {
    child->parent = successor->parent;
  }
  if (!successor->parent) {
    tree->root = child;
  } else if (successor == successor->parent->left) {
    successor->parent->left = child;
  } else {
    successor->parent->right = child;
  }
  if (successor != node) {
    node->key = successor->key;
  }
  if (!successor->is_red) {
    rbtree_fixup_remove(tree, child);
  }
  free(successor);
  return 0;
}

