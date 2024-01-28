#include <stdio.h>
#define N 4
void fun(int (*t)[N], int m) {
  int i, j;
  /**********found**********/
  for (i = 0; i < N; i++) {
    for (j = N - 1 - m; j >= 0; j--)
      /**********found**********/
      t[i][j + 1] = t[i][j];
    /**********found**********/
    for (j = 0; j < m; j++)
      t[i][j] = 0;
  }
}
void main() {
  int t[][N] = {21, 12, 13, 24, 25, 16, 47, 38, 29, 11, 32, 54, 42, 21, 33, 10},
      i, j, m;
  scanf("%d", &m);
  fun(t, m);
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++)
      printf("%3d", t[i][j]);
    printf("\n");
  }
}
