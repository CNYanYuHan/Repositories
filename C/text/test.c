
#include <stdio.h>

int main() {
  float a, b;
  char c;
  /***********Begin**********/
  scanf("%f%c%f", &a, &c, &b);
  if (c == '+') {
    printf("%f", a + b);
  } else if (c == '-') {
    printf("%f", a - b);
  } else if (c == '*') {
    printf("%f", a * b);
  } else if (c == '/') {
    printf("%f\n", a / b);
  } else {
    printf("Input error");
  }

  /***********End**********/
  return 0;
}