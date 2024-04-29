#include <bits/stdc++.h>

using namespace std;
/*
 *num_1 代表1号糖果的剩余数量
 *num_2 代表2号糖果的剩余数量
 *id代表当前同学的编号
 */
int ans = 0;
void dfs(int num_1, int num_2, int id) {

  if (id > 7) {
    if(num_1 == 0 && num_2 == 0){
        ans++;//方案数++
    }
    return;
  }

  for (int i = 0; i <= num_1; ++i) {
    for (int j = 0; j <= num_2; j++) {
      if (i + j >= 2 && i + j <= 5) {
        dfs(num_1 - i, num_2 - j, id + 1);
        //第id个人的数对是(i,j);
      }
    }
  }
  return;
}
int main() {
  int a, b, id = 1;
  cin >> a >> b;
  dfs(a, b, id);
  cout << ans<<endl;
  return 0;
}