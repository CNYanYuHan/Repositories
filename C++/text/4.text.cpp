#include <iostream>
using namespace std;
int main() {
  int N;
  cin >> N;
  int a[N], b[N];
  for (int i = 0; i < N; i++) {
    cin >> b[i];
    cin >> a[i];
  }
  
  for (int gap = N / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < N; i++) {
      int value = a[i];
      int t = b[i];
      int p = i;
      while (p >= gap && a[p - gap] > value) {
        a[p] = a[p - gap];
        b[p] = b[p - gap];
        p = p - gap;
      }
      a[p] = value;
      b[p] = t;
    }
  }
  for (int i = 1; i < N; i++) {
    if (a[i] == a[i - 1]) {
      if (b[i] > b[i-1]){
        int t = b[i];
        b[i] = b[i - 1];
        b[i - 1] = t;
      }
    }
  }
  for (int i = 0; i < N; i++) {
    cout << b[i] << endl;
    ;
  }
  // 请在此输入您的代码
  return 0;
}