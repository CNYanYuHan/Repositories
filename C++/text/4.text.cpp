#include <iomanip>
#include <iostream>

using namespace std;

class Circle {
public:
  float radius; //成员变量
  char *name = nullptr;
  Circle(float radius) { //构造函数
    this->radius = radius;
    name = (char *)malloc(100 * sizeof(char));
  }
  ~Circle()//析构函数
   { free(name); }                      
  float getS() { return 3.14 * radius * radius; } //成员函数
  float getC() { return 2 * 3.14 * radius; }
};
class Rectangle {
public:
  float a;
  float b;

  Rectangle(float a, float b) {
    this->a = a;
    this->b = b;
  }
  float getS() { return a * b; }
  float getC() { return 2 * (a + b); }
};
int main() {
  //实例化对象(调用构造函数)
  Circle c1(2.4f), c2(3.f);
  Rectangle r1(3.f, 4.f), r2(20.f, 3.6f);
  cout << fixed << setprecision(2);
  //调用成员变量
  cout << "The radius of circle c1 is " << c1.radius << endl;
  cout << "The a side of rectangle r1 is " << r1.a << endl;
  //调用成员函数
  cout << "The area of circle c1 is " << c1.getS() << endl;
  cout << "The circumference of rectangle r2 is " << r2.getC() << endl;
  return 0;
}
