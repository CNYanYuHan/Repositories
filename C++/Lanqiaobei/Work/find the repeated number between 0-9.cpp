#include <bits/stdc++.h>
using namespace std;
const int N = 10;

void find(int a[]) {
  int helper[N] = {0};
  for (int i = 0; i < N; i++) {
    helper[a[i]]++;
  }
  for (int i = 0; i < N; i++) {
    if (helper[i] == 2) {
      cout << i << endl;
    }
}
  }
int main() {
  int a[N];
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  find(a);
  return 0;
}