#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,k;
int num[N][20],dp[N][20][10];
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>num[i][j];
		}
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=k;j++)
			{
				dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j-1][0])+num[i][1];
				dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1]);
			}
		}
		cout<<max(dp[n][k][1],dp[n][k][0]);
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=k;j++)
			{
				dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j-1][0])+num[i][1];
				dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1]);
			}
		}
	}
	return 0;
} 
