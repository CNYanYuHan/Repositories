#include <stdio.h>
#include <string.h>
void fun(char *s, char *t) {
  int i, s1;
  s1 = strlen(s);
  /********found********/
  for (i = 0; i < s1; i++)
    t[i] = s[i];
  for (i = 0; i < s1; i++)
    t[s1 + i] = s[s1 - i - 1];
  /********found********/
  t[2*s1] = '\0';
}
void main() {
  char s[100], t[100];
  scanf("%s",s);
  fun(s,t);
  printf("\n%s", t);
}