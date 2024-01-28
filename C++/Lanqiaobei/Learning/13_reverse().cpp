/*
reverse()是一个用于反转容器中元素顺序的函数。它的原型定义在<algorithm>头文件中，函数声明如下：
reverse(first,last);
首尾地址或迭代器。
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
vector<int> v = {1 ,5 ,6 ,4 , 2 ,4 ,2 ,5};
for(auto num : v){
cout<<num<<' ';}
cout<<endl;
reverse(v.begin(),v.end());
for(auto num : v){
cout<<num<<' ';}
}