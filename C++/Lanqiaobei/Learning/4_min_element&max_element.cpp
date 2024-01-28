#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v = {1, 5, 8, 6, 3, 9, 4};
  cout << max({1, 2, 3, 4, 5}) << endl;
  cout
      << *max_element(v.begin(), v.end())
      << endl; // max_element[st,ed)返回地址[st,ed)中最大的那个值得的地址（迭代器），传入参数为两个地址（迭代器）。
  // v.begin()<=>&v[0];v.end()<=>&(v[0]+size(v));
  nth_element(v.begin(), v.begin() + 3, v.end());
  /*nth_element(st,k,ed)进行部分排序，返回值为void()，传入参数为三个地址(迭代器)。其中第二个参数位置的元素处于正确位置，其他位置元素的顺序可能是任意的，但前面的都比它小后面的都比他大。*/
  //此时v[3]的位置将会位于排序后的位置，其他的任意。
  for (auto &i : v)cout << i << ' ';
  //用于遍历容器v中的元素。其中auto关键字用于自动推导v中元素的类型，&i表示i是一个引用类型，这样可以直接修改v中的元素。循环体中的cout语句用于输出当前遍历到的元素，以空格分隔。整个循环会遍历v中的所有元素，并将它们输出到控制台。
  return 0;
}