#include <stdlib.h>
#include <stdio.h>

typedef struct {
  int rows;
  int cols;
  int **data;
} Matrix;

// Creates a new matrix with the specified number of rows and columns
Matrix *matrix_create(int rows, int cols) {
  Matrix *matrix = malloc(sizeof(Matrix));
  matrix->rows = rows;
  matrix->cols = cols;
  matrix->data = malloc(rows * sizeof(int*));
  for (int i = 0; i < rows; i++) {
    matrix->data[i] = malloc(cols * sizeof(int));
  }
  return matrix;
}

// Frees the memory used by the matrix
void matrix_free(Matrix *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    free(matrix->data[i]);
  }
  free(matrix->data);
  free(matrix);
}

// Sets the element at the specified row and column to the specified value
void matrix_set(Matrix *matrix, int row, int col, int value) {
  matrix->data[row][col] = value;
}

// Returns the element at the specified row and column
int matrix_get(Matrix *matrix, int row, int col) {
  return matrix->data[row][col];
}

// Prints the matrix to the console
void matrix_print(Matrix *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->cols; j++) {
      printf("%d ", matrix->data[i][j]);
    }
    printf("\n");
  }
}

int main(void) {
  Matrix *matrix = matrix_create(3, 3);
  matrix_set(matrix, 0, 0, 1);
  matrix_set(matrix, 0, 1, 2);
  matrix_set(matrix, 0, 2, 3);
  matrix_set(matrix, 1, 0, 4);
  matrix_set(matrix, 1, 1, 5);
  matrix_set(matrix, 1, 2, 6);
  matrix_set(matrix, 2, 0, 7);
  matrix_set(matrix, 2, 1, 8);
  matrix_set(matrix, 2, 2, 9);
  matrix_print(matrix);
  matrix_free(matrix);
  return 0;
}
