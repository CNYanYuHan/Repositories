#include <bits/stdc++.h>

using namespace std;

int N, M;
int com_cnt = 0, swap_cnt = 0;

void Shell_Sort(int *arr, int *dk) {
  int dk_tmp, i, j;
  int temp;
  for (dk_tmp = 1; dk_tmp <= M; dk_tmp++) {
    int index = dk[dk_tmp];
    for (i = index + 1; i <= N; i++) {
      j = i;
      temp = arr[j];
      //注意此处的写法：
      //先判断j>index，若满足则com_cnt++，若不满足则直接退出循环
      //若顺序颠倒则发生错误
      while (j > index && ++com_cnt && temp < arr[j - index]) {
        arr[j] = arr[j - index];
        j = j - index;
        swap_cnt++; //每循环一次即进行一次交换操作，swap_cnt+1
      }
      arr[j] = temp;
    }
  }
}

int main() {
  cin >> N >> M;
  int *dk = (int *)malloc(sizeof(int) * (M + 3));
  for (int i = 1; i <= M; i++)
    cin >> dk[i];
  int *arr = (int *)malloc(sizeof(int) * (N + 3));
  for (int i = 1; i <= N; i++)
    cin >> arr[i];

  Shell_Sort(arr, dk);
  cout << com_cnt << " " << swap_cnt << endl;
  return 0;
}