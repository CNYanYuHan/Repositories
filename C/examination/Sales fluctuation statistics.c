#include <stdio.h>
int main() {
  int n,t;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++)
    scanf("%d", a + i);
  for (int i = 0; i < n - 1; i++) {
  t = a[i+1] - a[i];
    printf("%d ", t);
  }
}