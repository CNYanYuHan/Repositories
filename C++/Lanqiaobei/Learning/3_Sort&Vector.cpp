#include <bits/stdc++.h>
using namespace std;
bool cmp(int n,int m){
    return n > m;
}
int main() {
  vector<int> v = {2, 1, 5, 6, 8};
  sort(v.begin(), v.end(),cmp);//可传入第三个参数，可以是函数或者lambda表达式
  for (int i = 0; i < (int)v.size(); i++) {
    cout << v[i] << ' ';
  }
  cout<<endl;
  sort(v.begin(),v.end(),[](int u,int v){
    return u < v;});//运用lambda匿名函数
  for (int i = 0;i < (int)v.size();i++){
    cout << v[i] <<' ';
  }
  struct Node{
  int x,y;
  bool operator < (const Node &m)const{
    //以x为第一关键字,y为第二关键字排序。
    return x == m.x? x < m.x : y < m.y;
  }
};
  return 0;
}