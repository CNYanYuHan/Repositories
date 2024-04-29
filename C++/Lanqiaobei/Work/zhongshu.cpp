#include<bits/stdc++.h>
using namespace std;

int x[40],y[40],r[40];
bool chk(int a,int b){
    int dx = x[a] - x[b];
    int dy = 
}
int ans = 0;
void dfs(int x,int sum){
    if(x > n){
        if(sum > ans){
            ans = sum;
        }
        return;
    }
    dfs(x + 1,sum + r[x] * r[x])
}
int main(){
    
    int n;cin>>n;
    for(int i = 1;i <= n;i++){
        cin >> x[i] >> y[i] >> r[i];
        }
    return 0;
}