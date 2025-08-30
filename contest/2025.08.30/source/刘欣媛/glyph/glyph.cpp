#include <bits/stdc++.h>
using namespace std;
int n,q,a[305][305];
long long f[305][305][305],dp[305][305];
int main()
{
	freopen("glyph.in","r",stdin);
	freopen("glyph.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	long long inf=9e18;
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(register int i=0;i<=n;i++)
	{
		for(register int j=0;j<=n;j++)
		{
			dp[i][j]=inf;
		}
	}
	for(register int k=1;k<=n;k++)
	{
		for(register int i=0;i<=n;i++)
		{
			for(register int j=0;j<=n;j++)
			{
				f[k][i][j]=inf;
			}
		}
	}
	
	for(register int k=1;k<=n;k++)
	{
		f[k][1][k]=a[1][k];
		for(register int i=1;i<=n;i++)
		{
			for(register int j=k;j<=n;j++)
			{
				if(i==1&&j==k) continue;
				f[k][i][j]=min(f[k][i-1][j],f[k][i][j-1])+a[i][j];
				
			}
		}
	}
//	for(int i =1;i<=n;i++)
//	{
//		for(int j=3;j<=n;j++)
//		{
//			cout<<f[3][i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	while(q--)
	{
		int x,xx,y,yy;
		cin>>x>>xx>>y>>yy;
		
		if(x==1)
		{
			cout<<f[y][xx][yy]<<"\n";	
			continue;
		}
		dp[x][y]=a[x][y];
		for(register int i=x;i<=xx;i++)
		{
			for(register int j=y;j<=yy;j++)
			{
				if(i==x&&j==y) continue;
				dp[i][j]=min(dp[i-1][j],dp[i][j-1])+a[i][j];
				//cout<<i<<" "<<j<<" "<<dp[i][j]<<" "<<min(dp[i-1][j],dp[i][j-1])<<"\n";
			}
		}
		cout<<dp[xx][yy]<<"\n";
		for(register int i=x;i<=xx;i++)
		{
			for(register int j=y;j<=yy;j++)
			{
				dp[i][j]=inf;
			}
		}
	}
	
	
	return 0;
} 
