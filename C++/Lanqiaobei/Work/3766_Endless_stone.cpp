#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9; //大小为编号范围+9,int范围为0~1e9
int a[N];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  fill(a,a + N,-1);//，a 和 a + N 分别表示数组的起始地址和结束地址。这里的 a 是指向数组中第一个元素的指针，而 a + N 则是指向数组中第 N 个元素的下一个位置的指针。-1为要设置的值
  int now = 1, cnt = 0;
  while (now < N) {
    a[now] = cnt++; //第一个没有走动，所以cnt初始为0
    int x = now;
    int sum = 0; // sum为每位数相加之和

    while (x) //计算sum
    {
      sum += x % 10;
      x = x / 10;
    }
    now += sum;

    a[now] = cnt;
  }

  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    cout << a[x] << "\n";
  }

  return 0;
}