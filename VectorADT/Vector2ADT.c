#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 10

typedef struct {
  void **array;
  size_t used;
  size_t size;
  size_t elementSize;
} Vector;

void initVector(Vector *v, size_t initialSize, size_t elementSize) {
  v->array = (void **)malloc(initialSize * elementSize);
  v->used = 0;
  v->size = initialSize;
  v->elementSize = elementSize;
}

void insertVector(Vector *v, void *element) {
  if (v->used == v->size) {
    v->size = v->size + (v->size / 2);
    v->array = (void **)realloc(v->array, v->size * v->elementSize);
  }
  v->array[v->used++] = element;
}

void freeVector(Vector *v) {
  free(v->array);
  v->array = NULL;
  v->used = v->size = 0;
}

int main() {
  Vector v;
  char *str1 = "Hello";
  char *str2 = "World";

  initVector(&v, INITIAL_SIZE, sizeof(char *));

  insertVector(&v, str1);
  insertVector(&v, str2);

  for (int i = 0; i < v.used; i++) {
    printf("%s ", (char *)v.array[i]);
  }

  freeVector(&v);

  return 0;
}
