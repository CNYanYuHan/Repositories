#include <bits/stdc++.h>
using namespace std;
class Student {
private:
  string name;
  int age;
  float score;

public:
  int id;
  int get_name() { return age; }
  int get_age() { return age; }
  void grow_up(int years) { age += years; }
};

int main() {
  vector<int> data = {5, 5, 9, 3, 7, 9, 5, 64, 89};

  sort(data.begin(), data.end());
  cout << "升序排序:" << endl;
  for (int i = 0; i <= data.size(); i++) {
    cout << data[i] << ' ';
  }
  for (int num : data) {
    cout << num << ' ';
  }
  sort(data.begin(), data.end(), greater<int>());
  cout << endl << "降序排序:" << endl;
  for (int i = 0; i < data.size(); i++) {
    cout << data[i] << ' ';
  }
  return 0;
}