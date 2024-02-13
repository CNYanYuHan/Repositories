//插入排序的优点是：当原始序列已经基本有序时再将新的数据插入进来比较方便，高效。
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  //希尔排序
  for (int gap = n / 2; gap > 0; gap = gap / 2) {
    //插入排序
    for (int i = gap; i < n; i++) {
      int value = arr[i];
      int p = i;
      while (p >= gap && arr[p - gap] > value) {
        arr[p] = arr[p - gap];
        p = p - gap;
      }
      arr[p] = value;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}