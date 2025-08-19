#include<bits/stdc++.h> 
using namespace std;
const int N=60,M=510;
int zk[N][N],n,m,dp[N][N][M],v[N][N],sz[N][N],ans=-1;
signed main()
{
	freopen("brike.in","r",stdin);
	freopen("bike.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			cin>>zk[i][j];
		}
	}
	for(int j=1;j<=n;j++)
		for(int i=1;i<=n;i++)
			v[i][j]=v[i-1][j]+zk[i][j];
	for(int j=1;j<=n;j++)
	{
		for(int i=0;i<=n;i++)
		{
			for(int k=i;k<=m;k++)
			{
				for(int t=0;t<=i+1;t++)
					dp[i][j][k]=max(dp[i][j][k],dp[t][j-1][k-i]+v[i][j]); 
			}
		}
	}
	cout<<max(dp[1][n][m],dp[0][n][m]);
	return 0;
}
