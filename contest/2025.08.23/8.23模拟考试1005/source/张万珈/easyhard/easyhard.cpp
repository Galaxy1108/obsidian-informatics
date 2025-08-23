#include <bits/stdc++.h>
using namespace std;
int mod;
long long C[3010][3010],l[3010];
void initC()
{
    C[0][0] = 1;
    for(int i=1;i<=3000;i++)
    {
        C[i][0] = 1;
        for(int j=1;j<i;j++)
        {
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
        }
        C[i][i] = 1;
    }
}
void initL()
{
    l[0] = 1;
    for(int i=1;i<=3000;i++)
    {
        l[i] = l[i-1]*2;
        if(l[i] >= mod) l[i] -= mod;
    }
}
signed main()
{
    freopen("easyhard.in","r",stdin);
    freopen("easyhard.out","w",stdout);
    int n,m;
    cin >> n >> m >> mod;
    initL();
    initC();
    long long ans = 0;
    n--,m--;
    for(int i=0;i<=n;i++)
    for(int j=0;j<=n and i+j<=m;j++)
    {
        long long t = l[m-i-j];
        t = (t*C[m][i]) % mod;
        t = (t*C[m-i][j]) % mod;
        ans = (ans+t);
        if(ans > mod) ans -= mod;
    }
    cout << (ans * 4) % mod;
    return 0;
}