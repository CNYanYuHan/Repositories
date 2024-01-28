#include <bits/stdc++.h>
using namespace std;

map<int, int> mp; //定义了一个空的map，map是一种关联容器，用于存储键-值对。

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); //加速
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n * m; ++i) {
    int x;
    cin >> x;
    mp[x]++; //在每次循环中，从输入中读取一个整数x，然后在map
             //mp中将x的出现次数加1。
  }

  for (const auto &[x, y] : mp) {
    if (2 * y > n * m)
      cout
          << x
          << '\n'; //对于每个键值对，如果该整数出现的次数超过了n*m的一半，就将该整数输出。
  }
  return 0;
}