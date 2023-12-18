#include <bits/stdc++.h>
using namespace std;
map<char, int> pp = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}}; // pp['A']=0
int main() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (pp[a[i]] + pp[b[i]] != 3) {
      for (int j = i + 1; j < n; j++) {
        if (pp[a[i]] + pp[b[j]] == 3 && pp[a[j]] + pp[b[i]] == 3) {
          swap(b[j], b[i]);
          break;
        }
      }
      cnt++;
    }
  }
  cout << cnt;
  return 0;
}
