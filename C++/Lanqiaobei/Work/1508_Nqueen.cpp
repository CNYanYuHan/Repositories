#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 15;
int n, ans;

int vis[N][N]; //表示被多少个皇后占用

void dfs(int dep) {
  if (dep == n + 1) {
    ans++;
    return;
  }

  for (int i = 1; i <= n; ++i) {
    if (vis[dep][i])
      continue;
    //修改状态
    for (int _i = 1; _i <= n; ++_i)
      vis[_i][i]++;
    for (int _i = dep,_j = i; _i >= 1 && _j >= 1; --_i, --_j)
      vis[_i][_j]++;
    for (int _i = dep, _j = i; _i <= n && _j <= n; ++_i, ++_j)
      vis[_i][_j]++;
    for (int _i = dep, _j = i; _i >= 1 && _j <= n; --_i, ++_j)
      vis[_i][_j]++;
    for (int _i = dep, _j = i; _i <= n && _j >= 1; ++_i, --_j)
      vis[_i][_j]++;

    dfs(dep + 1);

    for (int _i = 1; _i <= n; ++_i)
      vis[_i][i]--;
    for (int _i = dep, _j = i; _i >= 1 && _j >= 1; --_i, --_j)
      vis[_i][_j]--;
    for (int _i = dep, _j = i; _i <= n && _j <= n; ++_i, ++_j)
      vis[_i][_j]--;
    for (int _i = dep, _j = i; _i >= 1 && _j <= n; --_i, ++_j)
      vis[_i][_j]--;
    for (int _i = dep, _j = i; _i <= n && _j >= 1; ++_i, --_j)
      vis[_i][_j]--;
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n;
  dfs(1);
  cout << ans << '\n';
  return 0;
}
/*function dfs(当前状态) {
  if (当前状态 == 目的状态) {
    ···
  }
  for (···寻找新状态) {
    if (状态合法) {
      vis[访问该点] ； dfs(新状态);
      ? 是否需要恢复现场->vis[恢复访问]
    }
  }
  if (找不到新状态) {
    ···
  }
}*/
