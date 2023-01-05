#ifndef RBTREE_H
#define RBTREE_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct rbtree_node_t {
  struct rbtree_node_t* left;
  struct rbtree_node_t* right;
  struct rbtree_node_t* parent;
  int is_red;
} rbtree_node_t;

typedef struct rbtree_t {
  rbtree_node_t* root;
} rbtree_t;

/* Function prototypes for API functions */

/* Create and destroy tree */
rbtree_t* rbtree_create(void);
void rbtree_destroy(rbtree_t* tree);

/* Insert and remove nodes */
int rbtree_insert(rbtree_t* tree, rbtree_node_t* node);
int rbtree_remove(rbtree_t* tree, rbtree_node_t* node);

/* Find nodes */
rbtree_node_t* rbtree_find(rbtree_t* tree, int key);
rbtree_node_t* rbtree_min(rbtree_t* tree);
rbtree_node_t* rbtree_max(rbtree_t* tree);

#ifdef __cplusplus
}
#endif

#endif  /* RBTREE_H */
