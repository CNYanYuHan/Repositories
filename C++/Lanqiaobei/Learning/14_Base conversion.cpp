#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100;
int a[N];
//十六进制转十进制
int main(){
    unsigned int y = 0x131ACDF4;
    cout << y << endl;
    string str;
    getline(cin,str);
    for(int i = 0;i < (int)str.length();i++){
        if(str[i] >= '0'&& str[i] <= '9'){
            a[i + 1] = str[i];}
        else{a[i + 1] = str[i] - 'A' + 10;}
    }
        ll x = 0;
        for(int i = 1;i <= (int)str.length();i++){
            x = a[i] + x*16;
        }
        cout<<x<<endl;
        return 0;
}