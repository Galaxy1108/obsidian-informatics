#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+5;
int dp[N],tmp[N];
int n,m,x[N];
int solve(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++)scanf("%lld",x+i);
	reverse(x+1,x+1+m);
	for(int i=1;i<=n;i++)dp[i]=-0x3f3f3f3f3f3f3f;
	dp[0]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<=n;j++)tmp[j]=dp[j];
		for(int i=0;i<=n;i++)dp[i]=-0x3f3f3f3f3f3f3f;
		for(int j=0;j<=n;j++){
			if(j)dp[j]=max(dp[j],tmp[j-1]+x[i]);
			if(j!=n)dp[j]=max(dp[j],tmp[j+1]-x[i]);
		}
	}
	int ans=-0x3f3f3f3f3f3f3f;
	for(int i=0;i<=n;i++)ans=max(ans,dp[i]);
	printf("%lld\n",ans);
	return 0;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t;scanf("%lld",&t);
	while(t--)solve();
	return 0;
}
/*
dp[i][j]表示选了i个数,现在有j个+的最大值
dp[0][m]=0
 
*/
