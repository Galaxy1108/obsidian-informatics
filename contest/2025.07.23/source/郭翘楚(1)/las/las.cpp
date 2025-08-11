#include <bits/stdc++.h>
using namespace std;
int n,a[1000005],dp[1000005][5],ans[10000005];
int work(int u)
{
	memset(dp,0,sizeof(dp));
	dp[1][u]=1;
	for(int i=2;i<=n;i++)
	{
		if(dp[i-1][1] and a[i-1]<=2*a[i]) dp[i][1]=1;
		if(dp[i-1][4] and a[i-1]<=a[i]) dp[i][1]=4;
		if(dp[i-1][2] and a[i-1]*2>=a[i]) dp[i][2]=2;
		if(dp[i-1][3] and a[i-1]>=a[i]) dp[i][2]=3;
		if(dp[i-1][1] and a[i-1]<=a[i]) dp[i][3]=1;
		if(dp[i-1][4] and a[i-1]*2<=a[i]) dp[i][3]=4;
		if(dp[i-1][2] and a[i-1]>=a[i]) dp[i][4]=2;
		if(dp[i-1][3] and a[i-1]>=a[i]*2) dp[i][4]=3;
		
	}
	if(dp[n][u]==0) return 0;
	for(int i=n;i>=1;i--)
	{
		if(u==1) ans[i-1]=(i-1)%(n-1)+1;
		if(u==2) ans[i]=(i-1)%(n-1)+1;
		if(u==3) ans[i-1]=ans[i]=(i-1)%(n-1)+1;
		u=dp[i][u];
	}
	for(int i=1;i<n-1;i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<ans[n-1];
	return 1; 
 } 
int main()
{
	freopen("las.in","r",stdin);
	freopen("las.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	a[++n]=a[1];
	for(int i=1;i<=4;i++)
	{
		if(work(i))
		{
			return 0;
		}
	}
	cout<<"NIE";
	return 0;
} 
