#include <stdio.h>
int main(void) {
  char str[20] = "\0"; //字符数组初始化\0
  printf("请输入字符串：");
  gets(str);
  printf("%s\n", str);
  return 0;
}
/*在前面从键盘输入字符串是使用 scanf 和 %s。其实还有更简单的方法，即使用
gets()函数。

该函数的原型为：
# include <stdio.h>
char *gets(char *str);

这个函数很简单，只有一个参数。参数类型为 char* 型，即
str可以是一个字符指针变量名，也可以是一个字符数组名。

gets() 函数的功能是从输入缓冲区中读取一个字符串存储到字符指针变量
str所指向的内存空间。

gets()函数不仅比 scanf简洁，而且，就算输入的字符串中有空格也可以直接输入，不用像 scanf那样要定义多个字符数组。
*/