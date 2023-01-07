#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct VectorNode {
  void *data;
  struct VectorNode *next;
} VectorNode;

typedef struct {
  VectorNode *head;
  size_t elementSize;
  size_t size;
} Vector;

void initVector(Vector *v, size_t elementSize) {
  v->head = NULL;
  v->elementSize = elementSize;
  v->size = 0;
}

void insertVector(Vector *v, void *element) {
  VectorNode *node = (VectorNode *)malloc(sizeof(VectorNode));
  if (node == NULL) {
    return;
  }
  node->data = malloc(v->elementSize);
  if (node->data == NULL) {
    free(node);
    return;
  }
  memcpy(node->data, element, v->elementSize);
  node->next = v->head;
  v->head = node;
  v->size++;
}

void freeVector(Vector *v) {
  VectorNode *current = v->head;
  while (current != NULL) {
    VectorNode *temp = current;
    current = current->next;
    free(temp->data);
    free(temp);
  }
  v->head = NULL;
  v->size = 0;
}

int main() {
  Vector v;
  char *str1 = "Hello";
  char *str2 = "World";
  int x = 10;
  double y = 3.14;

  initVector(&v, sizeof(void *));

  insertVector(&v, str1);
  insertVector(&v, str2);
  insertVector(&v, &x);
  insertVector(&v, &y);

  VectorNode *current = v.head;
  while (current != NULL) {
    printf("%s ", (char *)current->data);
    current = current->next;
  }

  freeVector(&v);

  return 0;
}
