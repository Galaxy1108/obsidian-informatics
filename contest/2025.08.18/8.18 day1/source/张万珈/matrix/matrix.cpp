#include <bits/stdc++.h>
using namespace std;
#define int long long
int a1[110],a2[110];
int s1[110],s2[110];
int f[110][11];
int dp[110][110][11]; 
int n,m,k;
void mian()
{
    for(int i=1;i<=n;i++)
    {
        cin >> a1[i];
        s1[i] = s1[i-1] + a1[i];
    }
    memset(f,-100,sizeof(f));
    f[0][0] = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=i-1;j++)
            for(int k=0;k<::k;k++)
            {
                f[i][k+1] = max(f[i][k+1],f[j][k] + s1[i] - s1[j]);
            }
        for(int k=0;k<=::k;k++)
        {
            f[i][k] = max(f[i][k],f[i-1][k]);
        }
    }
    cout << f[n][::k];
    return ;
}
signed main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
    cin >> n >> m >> k;
    if(m == 1)
    {
        mian();
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
    	cin >> a1[i] >> a2[i];
    	s1[i] = s1[i-1] + a1[i];
    	s2[i] = s2[i-1] + a2[i];
	}
	memset(dp,-100,sizeof(dp));
	dp[0][0][0] = 0;
	for(int l=1;l<=n;l++)
	{
		for(int i=0;i<=l;i++)
		for(int j=0;j<=l;j++)
		for(int k=0;k<::k;k++)
		for(int t=0;t<=l;t++)
		{
			if(t > i) dp[l][j][k+1] = max(dp[l][j][k+1],dp[i][j][k] + s1[l] - s1[t-1]);
			if(t > j) dp[i][l][k+1] = max(dp[i][l][k+1],dp[i][j][k] + s2[l] - s1[t-1]);
			if(t > max(i,j)) dp[l][l][k+1] = max(dp[l][l][k+1],dp[i][j][k] + s1[l] + s2[l] - s1[t-1] - s2[t-1]); 
		}
	} 
	long long ans = -1e18;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			ans = max(ans,dp[i][j][k]);
//			cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << endl;
		}
	}
	cout << ans;
	return 0;
}
