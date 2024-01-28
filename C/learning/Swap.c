#include <stdio.h>
void swap(int *, int *); //可以省略形参
/*应该在main函数之前提前声明swap函数，或者将swap函数的定义放在main函数之前。*/
int main() {
  int p1 = 1, p2 = 2;
  swap(&p1, &p2);
  printf("%d,%d", p1, p2);
  return 0;
}
void swap(int *p1, int *p2) {
  int m = 0;
  int *p = &m; /*使用空指针会报错，需要初始化*/
  *p = *p1;
  *p1 = *p2;
  *p2 = *p;
}
