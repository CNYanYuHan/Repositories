#include<bits/stdc++.h>
#define N 200
#define lb lower_bound
#define ub upper_bound
//格式为：#define 标识符 常量
//（常量可以是字符、字符串、变量、类型、表达式等等）
using namespace std;
// using 格式为：using 别名 = 类型;
// typedef 格式为：typedef 类型 别名;
// (类型可以是基本数据类型，也可以是结构体等等)
main() {
  int data[N];
  for (int i = 0; i < N; i++) {
    data[i] = i * 4 + 6;
  }
  int num;
  cin >> num;
  cout << lb(data, data+N, num) - data << endl;
  return 0;
}