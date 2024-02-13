#include <bits/stdc++.h>
using namespace std;
const int N = 5e5;
int bucket[N];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    bucket[x]++;
  }
  for (int i = 0; i <= N; i++) {
    for (int j = 1; j <= bucket[i]; j++) {
      cout << i << ' ';
    }
  }
  return 0;
}