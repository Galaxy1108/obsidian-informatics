#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=65;
const ll mod=998244353;
ll qpow(ll x,ll y){
	ll ans=1;
	while(y){
		if(y&1) ans=ans*x%mod;
		y>>=1;
		x=x*x%mod;
	}
	return ans;
}
int n;
ll fact[N*3],inv[N*3];
ll C(ll x,ll y){
	return fact[x]*inv[y]%mod*inv[x-y]%mod;
}
int main(){
	freopen("abc.in","r",stdin);
	freopen("abc.out","w",stdout); 
	scanf("%d",&n);
	ll ans=1;
	fact[0]=1;
	inv[0]=1;
	for(int i=1;i<=3*n;i++){
		fact[i]=fact[i-1]*i%mod;
		inv[i]=qpow(fact[i],mod-2);
	}	
	ans=fact[3*n];
	ans=ans*qpow(1ll*qpow(fact[n],3)*(n+1)%mod,mod-2)%mod;
	printf("%lld",0);
	return 0;
} 
