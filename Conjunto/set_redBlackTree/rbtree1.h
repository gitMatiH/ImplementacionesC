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


/*
In order to implement a red-black tree, you will need to implement the following functions:

rbtree_insert: This function is responsible for inserting a new element into the tree and maintaining its red-black properties. It will involve creating a new node, inserting it into the tree in the correct position, and possibly rotating and coloring nodes to maintain the red-black properties of the tree.

rbtree_remove: This function is responsible for removing an element from the tree and maintaining its red-black properties. It will involve finding the node to be removed, unlink it from the tree, and possibly rotating and coloring nodes to maintain the red-black properties of the tree.

rbtree_find_node: This function is a helper function that is used by rbtree_get and rbtree_remove to locate the node with the specified key in the tree. It will involve traversing the tree and comparing the keys of the nodes until the node with the specified key is found, or NULL is returned if the node is not found.

rbtree_get: This function returns the value of the element with the specified key in the tree. It uses the rbtree_find_node function to locate the node with the specified key, and returns its value if the node is found.

rbtree_destroy: This function destroys the tree by freeing all of its nodes and the tree itself. It will involve writing a helper function that traverses the tree in a pre-order fashion and frees each node.

I hope this helps! Let me know if you have any questions.
*/


#endif
