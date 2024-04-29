#include <bits/stdc++.h>
using namespace std;

int main() {
  queue<string> v;
  queue<string> n;

  int N;
  cin >> N;

  while (N--) {
    string op, name, type;
    cin >> op;
    if (op == "IN") {
      cin >> name >> type;
      if (type == "V") {
        v.push(name);
      } else {
        n.push(name);
      }
    } else {
      cin >> type;
      if (type == "V") {
        v.pop();
      } else {
        n.pop();
      }
    }
  }

  while (v.size()) {
    cout << v.front() << endl;
    v.pop();
  }
  while (n.size()) {
    cout << n.front() << endl;
    n.pop();
  }
  return 0;
}