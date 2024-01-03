#include <stdio.h>
int main() {
  char ch = getchar(); //输入字符
  putchar(ch);
  return 0;
}
/*函数原型：int getchar(void); 返回类型为int,参数为void

头  文  件：#include<stdio.h>

返  回  值： 1、getchar返回的是字符的ASCII码值（整数）。
            2、getchar在读取结束或者失败的时候，会返回EOF。(EOF意思是end of file,本质上是-1）

读取方式：只能输入字符型,输入时遇到回车键才从缓冲区依次提取字符。

结束输入的方式：以Enter结束输入（空格不结束），接受空格符。

舍弃回车符的方法：以Enter结束输入时，接受空格，会舍弃最后的回车符。*/