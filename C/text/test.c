
#include <stdio.h>
void fun(char *s) {
  int i, j = 0;
  for (i = 0; s[i] != '\0'; i++){
    if (s[i] != 'c')
    /********found********/
    {
      s[j] = s[i];
      j++;
    }
    else{
      continue;
    }
  }
  /********found********/
}
void main() {
  char s[80];
  gets(s);
  fun(s);
  puts(s);
}
