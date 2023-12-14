#include <stdio.h>

int main() {
  int n = 'c';
  switch (n) {
  default:
    printf("error");
    break;
  case 'a':
  case 'A':
  case 'b':
  case 'B':
    printf("good");
    break;
  case 'c':
  case 'C':
    printf("pass");
    break;
  case 'd':
  case 'D':
    printf("warn");
    break;
  }
}