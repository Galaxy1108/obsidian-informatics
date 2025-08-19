#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long dp[5005][5005];
int a[5005];
int main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>a[i];
	}
	if(a[1]==1)
	{
		dp[2][1]=1;
		dp[2][2]=0;
	}
	else
	{
		dp[2][2]=1;
		dp[2][1]=0;
	}
	for(int i=2;i<n;i++)
	{
		if(a[i]==1)
		{
			dp[i+1][1]=1;
			for(int j=i;j>=1;j--)
			{
				dp[i+1][j]=(dp[i+1][j+1]+dp[i][j])%mod;
			}                                                                               
		}
		else
		{
			dp[i+1][1]=0;
			for(int j=2;j<=i+1;j++)
			{
				dp[i+1][j]=(dp[i][j-1]+dp[i+1][j-1])%mod;
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=(ans+dp[n][i])%mod;
	}
	cout<<ans;
	return 0;
}
