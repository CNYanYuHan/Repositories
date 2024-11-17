#include <bits/stdc++.h>

using namespace std;

class Book {
private:
  string name;
  int count;

public:
  Book(string name, int count = 0) {
    this->name = name; // this指明了数据成员，即Book类的成员变量name和count。
    this->count = count;
  } //构造函数，默认参数为0,是特殊的成员函数。不定义构造函数依然会有默认构造函数，但默认构造函数不能带参数。
  void set_name(const string &name) { //常量引用参数 name，类型为const
    // string，这意味着传入的字符串不可被修改，并且通过引用传递可以提高效率。这样做的好处是能够在不复制
    // string
    //对象的情况下，安全地访问它的值，因而避免了不必要的性能损耗。
    //这样做的好处是能够在不复制(函数不创建参数的副本)string对象的情况下，安全地访问它的值，因而避免了不必要的性能损耗。
    this->name = name;
  }
  void set_count(const int count) {
    if (count < 0) {
      count = 0;
    }
    this->count = count;
  }
  string get_name()const { return name; }
  int get_count() const { //只读函数；
    // 1.const string get_name()：这表示函数 get_name 返回一个
    // const 类型的 string 对象。这意味着调用该函数返回的 string
    //对象是不可修改的，但并不表示这个函数本身不会修改类的成员变量。

    // 2.string
    // get_name()const：在这里，const放在函数的尾部，表示这是一个常量成员函数。它承诺在函数调用过程中不会修改类的任何成员变量，即函数可以安全地在一个常量对象上调用。
    return count;
  }

  void add_count() { count++; }
  void remove_count() {
    if (count > 0) {
      count--;
    }
  }
};

int main() {
  Book book1("高等数学"), book2("大学英语");

  cout << book1.get_name() << "书的数量为：" << book1.get_count() << endl;
  cout << book2.get_name() << "书的数量为：" << book2.get_count() << endl;

  book1.set_count(10);
  book2.set_count(20);

  book1.add_count();
  book2.remove_count();
  book1.add_count();
  book2.remove_count();

  cout << book1.get_name() << "书的数量为：" << book1.get_count() << endl;
  cout << book2.get_name() << "书的数量为：" << book2.get_count() << endl;

  return 0;
}