#include <bits/stdc++.h>
using namespace std;
long long dp[5][229028],a[229028],n,s[229028],rit[229028],cnt,ans;
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		s[i]=a[i]+s[i-1];
		if(!a[i]){
			a[i]=2;
			rit[++cnt]=i-1;
		}
		else a[i]&=1;
	}
	memset(dp,0x3f,sizeof(dp));
	int i=1;
	while(a[i]==2) ++i;
	dp[a[i]][1]=dp[a[i]+2][1]=0;
	dp[(a[i]^1)][1]=dp[(a[i]^1)+2][1]=1;
	++i;
	for(;i<=n;++i){
		if(a[i]==2){
			dp[0][i]=min({dp[0][i-1],dp[2][i-1],dp[3][i-1]})+2;
			dp[1][i]=min(dp[1][i-1],dp[2][i-1])+1;
			dp[2][i]=dp[2][i-1]+2;
			dp[3][i]=min(dp[3][i-1],dp[2][i-1])+1;
			dp[4][i]=s[i-1];
		}
		else if(a[i]){
			dp[0][i]=min({dp[0][i-1],dp[2][i-1],dp[3][i-1],dp[4][i-1]})+1;
			dp[1][i]=min({dp[1][i-1],dp[2][i-1],dp[4][i-1]});
			dp[2][i]=min(dp[2][i-1],dp[4][i-1])+1;
			dp[3][i]=min({dp[3][i-1],dp[2][i-1],dp[4][i-1]});
		}
		else{
			dp[0][i]=min({dp[0][i-1],dp[2][i-1],dp[3][i-1],dp[4][i-1]});
			dp[1][i]=min({dp[1][i-1],dp[2][i-1],dp[4][i-1]})+1;
			dp[2][i]=min(dp[2][i-1],dp[4][i-1]);
			dp[3][i]=min({dp[3][i-1],dp[2][i-1],dp[4][i-1]})+1;
		}
	}
	ans=0x3f3f3f3f3f3f3f3f;
	for(int j=1;j<=cnt;++j){
		ans=min(ans,min({dp[0][rit[j]],dp[1][rit[j]],dp[2][rit[j]],dp[3][rit[j]]})+s[n]-s[rit[j]]);
	}
	cout<<min({ans,dp[0][n],dp[1][n],dp[2][n],dp[3][n]});
	return 0;
}

