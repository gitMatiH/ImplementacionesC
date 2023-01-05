typedef struct set {
  rbtree_t* tree;
} set_t;

set_t* set_create() {
  set_t* set = malloc(sizeof(set_t));
  set->tree = rbtree_create();
  return set;
}

void set_destroy(set_t* set) {
  rbtree_destroy(set->tree);
  free(set);
}

int set_insert(set_t* set, int key) {
  rbtree_node_t* node = malloc(sizeof(rbtree_node_t));
  node->key = key;
  node->value = NULL;
  return rbtree_insert(set->tree, node);
}

int set_remove(set_t* set, int key) {
  rbtree_node_t* node = rbtree_find_node(set->tree, key);
  if (!node) {
    return 1;
  }
  return rbtree_remove(set->tree, node);
}

int set_contains(set_t* set, int key) {
  rbtree_node_t* node = rbtree_find_node(set->tree, key);
  return node != NULL;
}
