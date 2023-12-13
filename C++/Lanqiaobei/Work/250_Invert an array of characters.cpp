#include<bits/stdc++.h>
using namespace std;

int main(){
    //法一：逆向输出
    string s;
    getline(cin,s);//getline()可输入空格
    for(int i = (int)s.length();i >= 0;i--){
        cout<<s[i];
    }
    cout<<endl;
    //法二；reverse()反转
    reverse(s.begin(),s.end());
    cout<<s<<endl;
    //法三：swap()交换
    for(int i = 0;i < (int)s.length() / 2;i++){
    swap(s[i],s[s.length()-i-1]);
    }
    cout << s <<endl;
    return 0;
}