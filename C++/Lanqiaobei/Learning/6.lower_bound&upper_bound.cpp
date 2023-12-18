#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v ={6,3,2,7,5,4,8,5,5,8,3,8,3,5,6,45};
    sort(v.begin(),v.end());//数组必须为非降序才能使用lower_bound()和upper_bound()11
    for(auto &i : v)cout << i <<' ';//1.for(auto x: range) 这样会拷贝一份 range 元素，而不会改变 range 中元素。
    //2.需要修改range中元素，用 for(auto &x: range);***
    //3.当只想读取 range 中元素时，使用 const auto&，如：for(const auto &x:range)，它不会进行拷贝，也不会修改range;
    //4.当需要拷贝元素，但不可修改拷贝出来的值时，使用 for(const auto x:range)，避免拷贝开销。
    cout <<endl;
    int num;
    cin>>num;
    cout<<(lower_bound(v.begin(),v.end(),num)-v.begin())<< '\n';
    //找到数组中第一个大于于等于num的元素下标
    cout<<(upper_bound(v.begin(),v.end(),num)-v.begin())<< '\n';
    //找到数组中第一个大于num的元素下标
    return 0;
}
//地址-首地址=下标。
/*如果不存在则返回最后一个元素的下一个位置，即vector中的end()*/
/*元素n在区间[lower_bound(v.begin(),v.end(),n),upper_bound(begin(),end(),n))出现*/