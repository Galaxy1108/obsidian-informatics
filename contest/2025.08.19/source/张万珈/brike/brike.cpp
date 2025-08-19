#include <bits/stdc++.h>
using namespace std;
const long long INF = -7161677110969590628;
int a[51][51];
long long dp[51][51][510];
int main()
{
    freopen("brike.in","r",stdin);
    freopen("brike.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i+1;j++)
        {
            cin >> a[i+j-1][i];
            a[i+j-1][i] += a[i+j-1][i-1];
        }
    }
    memset(dp,-100,sizeof(dp));
    // cout << dp[50][50][500];
    dp[1][0][0] = 0;
    dp[1][1][1] = a[1][1];
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            for(int k=0;k<=m;k++)
            {
                if(dp[i-1][j][k] == INF) continue;
                for(int l=0;l<=j+1;l++)
                {
                    dp[i][l][k+l] = max(dp[i][l][k+l],dp[i-1][j][k] + a[i][l]);
                }
            }
        }
    }
    long long ans = 0;
    for(int i=0;i<=n;i++)
    {
        ans = max(ans,dp[n][i][m]);
    }
    cout << ans;
}