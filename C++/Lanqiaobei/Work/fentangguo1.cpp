#include <iostream>
using namespace std;

int res = 0;
void slove(int k, int tan1, int tan2) // 第i人选，糖果1，2数量
{
  if (k >= 7) { // 枚举完了，看糖果数
    if (!tan1 && !tan2)
      res++;
    return;
  }
  for (int i = 0; i <= tan1; i++)   // 枚举糖1
    for (int j = 0; j <= tan2; j++) // 枚举糖2
      if (i + j >= 2 && i + j <= 5)
        slove(k + 1, tan1 - i, tan2 - j);
  return;
}

int main() {
  slove(0, 9, 16);
  cout << res;
  return 0;
}