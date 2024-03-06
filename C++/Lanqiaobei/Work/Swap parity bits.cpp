#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int ji = n & 0x55555555;
    int ou = n & 0xaaaaaaaa;
    int ans = (ji <<= 1) ^ (ou >>= 1); cout <<ans << endl;
    return 0;
}