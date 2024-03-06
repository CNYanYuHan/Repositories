#include <bits/stdc++.h>
using namespace std;

// 2个相同的2进制数做不进位加法结果为0；k个相同的k进制数做不进位加法结果0；
int find(int a[], int n) {
  int h[100] = {0};
  for (int i = 0; i < n; i++) {
    if (a[i]) {
      h[a[i]]++;
    }
  }
  for (int i = 0; i <= 99; i++) {
    if (h[i] == 1) {
      return i;
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = find(a, n);
  cout<<ans<<endl;
}