#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
int h,w,H[N],W[N],dp[N][N];
signed main()
{
	freopen("kyoto.in","r",stdin);
	freopen("kyoto.out","w",stdout);
	cin>>h>>w;
	for(int i=1;i<=h;i++) cin>>H[i];
	for(int i=1;i<=w;i++) cin>>W[i];
	if(h*w<=1e7) 
	{
		
	for(int i=1;i<=w;i++) dp[1][i]=(i-1)*H[1];
	for(int i=1;i<=h;i++) dp[i][1]=(i-1)*W[1];
	dp[1][1]=0;
	for(int i=2;i<=h;i++)
		for(int j=2;j<=w;j++)
		{
			dp[i][j]=min(dp[i][j-1]+H[i],dp[i-1][j]+W[j]);
		}
		cout<<dp[h][w];
	}
	return 0;
} 
