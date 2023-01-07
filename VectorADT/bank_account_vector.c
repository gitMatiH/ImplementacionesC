#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 10

typedef struct {
  char *name;
  char *phone;
  double balance;
} BankAccount;

typedef struct {
  BankAccount **array;
  size_t used;
  size_t size;
} Vector;

void initVector(Vector *v, size_t initialSize) {
  v->array = (BankAccount **)malloc(initialSize * sizeof(BankAccount *));
  v->used = 0;
  v->size = initialSize;
}

void insertVector(Vector *v, BankAccount *element) {
  if (v->used == v->size) {
    v->size = v->size + (v->size / 2);
    v->array = (BankAccount **)realloc(v->array, v->size * sizeof(BankAccount *));
  }
  v->array[v->used++] = element;
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
  BankAccount *account1;
  BankAccount *account2;

  initVector(&v, INITIAL_SIZE);

  account1 = (BankAccount *)malloc(sizeof(BankAccount));
  account1->name = strdup("John Smith");
  account1->phone = strdup("123-456-7890");
  account1->balance = 1000.00;

  account2 = (BankAccount *)malloc(sizeof(BankAccount));
  account2->name = strdup("Jane Doe");
  account2->phone = strdup("098-765-4321");
  account2->balance = 2000.00;

  insertVector(&v, account1);
  insertVector(&v, account2);

  for (int i = 0; i < v.used; i++) {
    printf("Name: %s\n", v.array[i]->name);
    printf("Phone: %s\n", v.array[i]->phone);
    printf("Balance: %.2f\n", v.array[i]->balance);
  }

  freeVector(&v);

  return 0;
}
