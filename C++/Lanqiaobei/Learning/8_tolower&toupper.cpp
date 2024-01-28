#include <bits/stdc++.h>
using namespace std;
char convertedCh(char ch) {
  if (islower(ch)) {
    ch = toupper(ch);
  } else if (isupper(ch)) {
    ch = tolower(ch);
  }
  return ch;
}
int main() {
  string s;
  getline(cin, s);
  for (auto &i : s) {
    i = convertedCh(i);
  }
  cout << s << endl;
  return 0;
}