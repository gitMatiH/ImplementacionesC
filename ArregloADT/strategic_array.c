#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 10

typedef struct {
  int *array;
  size_t used;
  size_t size;
} Array;

void initArray(Array *a, size_t initialSize) {
  a->array = (int *)malloc(initialSize * sizeof(int));
  a->used = 0;
  a->size = initialSize;
}

void insertArray(Array *a, int element) {
  if (a->used == a->size) {
    // Increase the size of the array by 50% if it is full
    a->size = a->size + (a->size / 2);
    a->array = (int *)realloc(a->array, a->size * sizeof(int));
  }
  a->array[a->used++] = element;
}

void freeArray(Array *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}

int main() {
  Array a;
  int i;

  initArray(&a, INITIAL_SIZE);

  for (i = 0; i < 100; i++) {
    insertArray(&a, i * 2);
  }

  for (i = 0; i < a.used; i++) {
    printf("%d ", a.array[i]);
  }

  freeArray(&a);

  return 0;
}
