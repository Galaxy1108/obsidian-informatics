#include <bits/stdc++.h>
using namespace std;
long long n,m,dp[10086][114],a[10086],ans;
int main(){
	freopen("brush.in","r",stdin);
	freopen("brush.out","w",stdout);
	memset(dp,0x3f,sizeof(dp));
	ans=0x3f3f3f3f;
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=2;i<=m;++i){
		for(int j=1;j<i;++j){ 
			dp[i][i-j]=a[i]+a[j]; 
		}
	}
	for(int i=m+1;i<=n;++i){
		for(int j=1;j<m;++j){ 
			for(int k=1;j+k<=m;++k){  
				dp[i][j]=min(dp[i][j],dp[i-j][k]+a[i]);
			}
		}
	}
	for(int i=max(n-m+2,2ll);i<=n;++i){
		for(int j=1;i-j>=max(n-m+1,1ll);++j) ans=min(ans,dp[i][j]); 
	}
	cout<<ans;
	return 0;
}  
