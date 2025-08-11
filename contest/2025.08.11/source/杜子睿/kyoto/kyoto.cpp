#include<bits/stdc++.h>
using namespace std;
long long h,w,a[1000005],b[1000005],dp[1005][1005];
int main(){
	freopen("kyoto.in","r",stdin);
	freopen("kyoto.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>h>>w;
	for(int i=1;i<=h;i++)
		cin>>a[i];
	for(int i=1;i<=w;i++)
		cin>>b[i];
	for(int i=1;i<=h;i++)
		fill(dp[i],dp[i]+w+3,1e18);
	dp[1][1]=0;	
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++){
			if(i!=1)
				dp[i][j]=min(dp[i][j],dp[i-1][j]+b[j]);
			if(j!=1)
				dp[i][j]=min(dp[i][j],dp[i][j-1]+a[i]);
		}
	cout<<dp[h][w];
	return 0;
}

