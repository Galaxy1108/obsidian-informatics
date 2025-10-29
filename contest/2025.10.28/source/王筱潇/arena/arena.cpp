#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
int n,x,dp[510][510],c[510][510];
ll kpow(ll x,ll y){
	if(y==0) return 1;
	if(y==1) return x;
	ll tmp=kpow(x,y/2);
	tmp=tmp*tmp%mod;
	if(y&1) tmp=tmp*x%mod;
	return tmp;
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%lld%lld",&n,&x);
	memset(dp,0,sizeof(dp));
	memset(c,0,sizeof(c));
	for(int i=0;i<=n;i++) c[i][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=x;j++){
			if(i>j) dp[i][j]=((kpow(j,i)-kpow(j-1,i))%mod+mod)%mod;
			else {
				for(int k=1;k<=i;k++){
					dp[i][j]=(dp[i][j]+c[i][k]*kpow(i-1,i-k)%mod*dp[k][j-i+1]%mod)%mod;
				}
				
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=x;i++){
		ans+=dp[n][i];
		ans%=mod;
	}
	printf("%lld",ans);
	return 0;
} 
