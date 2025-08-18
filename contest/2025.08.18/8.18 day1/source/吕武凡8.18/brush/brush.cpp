#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10010];
int dp[10010][10010];
int main()
{
	freopen("brush.in","r",stdin);
	freopen("brush.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	dp[1][1]=a[1];
	dp[1][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j>=max(1,i-m+1);j--)
		{
			dp[i][j]=min(dp[i][j],dp[j][j]+a[i]);
		}
	}
	int ans=1e9;
	for(int i=n;i>=n-m+1;i--)
	{
		ans=min(ans,dp[n][i]);
	}
	cout<<ans;
}
