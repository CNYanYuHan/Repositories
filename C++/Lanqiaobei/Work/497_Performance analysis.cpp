#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4 + 9;
int a[N];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int num;
  ll sum = 0;
  cin >> num;
  for (int i = 0; i < num; i++) {
    cin >> a[i];
    sum += a[i];
  }
  cout << "There is the putout by max&min_element():\n";
  cout << *max_element(a, a + num) << endl;
  cout << *min_element(a, a + num) << endl;
  cout << fixed << setprecision(2) << sum * 1.0 / num << endl;

  cout << "There is the putout by max&min():\n";
  int mi = a[0], ma = a[0];
  for (int i = 0; i < num; i++) {
    mi = min(mi, a[i]);
    ma = max(ma, a[i]);
  }
  cout << ma << '\n'
      << mi << '\n'
       << fixed << setprecision(2) << sum * 1.0 / num << endl;
  return 0;
  // fixed和setprecision(2)是用于设置输出浮点数的格式，fixed表示以固定小数点格式输出，setprecision(2)表示保留两位小数。sum
  // * 1.0 / num是需要输出的浮点数表达式，表示sum除以num的结果
  // cout << fixed << setprecision(2) << sum * 1.0 /num << endl;
}