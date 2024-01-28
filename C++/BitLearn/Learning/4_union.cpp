#include <bits/stdc++.h>
using namespace std;
int main(){
    union data{
        int i;
        char ch;
        float f;
    };
    cout<<sizeof(union data)<<endl;
    union data x;
    x.i = 1;
    x.ch = 'a';
    x.f = 98.465;
    cout<<x.i<<'\n'<<x.ch<<'\n'<<x.f<<endl;
    return 0;
}