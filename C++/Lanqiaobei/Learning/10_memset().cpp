#include <bits/stdc++.h>
using namespace std;
/* memset()是一个用于设置内存块值的函数。定义在<cstring>头文件中，函数声明：void*memset(void*
ptr, int value,size_t num);

1.ptr:指向要设置值的内存块的指针。
2.value:要设置的值，通常是一个整数。（八位二进制数）
3.num:要设置的字节数。（byte）
*/
int main() {
  int a[5];
  memset(a, 0x3f, sizeof(a));
  for (int i = 0; i < 5; i++)
    cout << bitset<32>(a[i]) << endl;
  return 0;
}