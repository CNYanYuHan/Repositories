#include <stdio.h>
void fn(void) {
  int n = 10;

  printf("n=%d\n", n);
  n++;
  printf("n++=%d\n", n);
}

void fn_static(void) {
  static int n = 10;

  printf("static n=%d\n", n);
  n++;
  printf("n++=%d\n", n);
}

int main(void) {
  fn();
  printf("--------------------\n");
  fn_static();
  printf("--------------------\n");
  fn();
  printf("--------------------\n");
  fn_static();

  return 0;
}
/*静态变量的输出会变化是因为静态变量在程序运行期间只被初始化一次，并且在整个程序运行期间都会保留其数值。在fn_static函数中，静态变量n的值在每次调用函数时都会保留上一次调用结束时的值，并在此基础上进行自增操作。因此，每次调用fn_static函数时，静态变量n的值都会不断增加。而普通变量n在每次调用fn函数时都会被重新初始化，因此其值每次都是初始值10。 */