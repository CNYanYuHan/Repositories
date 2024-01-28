#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int main() {
  int t;
  cin >> t;
  int x = t;
  int j = 0;
  int an[N];
  while (t--) {
    int sum = 0;
    int ans = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (a == 0) {
        a++, ans++;
      }
      sum += a;
    }
    if (sum == 0) {
      sum++;
      ans++;
    }
    an[j] = ans;
    j++;
  }
  for (int i = 0; i < x; i++) {
    cout << an[i] << endl;
  }
  return 0;
}