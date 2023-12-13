#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, i;
  cin >> N;
  int a[N];
  for (i = 0; i < N; i++) {
    cin >> a[i];
  }
  sort(a, a + N);
  for (i = 0; i < N; i++) {
    cout << a[i] << ' ';
  }
  cout << endl;
  for (i = N - 1; i >= 0; i--) {
    cout << a[i] << ' ';
  }
  return 0;
}