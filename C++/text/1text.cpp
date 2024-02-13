#include <bits/stdc++.h>
using namespace std;
multimap<int, int> mp;
int main() {
  int t;
  cin >> t;
  int a, b;
  for (int i = 0; i < t; ++i) {
    cin >> a >> b;
    mp.insert({b, a});
  }
  for (auto &[x, y] : mp)
    cout << y << '\n';
  return 0;
}