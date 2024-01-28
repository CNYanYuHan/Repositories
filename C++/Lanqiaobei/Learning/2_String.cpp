#include <bits/stdc++.h>
using namespace std;
int main() {
  // 1.获取字符串的长度(.length()/size()):
  string str = "Hello, World!";
  int length = str.length(); //或者int length = str.size();
  cout << length << endl;
  // 2.拼接字符串(+或.append(const string)):
  string str1 = "Hello";
  string str2 = "World!";
  string result1 = str1 + ", " + str2;
  string result2 = str1.append(", ").append(str2);
  cout << "Result 1:" << result1 << endl;
  cout << "Result 2:" << result2 << endl;
  // 3.字符串查找(.find(const string)):找到字符串中子字符串的位置
  size_t pos = str.find("World");
  if (pos != string::npos) {
    cout << "Substring found at position: " << pos << endl;
  } else {
    cout << "Substring not found." << endl;
  }
  // 4.字符串替换(.replace(size_t pos,size_t len,const string,字符串)):
  str.replace(
      7, 5,
      "Universe"); //从第七个字符('W')开始的五个字符("World")被替换("Universe")
  cout << str << endl;
  // 5.提取子字符串(.substr(size_pos,size_len)):
  cout << str.substr(7, 8) << endl;
  // 6.比较字符串长度(.compare(const string))
  int result = str1.compare(str2);
  if (result == 0) {
    cout << "String are equal" << endl;
  } else if (result < 0) {
    cout << "String 1 is less than String 2." << endl;
  } else {
    cout << "String 1 is greater than String 2." << endl;
  }
  //遍历string的方法
  // 1.循环枚举下标
  string s = "Hello";
  for (int i = 0; i < s.size(); i++) {
    cout << s[i];
  }
  cout << endl;
  // 2.auto枚举(其中&表示引用类型，如果对i修改会改变原来的值)
  for (auto &i : s) {
    cout << i;
    i = 'a';
  }
  cout << '\n' << s << endl;
  return 0;
}