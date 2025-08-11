#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1024;
int n;
vector<int>dp[N<<1][N];
int val[N],sum[N][10];
int opt[N],c[N];
int f[N][N];
void solve(int p,int l,int r,int d){
	for(int S=0;S<(1<<d);S++)dp[p][S].resize(r-l+2);
	if(l==r){
		int x=p-(1<<n);
		for(int S=0;S<(1<<d);S++)dp[p][S][!opt[x]]=c[x];
		for(int S=0;S<(1<<d);S++)for(int i=0;i<d;i++)
			dp[p][S][(S>>i&1)^1]+=sum[x][i];
		return;
	}int mid=l+r>>1;
	solve(p<<1,l,mid,d+1);
	solve(p<<1|1,mid+1,r,d+1);
	for(int S=0;S<(1<<d);S++)for(int i=0;i<=(r-l+1);i++){
		dp[p][S][i]=1e18;
		if((r-l+1-i)<i){//1
			for(int t=i-(r-l+1)/2;t<=(r-l+1)/2;t++)dp[p][S][i]=min(dp[p][S][i],dp[p<<1][S<<1|1][t]+dp[p<<1|1][S<<1|1][i-t]);
		}else{//0
			for(int t=0;t<=i;t++)dp[p][S][i]=min(dp[p][S][i],dp[p<<1][S<<1][t]+dp[p<<1|1][S<<1][i-t]);
		}
	}
}
signed main(){
	freopen("cost.in","r",stdin);
	freopen("cost.out","w",stdout);
	scanf("%lld",&n);
	for(int i=0;i<(1<<n);i++)scanf("%lld",opt+i);
	for(int i=0;i<(1<<n);i++)scanf("%lld",c+i);
	for(int i=0;i<(1<<n);i++)for(int j=i+1;j<(1<<n);j++)scanf("%lld",&f[i][j]),f[j][i]=f[i][j];
	for(int i=0;i<(1<<n);i++)for(int j=0;j<(1<<n);j++)for(int k=n-1;k>=0;k--)
		if((i>>k&1)^(j>>k&1)){
			sum[i][k]+=f[i][j];
			break;
		}
	solve(1,1,1<<n,0);
	int ans=1e18;
	for(int i=0;i<(1<<n);i++)ans=min(ans,dp[1][0][i]);
	printf("%lld\n",ans);
	return 0;
}
/*
树高很小 考虑状压
设dp[i][j][k]表示i子树内有j个b,且祖先的状态为k的最小值 
可将费用分到i和j上
祖先的状态与叶子不同的时候 就要加费用 
2
1 0 1 0
2 2 10 9
10 1 2
2 1
3
*/
