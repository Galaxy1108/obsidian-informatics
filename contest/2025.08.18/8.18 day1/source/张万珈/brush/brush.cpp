#include <bits/stdc++.h>
using namespace std;
int a[10010];
long long dp[2][110][110];
int n,m;
void init(int t)
{
    memset(dp[t],0x3f,sizeof(dp[t]));
}
signed main()
{
    freopen("brush.in","r",stdin);
    freopen("brush.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    init(0);
    for(int i=1;i<=m;i++)
    {
        for(int j=i+1;j<=m;j++)
        {
            dp[0][m-j][m-i] = a[i] + a[j];
        }
    }
    int t = 1;
    for(int i=m+1;i<=n;i++)
    {
        init(t);
        for(int j=0;j<=m-1;j++)
        {
            for(int k=j+1;k<=m-1;k++)
            {
                dp[t][j+1][k+1] = min(dp[t][j+1][k+1],dp[t^1][j][k]);
                dp[t][0][j+1] = min(dp[t][0][j+1],dp[t^1][j][k] + a[i]);
            }
        }
        t ^= 1;
    }
    t ^= 1;
    long long ans = 1e18;
    for(int i=0;i<=m-1;i++)
    {
        for(int j=0;j<=m-1;j++)
        {
            ans = min(ans,dp[t][i][j]);
        }
    }
    cout << ans;
    return 0;
}