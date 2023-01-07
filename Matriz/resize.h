// Resizes the matrix to the specified number of rows and columns
void matrix_resize(Matrix *matrix, int rows, int cols) {
  matrix->data = realloc(matrix->data, rows * sizeof(int*));
  for (int i = 0; i < rows; i++) {
    matrix->data[i] = realloc(matrix->data[i], cols * sizeof(int));
  }
  matrix->rows = rows;
  matrix->cols = cols;
}

/*
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
  matrix_resize(matrix, 4, 4);
  matrix_set(matrix, 3, 3, 10);
  matrix_print(matrix);
  matrix_free(matrix);
  return 0;
}
*/