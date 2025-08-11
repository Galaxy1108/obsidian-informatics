#include <bits/stdc++.h>
using namespace std;
int n,m,t,dp[200010][2010],a[300010];
int maxdp(){
	int t=-1000000;
	for(int i=1;i<=n;i++){
		t=max(t,dp[m][i]);
	}
	return t;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=m;i++){
			scanf("%lld",&a[i]);
		}
		dp[0][0]=0;
		for(int j=1;j<=n;j++) dp[0][j]=-1000000000;
		for(int i=1;i<=m;i++){
			for(int j=0;j<=n;j++){
				if(j==0) dp[i][j]=dp[i-1][j+1]-a[i];
				else if(0<j<n){
					if(dp[i-1][j+1]-a[i]>dp[i-1][j-1]+a[i]){
						dp[i][j]=dp[i-1][j+1]-a[i];
					}
					else dp[i][j]=dp[i-1][j-1]+a[i];
				}
				else if(j==n) dp[i][j]=dp[i-1][j-1]+a[i];
			}
		}
		printf("%d\n",maxdp());
	}
	return 0;
}
