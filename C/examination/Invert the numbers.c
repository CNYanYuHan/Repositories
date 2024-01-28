#include <stdio.h>

int main() {
 int num, reversedNum = 0;

  printf("请输入一个正整数：");
  scanf("%d", &num);

  while (num != 0) {
    int digit = num % 10;
    reversedNum = reversedNum * 10 + digit;
    num /= 10;
  }

  printf("按逆序输出的结果为：%d", reversedNum);

  return 0;
}