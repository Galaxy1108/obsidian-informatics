#include <bits/stdc++.h>
using namespace std;
long long dp[1005][1005];
int a[1005];
int b[1005];
int main()
{
	freopen("kyoto.in","r",stdin);
    freopen("kyoto.out","w",stdout);
	int h,w;
	cin>>h>>w;
	for(int i=1;i<=h;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=w;i++)
	{
		cin>>b[i];
	}
	dp[1][1]=0;
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			if(i!=1 and j!=1)
			{
				dp[i][j]=min(dp[i-1][j]+b[j],dp[i][j-1]+a[i]);
			}
			else if(i==1 and j!=1)
			{
				dp[i][j]=dp[i][j-1]+a[i];
			} 
			else if(j==1 and i!=1)
			{
				dp[i][j]=dp[i-1][j]+b[j];
			}
		}
	}
	cout<<dp[h][w];
	return 0;
}