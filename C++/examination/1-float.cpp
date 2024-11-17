#include <iostream>
using namespace std;
//默认值default value：当函数参数没有传入值时，使用默认值
int power(
    int x,
    int y =
        2) //默认参数必须在形参列表的结尾（从右向左设置）！避免歧义且应当在函数声明时就指定默认值
{
  int ans = 1;
  for (int i = 1; i <= y; i++) {
    ans *= x;
  }
  return ans;
}
// inline
// function内联函数：指建议编译器编译时将某个函数在调用处直接展开，避免运行时调用开销；若一函数功能简单，则函数调用的额外开销占比较高，则建议将其设置为内联函数，inline关键字只是建议编译器将函数内联，是否内联由编译器自行决定；函数内联发生在编译时，提高运行时的效率；【语句较少】的函数建议设置为内联函数，以提高效率；
inline int getMax(int a, int b, int c) {
  return a > b ? (a > c ? a : c) : (b > c ? b : c);
}
void swap(int &x, int &y) { //引用的本质是已定义变量的别名，因此可以直接对其进行操作，不可存在空引用；除函数形参外，其他引用定义时必须赋初始值：类型&
                            //变量名 = 初始值;
  //类型& 变量名是定义一个该类型的引用，&变量是对变量取地址，得到一个指针
  int temp = x;
  x = y;
  y = temp;
}
void swap_p(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}
//函数重载三要素：1.名称相同2.参数列表不同3.调用不产生匹配歧义；仅有返回值不同不构成重载
//函数重载的作用：1.方便调用方编写代码，提高代码的可读性2.简化代码3 提高效率，
int add(int x, int y) { return x + y; }
float add(float x, float y) { return x + y; }
string add(int a, string s) { return to_string(a) + s; }
string add(string s, int a) { return s + to_string(a); }
string add(string s1, string s2) { return s1 + s2; }
int main() {
  int a = 10, b = 20;
  cout << "Before swap: a = " << a << " b = " << b << endl;
  swap(a, b);
  cout << "After swap: a = " << a << " b = " << b << endl;
  swap_p(&a, &b);
  cout << "After after swap_p: a = " << a << " b = " << b << endl;
  cout << "add(10, 20) = " << add(10, 20) << endl;
  cout << "add(10.5, 20.5) = "
       << add(static_cast<float>(10.5), static_cast<float>(20.56)) << endl;
  cout << add(10, "拉拉啊了") << endl;
  cout << add("拉拉啊了", 10) << endl;
  cout << add("hello", "world") << endl;
  cout << "getMax(10, 20, 30) = " << getMax(10, 20, 30) << endl;
  cout << "getMax(10, 30, 20) = " << getMax(10, 30, 20) << endl;
  cout << "getMax(30, 10, 20) = " << getMax(30, 10, 20) << endl;
  cout << "getMax(20, 30, 10) = " << getMax(20, 30, 10) << endl;
  cout << "power(2,3) = " << power(2, 3) << endl; // 8
  cout << "power(2) = " << power(2) << endl;      // 4
  cout << "power(9,3) = " << power(9, 3) << endl; // 271
  return 0;
}
