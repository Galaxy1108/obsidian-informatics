#include <bits/stdc++.h>
using namespace std;
long double dp[2010][2],c[2010],d[2010];
long long w[2010];
#define int long long
void init()
{
    for(int i=0;i<=2000;i++)
    {
        for(int j=0;j<=1;j++)
        {
            dp[i][j] = -1e9;
        }

    }
}
signed main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    int n,cost;
    cin >> n >> cost;
    init();
    for(int i=1;i<=n;i++)
    {
        cin >> w[i] >> c[i] >> d[i];
        w[i] += w[i-1];
    }
    dp[0][0] = 0;
    for(int i=1;i<=n;i++)
    {
        dp[i][0] = dp[i-1][0] + w[i]-w[i-1];
        dp[i][1] = max(dp[i][1],(dp[i-1][0] + w[i] - w[i-1])*c[i]);
        for(int j=1;j<i;j++)
        {
            dp[i][0] = max(dp[i][0],(dp[j][1]*d[i]) - cost + w[i] - w[j]);
            dp[i][1] = max(dp[i][1],dp[j][1] + ((w[i] - w[j])*c[i]));
        }
    }
    printf("%.4Lf",dp[n][0]);
}