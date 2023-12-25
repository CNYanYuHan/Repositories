/*1. 将头文件 #include<bits / stdc++.h> 替换为具体需要的头文件，例如
#include<iostream> 和 #include<cstring>。

2. 将数组 prefix 的大小改为 n + 1，这样可以避免数组越界。

3. 在计算前缀和数组时，可以将 s[i] =='L'? 1: (-1) 改为 `(s[i] == 'L') ? 1: -1，这样可以使代码更加简洁。

以下是优化后的代码：
*/
#include <cstring>
#include <iostream>
using namespace std;

const int N = 1005;

char s[N];
int prefix[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> (s + 1);
  int n = strlen(s + 1);

  for (int i = 1; i <= n; ++i) {
    prefix[i] = prefix[i - 1] + ((s[i] == 'L') ? 1 : -1);
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      if (prefix[j] - prefix[i - 1] == 0) {
        ans = max(ans, j - i + 1);
      }
    }
  }

  cout << ans << endl;
  return 0;
}