#include <stdio.h>
int main() {
  int a, count = 0;
  scanf("%d", &a);
  if (a > 0) {
    while (a) {
      count++;
      a = a / 10;
    }
    printf("%d",count);
  } else if (a == 0)
    printf("1");
  else
    printf("Error");
}
