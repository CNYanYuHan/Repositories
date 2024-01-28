#include <bits/stdc++.h>
using namespace std;
// sort(起始地址,结束地址的下一位,*比较函数)
int main() {
  int n, a[100];
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int j = 1; j <= n; j++) {
     cout << a[j]<< ' ';
     }
  return 0;
}