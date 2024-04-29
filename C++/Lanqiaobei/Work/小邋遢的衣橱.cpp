#include<bits/stdc++.h>
using namespace std;
string zhan[10005];
int top = 0;
void in(string str) {
  top++;
  zhan[top] = str;
}
void out() { top--; }
int main() {
  int m;
  cin >> m;
  string state, name;
  while (m--) {
    cin >> state >> name;
    if (state == "in") {
      in(name);
    } else {
      while (zhan[top] != name) {
        out();
      }
      out();
    }
    /* cout<<" "<<top<<endl;*/
  }
  if (top != 0)
    cout << zhan[top];
  else
    cout << "Empty";
}
