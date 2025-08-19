#include <bits/stdc++.h>
using namespace std;
const int N=55;
int n,m,f[N][N],dp[N][N*N][N];
int main()
{
	freopen("brike.in","r",stdin);
	freopen("brike.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=n;j>=i;j--)
	{
		cin>>f[i][j];
		f[i][j]+=f[i-1][j];
	}
	memset(dp,-0x3f,sizeof(dp));
	dp[0][0][0]=0;
	for(int i=1;i<=n;i++)
	for(int j=0;j<=min(m,(i+1)*i/2);j++)
	for(int k=0;k<=min(i,j);k++)
	for(int l=max(0,k-1);l<=i-1;l++)
	dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-k][l]+f[k][i]);
	int ans=0;
	for(int i=1;i<=n;i++)
	for(int j=0;j<=i;j++)
	ans=max(ans,dp[i][m][j]);
	cout<<ans;
	return 0;
}
