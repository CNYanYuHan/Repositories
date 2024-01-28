#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 150;
int main() {
  //取消同步流来加速cin和cout
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  double a, b;
  scanf("%lf %lf", &a, &b);
  printf("%lf, %lf\n", a, b);

  char c1, c2;
  scanf("%c:%c", &c1, &c2);
  printf("%c,%c", c1, c2);

  char s[10];
  scanf("%s", s);//从s[0]开始输入
  printf("%s", s);

  scanf("%[^\n]", s);
  printf("%s", s);

  int c, d;
  cin >> c >> d;
  cout << c << ' ' << d << '\n';

  double a, b;
  cin >> a >> b;
  cout << fixed << setprecision(3) /*保留3位小数*/ << a << ' ' << b << '\n';

  char s1[10];
  cin >> s1;
  cout << s1;

  string s2;
  cin >> getline(cin, s2);//只有遇到回车符才会停止输入
  cout << s2;

  char s3[N];
  cin >> s3 + 1;//从s3[1]开始输入
for(int i = 1;s[i]/*只要s[1]不等于'/0'*/; ++i){
    cout << s[i];
}


  return 0;
}