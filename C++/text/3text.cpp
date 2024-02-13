#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  // 请在此输入您的代码
  int n, i;
  cin >> n;
  vector<ll> a(n);
  for (i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  ll ans = a[1] - a[0];
  for (i = 2; i < n; i++) {
    ans = min(ans, a[i] - a[i - 1]);
  }
  cout << ans;
  return 0;
}