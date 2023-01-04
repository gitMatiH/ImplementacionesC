#ifndef RBTREE_H
#define RBTREE_H

typedef struct rbtree RBTree;

/*
 * Creates a new red-black tree and returns a pointer to it.
 *
 * @return: pointer to the new red-black tree
 */
RBTree* rbtree_create(void);

/*
 * Destroys the specified red-black tree.
 *
 * @tree: pointer to the red-black tree
 */
void rbtree_destroy(RBTree* tree);

/*
 * Inserts a new element into the red-black tree.
 *
 * @tree: pointer to the red-black tree
 * @key: key of the element to be inserted
 * @value: value of the element to be inserted
 *
 * @return: 0 if the element was successfully inserted, or -1 if an error occurred
 */
int rbtree_insert(RBTree* tree, int key, int value);

/*
 * Removes the element with the specified key from the red-black tree.
 *
 * @tree: pointer to the red-black tree
 * @key: key of the element to be removed
 *
 * @return: 0 if the element was successfully removed, or -1 if an error occurred
 */
int rbtree_remove(RBTree* tree, int key);

/*
 * Returns the value of the element with the specified key in the red-black tree.
 *
 * @tree: pointer to the red-black tree
 * @key: key of the element to be retrieved
 *
 * @return: value of the element, or -1 if the element was not found
 */
int rbtree_get(RBTree* tree, int key);

#endif
