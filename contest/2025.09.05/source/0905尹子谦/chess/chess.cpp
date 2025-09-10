#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=210,M=9999973;
int n,m;
int dp[N][N][N];
signed main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m;
	dp[0][0][0]=1;
    for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			for(int k=0;k<=m-j;k++)
			{
				dp[i][j][k]=dp[i-1][j][k];
				if(j>=1) dp[i][j][k]=dp[i][j][k]+dp[i-1][j-1][k]*(m-k-j+1)%M;
				if(k>=1) dp[i][j][k]=dp[i][j][k]+dp[i-1][j+1][k-1]*(j+1)%M;
				if(j>=2) dp[i][j][k]=dp[i][j][k]+dp[i-1][j-2][k]*((m-k-j+2)*(m-k-j+1)/2)%M;
				if(k>=1) dp[i][j][k]=dp[i][j][k]+dp[i-1][j][k-1]*j%M*(m-k-j+1)%M;
				if(k>=2) dp[i][j][k]=dp[i][j][k]+dp[i-1][j+2][k-2]*((j+1)*(j+2)/2)%M;
				dp[i][j][k]%=M;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=m-i;j++)
		{
			ans=ans+dp[n][i][j];
			ans%=M;
		}
	}
	cout<<ans%M;
	return 0;
} 
