//本题的核心仍然是考察希尔排序
//只是在希尔排序的思想上需要自定义一个比较函数，实现不同书籍之间的比较
#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;

class Book {
public:
  uint ID;
  uint weight;
};

bool operator<(const Book &b1,
               const Book &b2) //重载<运算符，使其用于两个Book类对象的比较
{
  if (b1.weight < b2.weight)
    return true;                   //权重小的排在前面
  else if (b1.weight == b2.weight) //权重相同
  {
    if (b1.ID < b2.ID)
      return true; // ID小的排在前面
    else
      return false;
  } else
    return false;
}

void Shell_Sort(Book *arr, uint N) //希尔排序
{
  int dk, i, j; // dk为增量，i和j用于存储下标
  Book temp;    // temp用于暂存插入排序时要插入的元素
  for (dk = N / 2; dk >= 1;
       dk = dk / 2) //初始增量dk=N/2，增量变化函数dk=dk/2，直至dk为1
  {
    for (i = dk + 1; i <= N; i++) //遍历每个子序列，i为子序列起始下标
    {
      //下面是插入排序
      if (arr[i] < arr[i - dk]) //若后一元素比前一元素小，要将其插入合适的位置
      {
        temp = arr[i];
        //插入排序的核心操作：子序列依次后移，直至找到一个合适的插入位置
        for (j = i - dk; j > 0 && temp < arr[j]; j = j - dk) {
          arr[j + dk] = arr[j];
        }
        arr[j + dk] = temp; //将该元素插入合适的位置
      }
    }
  }
}

int main() {
  uint N;
  cin >> N;
  Book *arr = (Book *)malloc(sizeof(Book) * (N + 3));
  for (uint i = 1; i <= N; i++) {
    cin >> arr[i].ID >> arr[i].weight;
  }

  Shell_Sort(arr, N);
  for (uint i = 1; i <= N; i++)
    cout << arr[i].ID << endl;
  return 0;
}