#include <bits/stdc++.h>
using namespace std;
int n,m,k;
const int mx=-0x3f3f3f3f;
int dp[105][15][2],t[105];
void work()//m==1
{
	for(int i=1;i<=n;i++) cin>>t[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j-1][0])+t[i];
			dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1]);
		}
	}
	cout<<max(dp[n][k][0],dp[n][k][1]);
}
int f[105][15][5],a[105][2];
void solve()//m==2;
{
	memset(f,mx,sizeof(f));
	for(int i=0;i<=2;i++)
	{
		for(int j=0;j<=n;j++)
		{
			f[i][j][0]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][0]>>a[i][1];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			f[i][j][0]=max({f[i-1][j][0],f[i-1][j][1],f[i-1][j][2],f[i-1][j][3],f[i-1][j][4]});
			f[i][j][1]=max({f[i-1][j-1][0],f[i-1][j][1],f[i-1][j-1][2],f[i-1][j][3],f[i-1][j-1][4]})+a[i][0];
			f[i][j][2]=max({f[i-1][j-1][0],f[i-1][j-1][1],f[i-1][j][2],f[i-1][j][3],f[i-1][j-1][4]})+a[i][1];
			f[i][j][3]=max({f[i-1][j-1][1],f[i-1][j-1][2],f[i-1][j][3]})+a[i][0]+a[i][1];
			if(j>1) f[i][j][3]=max(f[i][j][3],f[i-1][j-2][4]+a[i][0]+a[i][1]);
			f[i][j][4]=max({f[i-1][j-1][0],f[i-1][j-1][1],f[i-1][j-1][2],f[i-1][j-1][3],f[i-1][j][4]})+a[i][0]+a[i][1];
			
		}
	}
	cout<<max({f[n][k][0],f[n][k][1],f[n][k][2],f[n][k][3],f[n][k][4]});
}
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	cin>>n>>m>>k;
	if(m==2)
	{
		solve();
	}	
	else
	{
		work();
	}
}
