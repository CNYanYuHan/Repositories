#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    if(((n-1)&n)==0){
        cout<<"ture"<<endl;
    }
    else{
        cout<<"wrong"<<endl;
    }
    return 0;
}