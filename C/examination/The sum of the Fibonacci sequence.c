#include <stdio.h>
/*在C语言中，const不是一个真真正正的常量，其代表的含义仅仅是只读。使用const声明的对象是一个运行时对象，无法使用其作为某个量的初值、数组的长度、case的值或在类型的情形中使用。
 */
int a[100];

int f(int n) {
  if (n <= 2) {
    return 1;
  } else {
    return a[n] = f(n - 1) + f(n - 2);
  }
}

int main() {
  int n, i, sum = 0;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    sum += f(i);
  }
  printf("%d", sum);
  return 0;
}