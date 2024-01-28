#include <stdio.h>
#define N 10
int main() {
  int a, b = 0,s = 0;
  scanf("%d", &a);
  /*********begin*******/
  while (a > 0) {
    b = a % 8;
    s = s * 10 + b;
    a /= 8;
  }
  /*********end********/
  printf("%d", s);
  return 0;
}