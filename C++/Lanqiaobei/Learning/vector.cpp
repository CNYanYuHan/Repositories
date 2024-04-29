#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> a;
  vector<int> b[100];
  struct rec {
    int a;
    char b;
  };
  vector<rec> c;
  vector<int>::iterator yyh; // vector的迭代器，与指针类似；
}
/*
a.size()//返回实际长度（元素个数），O(1)复杂度
a.empty()//容器为空返回1,否则返回0,o(1)复杂度
a.clear()//把vector清空
a,begin()//返回指向第一个元素的迭代器，*a.begin()与a[0]作用相同
a.end()//越界访问，指向vevtor尾部,指向第n个元素再往后的边界
a.frdddont()//返回第一个元素的值,等价于*a.begin()和a[0]
a.back//返回最后一个元素的值，等价于*--a.end()和a[size()-1]
a.push_back(x)//把元素x插入vector的尾部
a.pop_back()//删除vector中的最后一个元素

1.迭代器的使用与指针类似，可遍历整个容器。
for(vector<int>::iterator it=a.begin();it != a.end();it++){
  cout<<*iterator<<endl;
  }
for(auto it = a.begin();it!=a.end();it++){
  cout << *it <<endl;
}
}
2.当成数组使用。
for(int i = 0;i<a.size();i++){
  cout <<a[i]<<endl;
}
*/
