#include <bits/stdc++.h>
using namespace std;
long long n,m,mod=9999973,dp[2][101][101],now,ans;
long long C(long long x){
	return (x*(x-1)/2)%mod;
} 
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	dp[0][0][0]=1;
	for(int i=1;i<=m;++i){
		now^=1;
		for(int j=0;j<=n;++j){
			for(int k=0;k<=j;++k){
				if(j-k){
					long long res=dp[now^1][j-1][k]*(n-j+1)%mod;
					dp[now][j][k]=(dp[now][j][k]+res)%mod;
				}
				if(k){
					long long res=dp[now^1][j][k-1]*(j-k+1)%mod;
					dp[now][j][k]=(dp[now][j][k]+res)%mod;
				}
				if(j-k&&k){
					long long res=dp[now^1][j-1][k-1]*(j-k)%mod*(n-j+1)%mod;
					dp[now][j][k]=(dp[now][j][k]+res)%mod;
				}
				if(k>=2){
					long long res=dp[now^1][j][k-2]*C(j-k+2)%mod;
					dp[now][j][k]=(dp[now][j][k]+res)%mod;
				}
				if(j-k>=2){
					long long res=dp[now^1][j-2][k]*C(n-j+2)%mod;
					dp[now][j][k]=(dp[now][j][k]+res)%mod;
				}
			}
		}
		for(int j=0;j<=n;++j){
			for(int k=0;k<=j;++k){
				dp[now][j][k]=(dp[now][j][k]+dp[now^1][j][k])%mod;
				dp[now^1][j][k]=0;
			}
		}
	}
	for(int j=0;j<=n;++j){
		for(int k=0;k<=j;++k) ans=(ans+dp[now][j][k])%mod;
	}
	printf("%lld",ans);
	return 0;
} 
