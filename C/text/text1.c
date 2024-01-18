#include <stdio.h>
#define M 5
/********found********/
int fun(int n, int xx[M][M]) {
  int i, j, sum = 0;
  for (i = 0; i < M; i++) {
    for (j = 0; j < M; j++) {
      /********found********/
      printf("%d", xx[i][j]);
    }
    printf("\n");
  }
  for (i = 0; i < n; i++)
    sum += xx[i][i] + xx[i][n - i - 1];
  return (sum);
}
void main() {
  int aa[M][M], i, j;
  for (i = 0; i < M; i++)
    for (j = 0; j < M; j++)
      scanf("%d", &aa[i][j]);
  printf("\n");
  printf("%d", fun(M, aa));
}
