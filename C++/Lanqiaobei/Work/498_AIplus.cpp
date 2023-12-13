// 下一个回文数可以通过以下方法得到：

// 1. 将当前回文数加1，得到一个新的数。 2. 将这个新数转换成字符串，记为`s`。 3. 判断`s`是否是回文字符串，如果是，直接输出`s`，否则继续执行。 4. 将`s`的前一半（向下取整）翻转后拼接在`s`的后面，得到一个新的字符串，记为`t`。 5. 如果`t`大于等于新数，输出`t`，否则回到步骤3。

//     下一个ABABBABA类型的回文数可以通过以下方法得到：

//     1. 将当前回文数加1，得到一个新的数。 2. 将这个新数转换成字符串，记为`s`。 3. 如果`s`的长度为偶数，将其分为两半，左半部分记为`s1`，右半部分记为`s2`。 4. 如果`s1`与`s2`相等，则将`s1`和`s2`分别翻转后拼接得到一个新的字符串，记为`t`。 5. 如果`t`大于等于新数并且`t`是ABABBABA类型的回文数，则输出`t`，否则回到步骤3。 6. 如果`s`的长度为奇数，将其分为三部分，左半部分记为`s1`，中间的数字记为`mid`，右半部分记为`s2`。 7. 如果`s1`与`s2`相等，则将`s1`和`s2`分别翻转后拼接得到一个新的字符串，记为`t`，并在`t`的中间插入`mid`。 8. 如果`t`大于等于新数并且`t`是ABABBABA类型的回文数，则输出`t`，否则回到步骤3。

//     下面是实现上述算法的代码：

// ```cpp
#include <bits/stdc++.h>
    using namespace std;

int s2i(string s) {
  int res = 0;
  for (const auto &i : s)
    res = res * 10 + i - '0';
  return res;
}

string i2s(int x, int w) {
  string res;
  while (x)
    res += (x % 10) + '0', x /= 10;
  while (res.length() < w)
    res += '0';
  reverse(res.begin(), res.end());
  return res;
}

bool isPa(string s) {
  for (int i = 0; i < s.length() / 2; ++i) {
    if (s[i] != s[s.length() - 1 - i])
      return false;
  }
  return true;
}

bool isPa2(string s) {
  if (!isPa(s))
    return false;
  if (s.length() == 7 && s[0] == s[6] && s[1] == s[5] && s[2] == s[4])
    return true;
  if (s.length() == 6 && s[0] == s[5] && s[1] == s[4] && s[2] == s[3])
    return true;
  return false;
}

string getNextPa(string s) {
  int n = s.length();
  int mid = (n + 1) / 2;
  string s1 = s.substr(0, mid);
  string s2 = s.substr(mid);
  string t = s1 + string(s1.rbegin(), s1.rend());
  if (t >= s) {
    if (isPa(t))
      return t;
    return getNextPa(t);
  }
  s1 = s.substr(0, mid + 1);
  string smid = s.substr(mid, 1);
  s2 = s.substr(mid + 1);
  t = s1 + smid + string(s1.rbegin(), s1.rend());
  if (t >= s) {
    if (isPa2(t))
      return t;
    return getNextPa(t);
  }
  return "";
}

int main() {
  string s;
  cin >> s;

  // 下一个回文数
  int x = s2i(s);
  while (true) {
    ++x;
    string t = i2s(x, s.length());
    if (isPa(t)) {
      cout << t << '\n';
      break;
    }
    t = t.substr(0, s.length() / 2) +
        string(t.rbegin(), t.rbegin() + s.length() / 2);
    if (t >= s) {
      cout << t << '\n';
      break;
    }
  }

  // 下一个 ABABBABA 类型的回文数
  x = s2i(s);
  while (true) {
    ++x;
    string t = i2s(x, s.length());
    if (t.length() % 2 == 0) {
      string s1 = t.substr(0, t.length() / 2);
      string s2 = t.substr(t.length() / 2);
      if (s1 == s2) {
        t = s1 + string(s1.rbegin(), s1.rend());
        if (t >= s && isPa2(t)) {
          cout << t << '\n';
          break;
        }
      }
    } else {
      int mid = t[t.length() / 2] - '0';
      string s1 = t.substr(0, t.length() / 2);
      string s2 = t.substr(t.length() / 2 + 1);
      if (s1 == s2) {
        t = s1 + to_string(mid) + string(s1.rbegin(), s1.rend());
        if (t >= s && isPa2(t)) {
          cout << t << '\n';
          break;
        }
      }
    }
  }

  return 0;
}
// ```

//     这个代码先读入一个回文数`s`，然后分别计算出下一个回文数和下一个ABABBABA类型的回文数，并输出它们。注意，在判断一个字符串是否大于等于另一个字符串时，可以直接使用字符串的比较运算符，因为字符串的比较运算符可以按字典序比较两个字符串的大小。