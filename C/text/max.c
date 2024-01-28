#include <stdio.h>
#include <string.h>
void fun(char *s) {
  int i, j;
  for (i = j = 0; s[i] != '\0'; i++)
    if (s[i] >= '0' && s[i] <= '9')
      /********found********/
      s[j] = s[i];
  j++;
  /********found********/
  s[j] = '\0';
}
void main() {
  char item[80];
  gets(item);
  fun(item);
  printf("\n%s", item);
}