#include <bits/stdc++.h>
using namespace std;
const int N = 120;
bool a[N][N], b[N][N];//一个为初始灌溉处，一个为更新灌溉处

int main() {
  int n, m;
  cin >> n >> m;//方格大小

  int t;
  cin >> t;//输入水管个数
  for (int i = 1; i <= t; ++i) {
    int x, y;
    cin >> x >> y;
    a[x][y] = 1;
  }//标记水管位置
  int k;
  cin >> k;//输入时间
  while (k--) {//时间流逝
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (a[i][j])//标记新的灌溉处
          b[i][j] = b[i - 1][j] = b[i + 1][j] = b[i][j - 1] = b[i][j + 1] = 1;
      }
    }

    for (int i = 1; i <= n; i++)//更新新的灌溉处
      for (int j = 1; j <= m; j++)
        a[i][j] = b[i][j];
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (a[i][j])
        ans++;//统计灌溉处
  cout << ans << '\n';
  return 0;
}