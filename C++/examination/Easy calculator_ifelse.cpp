#include <bits/stdc++.h>
#define N 100
using namespace std;

int main() {
  int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
  char arr1[N], arr2[N], arr3[N], arr4[N];
  string x;

  printf("请输入一串字符,按回车键结束\n");
  getline(cin, x);
  int y = (int)x.length();
  for (int z = 0; z < y; z++) {
    if (x[z] >= 'a' && x[z] <= 'z') {
      arr1[a] = x[z];
      a++;
    } else if (x[z] >= 'A' && x[z] <= 'Z') {
      arr2[b] = x[z];
      b++;
    } else if (x[z] == ' ') {
      c++;
    } else if (x[z] >= '0' && x[z] <= '9') {
      arr4[f] = x[z] - '0';
      f++;
    } else {
      arr3[d] = x[z];
      d++;
    }
  }

  printf("一共有%d个大写字母,%d个小写字母,%d个数字,%d个空格和%d个其他字符\n", b,
        a, f, c, d);

  printf("大写字母为: ");
  for (e = 0; e < b; e++) {
    printf("%c ", arr2[e]);
  }

  printf("\n小写字母为: ");
  for (e = 0; e < a; e++) {
    printf("%c ", arr1[e]);
  }

  printf("\n数字为: ");
  for (e = 0; e < f; e++) {
    printf("%d ", arr4[e]);
  }

  printf("\n其他字符为: ");
  for (e = 0; e < d; e++) {
    cout << arr3[e] << ' ';
  }

  return 0;
}