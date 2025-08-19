#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll sum[1000005],dp[1000005],x[1000005],p[1000005],c[1000005];
int main(){
	freopen("storage.in","r",stdin);
	freopen("storage.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>p[i]>>c[i];
		sum[i]=sum[i-1]+p[i];
	}
	fill(dp,dp+n+3,1e18);
	dp[n]=c[n];
	for(int i=1;i<n;i++)
		dp[n]+=p[i]*(x[n]-x[i]);
	ll minn=dp[n];
	for(int i=n-1;i>=1;i--){
		for(int j=1;j<=int(150000000/n)&&i+j<=n;j++)
			dp[i]=min(dp[i],dp[j+i]+c[i]+x[i]*sum[i]-sum[i]*x[i+j]);
		minn=min(minn,dp[i]);
	}
	cout<<minn;
	return 0;
}

