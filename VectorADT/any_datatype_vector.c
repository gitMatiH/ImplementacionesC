#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int insertVector(Vector *v, void *element) {
  if (v->used == v->size) {
    void *temp = realloc(v->array, (v->size + 1) * v->elementSize);
    if (temp == NULL) {
      return 0;
    }
    v->array = temp;
    v->size++;
  }
  v->array[v->used++] = element;
  return 1;
}

void freeVector(Vector *v) {
  for (int i = 0; i < v->used; i++) {
    free(v->array[i]);
  }
  free(v->array);
  v->array = NULL;
  v->used = v->size = 0;
}

int main() {
  Vector v;
  char *str1 = "Hello";
  char *str2 = "World";
  int x = 10;
  double y = 3.14;

  initVector(&v, 1, sizeof(void *));

  if (insertVector(&v, str1)) {
    printf("%s ", (char *)v.array[0]);
  }
  if (insertVector(&v, str2)) {
    printf("%s ", (char *)v.array[1]);
  }
  if (insertVector(&v, &x)) {
    printf("%d ", *(int *)v.array[2]);
  }
  if (insertVector(&v, &y)) {
    printf("%.2f ", *(double *)v.array[3]);
  }

  freeVector(&v);

  return 0;
}
