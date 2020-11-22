#include <stdio.h>

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

/*
9.22. Дана матрица размером 4*4. Поменять первый элемент каждого столбца матрицы с максимальным элементом этого столбца, второй элемент этого столбца с минимальным элементом этого столбца. Вывести на печать заданную и образовавшуюся матрицы.
*/

void print_matrix(int M[4][4]) {
  for (int i=0; i<4; i++) {
    for (int j=0; j<4; j++) {
      printf("%-4d", M[i][j]);
    }
    printf("\n");
  }
}

int main(void) {
  int M[4][4]={{3,5,-1,2},{7,5,9,-3},{-1,7,4,3},{4,-5,8,-2}};
  
  print_matrix(M);

  int* max_j = NULL;
  int* min_j = NULL;
  for (int i=0; i<4; i++) {
    max_j = &M[0][i];
    min_j = &M[1][i];
    for (int j=0; j<4; j++) {
      if (M[j][i] > *max_j) {
        swap(max_j, &M[j][i]);
      }
      if (M[j][i] < *min_j) {
        swap(min_j, &M[j][i]);
      }
    }
  }
  printf("\n");
  print_matrix(M);
  return 0;
}