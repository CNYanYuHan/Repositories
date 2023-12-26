#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
int a[N], d[N];

void solve(int n, int m) {
  for (int i = 1; i < n; i++) {
    cin >> a[i];
    d[i] = a[i] - a[i - 1];
  }
  while (m--) {
    int l, r, x;
    cin >> l >> r >> x;
    d[l] += x, d[r + 1] -= x;
  }
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1] + d[i];
    cout << a[i] << " \n"[i == n];
  }
}
int main() {
  int n, m;
  while (cin >> n >> m)
    solve(n, m);
  return 0;
}