#include <bits/stdc++.h>
using namespace std;

int decToBin(int dec) {
  int result = 0, temp = dec, j = 1;
  while (temp) {
    result = result + j * (temp % 2);
    temp = temp / 2;
    j = j * 10;
  }
  return result;
}
int main() {
  int m, n,ans=0;
  cin >> n;
  m = decToBin(n);
  while(m){
    if(m % 10 == 1){
      ans++;
    }
    m /= 10;
  }
  cout << ans<<endl;
}