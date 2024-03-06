#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
const ll p = 1e9 + 9;
//带备忘录递归
ll dp[N];

ll fib(int n) {
  if (dp[n])
    return dp[n];
  if (n == 1 || n == 2)
    return 1;
  else
    return dp[n] = (fib(n - 1) + fib(n - 2)) % p;
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cout << fib(i) << '\n';
  }
  return 0;
}
