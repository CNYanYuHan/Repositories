#include <bits/stdc++.h>
using namespace std;
//格式：binary_search(numbers.begin(),numbers.end(),target);
//它通过二分查找算法来确定序列中是否存在目标元素。
//函数返回一个bool值，表示目标是否存在于序列之中。
//如果需要获取找到元素的位置，可以使用:lower_bound()函数，或者upper_bound()函数。
int main() {
  vector<int> num = {1, 5, 8, 6, 3, 9, 4};

  int tar = 5;

  bool found = binary_search(num.begin(),num.end(),tar);
  if(found){
    cout << "Target target "<<tar<<"is found.";
    cout << "Target target"<<tar<<"is not found.";
  }

  return 0;
}