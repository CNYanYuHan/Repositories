#include <bits/stdc++.h>
using namespace std;
// next_permutation(st,nd)函数用于生成当前序列的下一个排列并返回bool值，它按照字典序对序列重新排列，如果存在下一个排列，则将当前序列更改为下一个排列，并返回true;如果当前序列已经是最后一个排列，则返回false。
// prev_permutation(st,nd)函数用于生成当前序列的上一个排列并返回bool值，它按照字典序对序列重新排列，如果存在上一个排列，则将当前序列更改为上一个排列，并返回true;如果当前序列已经是第一个排列，则返回false。

int main() {
  vector<int> v = {1, 2, 3, 4} ;
  cout << "Initial permutation: ";
  for (auto num : v) {
    cout << num << ' ';
  }
  cout << endl;

  while(next_permutation(v.begin(), v.end())) {
    cout << "Next permutation: ";
    for (auto num : v) {
      cout << num << ' ';
    }
    cout << endl;
  }
  return 0;
}