#include <bits/stdc++.h>
using namespace std;
/*unique()是一个用于去除容器中相邻重复元素的函数。
它的原型定义在<algorithm>头文件中，函数声明如下:
unique(first,last);
1.first:指向容器中要去重的第一个元素的迭代器。
2.last:指向容器中要去重的最后
unique()函数将[first,last)范围内的相邻重复的元素去除，*并返回一个指向去重后容器范围的尾后迭代器。去重后的范围中只保留了第一个首次出现的元素，后续重复的相同元素都被移除。
unique()函数可用于去除各种类型的容器中的相邻重复元素，包括数组、向量、链表等。
*/
int main() {
  vector<int> vec = {1, 1, 1, 1, 5, 5, 3, 3, 6, 5, 5, 4, 4, 2};
  sort(vec.begin(), vec.end()); //重新排序，以去除不相邻的重复元素。
  auto it = unique(vec.begin(), vec.end()); //
  vec.erase(
      it,
      vec.end()); //根据去重后容器范围的迭代器，去除去重后范围之外的多余空间。

  for (auto num : vec) {
    cout << num << ' ';
  }
  cout << endl;
  vector<int> v = {1, 2, 2, 2, 6, 6, 8, 8, 4, 4, 5, 9, 9};
  sort(v.begin(), v.end());
  auto n = unique(v.begin(), v.end());
  v.erase(n, v.end());
  for (auto nu : v) {
    cout << nu << ' ';
  }
  cout << endl;

  int a[] = {5, 5, 8, 8, 9, 5, 6};
  sort(a, a + sizeof(a) / sizeof(a[0]));
  int m = unique(a, a + 7) - a; //得到去重后的容器下标大小
  for (int i = 0; i < m; i++) {
    cout << a[i] << ' ';
  }
  return 0;
}