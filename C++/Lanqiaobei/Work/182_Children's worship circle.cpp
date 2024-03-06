#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;

int n, a[N], dfn[N], idx, mindfn;

int dfs(int x)
{
    dfn[x] = ++ idx;

    if(dfn[a[x]])
    {
        if(dfn[a[x]] >= mindfn)return dfn[x] - dfn[a[x]] + 1;
        return 0;
    }

    return dfs(a[x]);

}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
        if(!dfn[i]){
            mindfn = idx + 1;
            ans = max(ans,dfs(i));
        }
    }
    cout << ans <<endl;
    return 0;
}