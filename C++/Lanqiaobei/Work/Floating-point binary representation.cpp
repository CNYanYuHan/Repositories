#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  float num;
  cin>>num;
  while(num > 0){//乘2诺整；
    float d = num*2;
    if(d >= 1){
        cout << '1';
        num = d - 1;
    }else{
        cout << '0';
        num = d;
    }
  }
  return 0;
}