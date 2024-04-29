#include <bits/stdc++.h>
using namespace std;

queue<string> V;
queue<string> N;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string io, name, type;
    cin >> io;
    if (io == "IN") {
      cin >> name >> type;
      if (type == "V") {
        V.push(name);
      } else {
        N.push(name);
      }
    } else {
      cin >> type;
      if (type == "V") {
        V.pop();
      } else {
        N.pop();
      }
    }
  }
  int V_size = V.size(), N_size = N.size();
  for (int i = 0; i < V_size; i++) {
    cout << V.front() << endl;
    V.pop();
  }
  for (int j = 0; j < N_size; j++) {
    cout << N.front() << endl;
    N.pop();
  }
  return 0;
}