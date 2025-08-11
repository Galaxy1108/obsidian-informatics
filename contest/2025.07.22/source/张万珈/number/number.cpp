#include <bits/stdc++.h>
using namespace std;
long long a[300010];
long long dp[2010][2];
int n,m;
void init(int t)
{
    for(int i=0;i<=n;i++)
    {
        dp[i][t] = -1e15;
    }
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        for(int i=1;i<=m;i++)
        {
            cin >> a[i];
        }
        init(0),init(1);
        dp[0][0] = 0;
        int t = 0;
        // for(int i=0;i<=n;i++)
        //     {
        //         // ans = max(ans,dp[i][n-i][t]);
        //         cout << dp[i][n-i][0] << ' ';
        //     }
        //     for(int i=0;i<=n;i++)
        //     {
        //         // ans = max(ans,dp[i][n-i][t]);
        //         cout << dp[i][n-i][1] << ' ';
        //     }
        for(int now=m;now>=1;now--)
        {
            t^=1;
            init(t);
            for(int i=0;i<=n;i++)
            {
                if(n-i && dp[i][t^1] != -1e15) dp[i+1][t] = max(dp[i+1][t],dp[i][t^1] + a[now]);
                if(i && dp[i][t^1] != -1e15) dp[i-1][t] = max(dp[i-1][t],dp[i][t^1] - a[now]);
            }
            // for(int i=0;i<=n;i++)
            // {
            //     // ans = max(ans,dp[i][n-i][t]);
            //     // cout << dp[i][n-i][t] << ' ';
            // }
            // cout << endl;
        }
        long long ans=-0x3f3f3f3f3f;
        for(int i=0;i<=n;i++)
        {
            ans = max(ans,dp[i][t]);
            // cout << dp[i][n-i][t] << ' ';
        }
        // cout << '\n';
        cout << ans << '\n';
    }
}
