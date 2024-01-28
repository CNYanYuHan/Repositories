#include <iostream>
using namespace std;
const int N = 100;
int mp[N][N], ans[N][N];

int main()
{


    int m, n;cin >> m >> n;
    for (int i = 1; i <= m;i++){
        for (int j = 1; j <= n;j++){
            cin >> mp[i][j];
        }
    }

for (int i = 1; i <= m; i++)
{
    for (int j = 1; j <= n; j++)
    {
        if(mp[i][j] == 1){
            ans[i][j] = 9;
            continue;
        }
        for (int _i = max(1, i - 1); _i <= min(m, i + 1); ++ _i)
        {           
            for (int _j = max(1, j - 1); _j <= min(n,j + 1); ++ _j)
            {
                if(mp[_i][_j])ans[i][j]++;
            }
        }
    }
}

for (int i = 1; i <= m;i++){
        for (int j = 1; j <= n; j++)
        {
            cout << ans[i][j] << " ";
        }
    cout << '\n';
    }
return 0;
}