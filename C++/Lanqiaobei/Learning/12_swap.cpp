/*swap(T&a,T&b)函数接受两个参数：
a:要交换值的第一个变量的引用。
b:要交换值的第二个变量的引用。
swap()函数通过将第一个变量的值储存到临时变量中，然后将第二个变量的值赋给第一个变量，最后将临时变量的值赋给第二个变量，实现两个变量值的交换。
swap()函数可用于交换任意类型的变量，包括基本类型(整数、浮点数等)和自定义类型(如结构体、类对象等)。
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a = 10,b = 20;
    swap(a,b);
    cout<<a<<' '<<b<<endl;
}