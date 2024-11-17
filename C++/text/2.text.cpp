#include <bits/stdc++.h>
using namespace std;

class Book {
private:
  string name;
  int count;

public:
  Book(string name, int count = 0) {
    this->name = name;
    this->count = count;
  }
  void set_name(const string &name) { this->name = name; }
  void set_count(const int new_count) {
    if (new_count < 0) {
      count = 0;
    }
    this -> count = new_count;
  }
  string get_name() const { return name; }
  int get_count() const { return count; }
  void add_count() { count++; }
  void remove_count() {
    if (count > 0) {
      count--;
    }
  }
};

int main() {
  Book book1("C++ Primer", 10), book2("Java programming");

  cout << book1.get_name() << "的数量为" << book1.get_count() << endl;
  cout << book2.get_name() << "的数量为" << book2.get_count() << endl;

  book1.set_count(100);
  book2.set_name("Python programming");
  cout << book1.get_name() << "的数量为" << book1.get_count() << endl;
  cout << book2.get_name() << "的数量为" << book2.get_count() << endl;

  book1.add_count();
  book2.remove_count();
  cout << book1.get_name() << "的数量为" << book1.get_count() << endl;
  cout << book2.get_name() << "的数量为" << book2.get_count() << endl;

  return 0;
}
