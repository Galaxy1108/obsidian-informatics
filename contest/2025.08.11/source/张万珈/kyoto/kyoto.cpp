#include <bits/stdc++.h>
using namespace std;
long long a[1010],b[1010],dp[1010][1010];

int main()
{
	freopen("kyoto.in","r",stdin);
	freopen("kyoto.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin >> b[i];
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            dp[i][j] = 1e15;
        }
    }
    dp[1][1] = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==1&&j==1)
            {
                continue;
            }
            dp[i][j] = min(dp[i-1][j] + b[j],dp[i][j-1] + a[i]);
            // cout << dp[i][j];
        }
        cout << endl;
    }
    cout << dp[n][m];
}
