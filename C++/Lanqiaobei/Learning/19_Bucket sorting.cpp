#include <bits/stdc++.h>
using namespace std;

const int N = 1009;
#define maxn 100050

int a[N], cnt[maxn];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cnt[a[i]]++;
  }
  for (int i = 0; i < maxn; i++) {
    while (cnt[i]--) {
      printf("%d ", i);
    }
  }
  return 0;
}