#include <stdio.h>

void takes_arr_pointer_1(int* arr) {
  printf("in takes_arr_pointer_1, sizeof(arr) = %d\n", sizeof(arr));
}

void takes_arr_pointer_2(int arr[]) {
  printf("in takes_arr_pointer_2, sizeof(arr) = %d\n", sizeof(arr));
}

int main() {
  int arr[100];
  printf("in main, sizeof(arr) = %d\n", sizeof(arr));
  takes_arr_pointer_1(arr);
  takes_arr_pointer_2(arr);
  return 0;
}