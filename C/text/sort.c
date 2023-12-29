#include <stdio.h>
const int N = 10;
int main() {
  int a[N], t;
  for (int i = 0; i < N; i++) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      if (a[i] > a[j]) {
        t = a[i];
        a[i] = a[j];
        a[j] = t;
      }
    }
  }
  for (int i = 0; i < N; i++) {
    printf("%d ", a[i]);
  }

  return 0;
}
