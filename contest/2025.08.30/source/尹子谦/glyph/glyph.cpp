#include<bits/stdc++.h>
using namespace std;
const int N=310;
long long n,q,a[N][N];
long long dp[N][N];
int main()
{
	freopen("glyph.in","r",stdin);
	freopen("glyph.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) 
			cin>>a[i][j];
	while(q--)
	{
		int x,xx,y,yy;
		cin>>x>>xx>>y>>yy;
		dp[x][y]=a[x][y];
		for(int i=x+1;i<=xx;i++)	dp[i][y]=dp[i-1][y]+a[i][y];
		for(int j=y+1;j<=yy;j++)	dp[x][j]=dp[x][j-1]+a[x][j];
		for(int  i=x+1;i<=xx;i++) for(int j=y+1;j<=yy;j++) dp[i][j]=min(dp[i-1][j],dp[i][j-1])+a[i][j];
		cout<<dp[xx][yy]<<endl;
	}
	return 0;
}
