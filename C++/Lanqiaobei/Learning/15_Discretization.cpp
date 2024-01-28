#include <bits/stdc++.h>
using namespace std;

vector<int> L;

int getidx(int x)
{
    return lower_bound(L.begin(),L.end(),x) - L.begin();//获取该数在离散化数组中的下标。
}

const int N = 1e5 + 9;
int a[N];

int main(){
    int n;cin>>n;
    for(int i = 1;i <= n ;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n ;i++){
        L.push_back(a[i]);
    }
    sort(L.begin(),L.end());
    L.erase(unique(L.begin(),L.end()),L.end());
    //去重
    cout<<"离散化数组为:";
    for(const auto &i : L)cout << i<<' ';
    cout<<endl;

    int val;cin>> val;

    cout << getidx(val)<<endl;
    return 0;
}