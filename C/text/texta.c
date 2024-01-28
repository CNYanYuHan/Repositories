#include <stdio.h>
#include <string.h>

void fun(char t[]) {
  int i, j;
  char temp;
  int n = strlen(t);
  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      if (t[i] == ' ') {
        temp = t[i];
        t[i] = t[j];
        t[j] = temp;
      } else if (t[j] != ' ' && t[i] < t[j]) {
        temp = t[i];
        t[i] = t[j];
        t[j] = temp;
      }
    }
  }
}

int main() {
  char s[81];
  fgets(s, 81, stdin);
  fun(s);
  printf("%s", s);
  return 0;
}