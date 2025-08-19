#include <bits/stdc++.h>
using namespace std;
int n,m,dp[51][51][514],a[51][51],ans;
int main(){
	freopen("brike.in","r",stdin);
	freopen("brike.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n-i+1;++j){
			cin>>a[i][j];
			a[i][j]+=a[i-1][j];
		}
	}
	for(int j=1;j<=n+1;++j){
		for(int i=0;i<=n-j+1;++i){
			for(int k=i;k<=m;++k){
				dp[j][i][k]=max(dp[j][i][k],dp[j-1][i][k-i]+a[i][j]);
				dp[j][i][k]=max(dp[j][i][k],dp[j-1][i+1][k-i]+a[i][j]);
				if(i) dp[j][i][k]=max(dp[j][i][k],dp[j][i-1][k-1]+a[i][j]-a[i-1][j]);
				if(k==m) ans=max(dp[j][i][k],m);
			}
		}
	}
	cout<<ans;
	return 0;
}
