#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+5;
int h,w,a[N],b[N],dp[N][N];
signed main()
{
	freopen("kyoto.in","r",stdin);
	freopen("kyoto.out","w",stdout);
	cin>>h>>w;
	for(int i=1;i<=h;i++)cin>>a[i];
	for(int i=1;i<=w;i++)cin>>b[i];
	memset(dp,0x3f,sizeof(dp));
	dp[1][1]=0;
	for(int i=2;i<=h;i++)dp[i][1]=dp[i-1][1]+b[1];
	for(int i=2;i<=w;i++)dp[1][i]=dp[1][i-1]+a[1];
	for(int i=2;i<=h;i++)
		for(int j=2;j<=w;j++)
			dp[i][j]=min(dp[i-1][j]+b[j],dp[i][j-1]+a[i]);
	cout<<dp[h][w];
	
	return 0;
} 
