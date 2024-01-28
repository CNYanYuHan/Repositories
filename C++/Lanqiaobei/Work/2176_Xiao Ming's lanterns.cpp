#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 3;
ll a[N], d[N];

void solve(int n, int m) {
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  for (int i = 1; i <= n; ++i)
    d[i] = a[i] - a[i - 1];

  while (m--) {
    int l, r, v;
    cin >> l >> r >> v;

    d[l] += v, d[r + 1] -= v;
  }
  //通过前缀和还原经过m次操作后的a数组；
  for (int i = 1; i <= n; ++i) {
    a[i] = a[i - 1] + d[i];
    cout << max(0ll, a[i]) /*需要确保0和a[i]是相同类型的值，以便进行正确的比较和返回。所以需要将0转化为long
                              long类型。*/
         << " \n"[i == n]; /*这行代码是一个三元运算符，它根据条件i==n选择输出空格“
                              ”或者换行符“\n”*/
  }
  int main() {
    int n, m;
    while (cin >> n >> m)
      solve(n, m);
    return 0;
  }
