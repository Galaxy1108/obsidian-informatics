#include<bits/stdc++.h>
using namespace std;
unsigned long long mod;
#define int unsigned long long
unsigned long long dp[2][3510][3510];
int n,m;
signed main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin >> n >> m >> mod;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dp[0][i][j] = 1;
        }
    }
    int t = 0;
    for(int i=2;i<=n;i++)
    {
        for(int a=1;a<=m;a++)
        {
            for(int b=m;b>=a;b--)
            {
                dp[t][a][b] = (((dp[t][a][b] + dp[t][a-1][b]) % mod + dp[t][a][b+1] ) % mod + (mod - dp[t][a-1][b+1])) % mod;
            }
        }
        t^=1;
        for(int a=1;a<=m;a++)
        {
            for(int b=a;b<=m;b++)
            {
                dp[t][a][b] = (dp[t^1][a][a] + dp[t^1][b][b] + (mod - dp[t^1][a][b])) % mod;
            }
        }
    }
    unsigned long long ans = 0;
    for(int i=1;i<=m;i++)
    {
        for(int j=i;j<=m;j++)
        {
            ans = (ans + dp[t][i][j]) % mod;
        }
    }
    cout << ans;
}