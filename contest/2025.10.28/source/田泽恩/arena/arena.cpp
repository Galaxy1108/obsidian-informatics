#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int fct[514],inv[514],pw[514][514],dp[514][514];
int fpow(int x,int y){
	int base=1;
	while(y){
		if(y&1) base=1ll*base*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return base;
}
int C(int n,int m){
	return 1ll*fct[n]*(1ll*inv[m]*inv[n-m]%mod)%mod;
}
int solve(int n,int x){
	if(x<0) return !n;
	if(~dp[n][x]) return dp[n][x];
	int res=0;
	for(int i=0,r;i<=n;++i){
		r=1ll*C(n,i)*(1ll*pw[min(x,n-1)][i]*solve(n-i,x-n+1)%mod)%mod;
		res=res+r<mod?res+r:res+r-mod;
	}
	return dp[n][x]=res;
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int n,x;
	cin>>n>>x;
	for(int i=0;i<=500;++i){
		pw[i][0]=1;
		for(int j=1;j<=500;++j) pw[i][j]=1ll*pw[i][j-1]*i%mod;
	}
	fct[0]=inv[0]=1;
	for(int i=1;i<=500;++i) fct[i]=1ll*fct[i-1]*i%mod;
	inv[500]=fpow(fct[500],mod-2);
	for(int i=499;i;--i) inv[i]=1ll*inv[i+1]*(i+1)%mod;
	for(int i=0;i<=500;++i){
		for(int j=0;j<=500;++j){
			if(!i){
				dp[i][j]=1;
				continue;
			}
			if(i!=1&&j==1){
				dp[i][j]=1;
				continue;
			}
			if(i==1){
				dp[i][j]=0;
				continue;
			}
			dp[i][j]=-1;
		}
	}
	cout<<solve(n,x);
	return 0;
} 
