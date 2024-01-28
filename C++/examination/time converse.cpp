#include <bits/stdc++.h>
using namespace std;

// convert函数原型
void convert(int &hour, int &minute, char &form);

int main() {
  int h, m;
  char f;
  cin >> h >> m;

  /********* Begin *********/
  if(h > 12){
    f = 'P';
    }
  else{
    f = 'A';
  }
  /*********  End  *********/
  convert(h, m, f);
  return 0;
}

// convert函数定义
/********* Begin *********/
void convert(int &hour, int &minute, char &form) {
  if (hour > 12) {
    hour -= 12;
  }
  printf("%d:%d %cM", hour, minute, form);
}

/*********  End  *********/