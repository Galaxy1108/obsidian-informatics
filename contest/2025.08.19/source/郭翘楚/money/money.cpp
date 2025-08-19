#include <bits/stdc++.h>
using namespace std;
double dp[2005][3][2];
int w[2005];
double c[2005],d[2005];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int n,cost;
	cin>>n>>cost;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>c[i]>>d[i];
	}	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=2;j++)
		{
			
			if(j==0)
			{
				dp[i][0][0]=max(dp[i-1][0][0],dp[i-1][2][0]);
				dp[i][0][1]=max(dp[i-1][0][1],dp[i-1][1][1]);
			}
			if(j==1)
			{
				dp[i][j][0]=max(dp[i-1][0][1]*d[i]-cost,dp[i-1][2][1]*d[i]-cost);
			}
			if(j==2)
			{
				dp[i][j][1]=max(dp[i-1][0][0]*c[i],dp[i-1][1][0]*c[i]);
			}
			dp[i][j][0]+=w[i];
//			cout<<dp[i][j][1]<<" "<<dp[i][j][0]<<endl;
		}
	}
	printf("%.4llf",max(dp[n-1][0][0],max(dp[n][0][0],dp[n-1][0][1]*d[n]-cost)));
	return 0;
} 
