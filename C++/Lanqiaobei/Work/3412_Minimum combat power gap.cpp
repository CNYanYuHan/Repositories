#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int a[N];
int main(){
int n;cin>>n;
for(int i = 1;i <= n;i++)cin >> a[i];
sort(a + 1,a + 1 + n);
int ans =a[2] - a[1];
for(int i = 2 ;i < n; ++i){
    ans = min(ans,a[i + 1] - a[i]);
}
cout << ans <<endl;
return 0;
}