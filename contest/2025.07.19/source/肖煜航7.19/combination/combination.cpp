#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=1005;
ll n,X,mod,m;
int c[N][N];
ll a[N];
ll qpow(ll x,ll y){
	ll ans=1;
	x%=mod;
	while(y){
		if(y&1) ans=ans*x%mod;
		y>>=1;
		x=x*x%mod;
	}
	return ans;
}
int main(){
	freopen("combination.in","r",stdin);
	freopen("combination.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&X,&mod,&m);
	if(m==0){
		ll x;
		scanf("%lld",&x);
		printf("%lld",x*qpow(X+1,n)%mod);
	}
	else{
		c[0][0]=1;
		for(int i=1;i<=n;i++){
			c[i][0]=1;
			for(int j=1;j<=n;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
		for(int i=0;i<=m;i++) scanf("%lld",&a[i]);		
		ll ans=0;
		for(int k=0;k<=n;k++){
			ll sum=0;
			for(int i=0;i<=m;i++){
				sum=(sum+1ll*a[i]*qpow(k,i)%mod*qpow(X,k)%mod*c[n][k]%mod)%mod;
			}
			ans=(ans+sum)%mod;
		}
		printf("%lld",ans);
	}
	return 0;
} 
