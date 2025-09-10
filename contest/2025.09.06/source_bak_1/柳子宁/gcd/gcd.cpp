#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int m,p[110],a[110],cntp;
long long n,ans,val[110];
int prime[10000010],mu[10000010],inv[10000010],v[10000010],flag[10000010];
long long fastpow(long long x,int y){
	long long ans=1;
	while(y){
		if(y&1) ans=(ans*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return ans;
}
void Init(){
	inv[1]=1;
	for(int i=2;i<=n;++i) inv[i]=(1ll*inv[mod%i]*(mod-mod/i))%mod;
	return;
}
int main()
{
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	scanf("%lld%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&p[i],&a[i]);
		val[i]=fastpow(p[i],a[i]);
	}
	Init();
	v[1]=n;
	for(int i=2;i<=n;++i){
		if(!flag[i]){
			flag[i]=i;
			prime[++cntp]=i;
			mu[i]=-1;
		}
		for(int j=1;j<=cntp&&1ll*i*prime[j]<=n;++j){
			flag[i*prime[j]]=prime[j];
			if(i%prime[j]){
				mu[i*prime[j]]=-mu[i];
			}
			else{
				mu[i*prime[j]]=0;
			}
		}

		if(!mu[i]) continue;
		int p=flag[i];
		v[i]=v[i/p]/p;
		for(int j=1;j<=m;++j){
			if(p==(::p[j])){
				v[i]/=val[j];
				break;
			}
		}
		if(mu[i]==1) ans=(ans-n*inv[n-v[i]]%mod*(v[i]))%mod;
		else ans=(ans+n*inv[n-v[i]]%mod*(v[i]))%mod;
		if(ans<0) ans+=mod;
	}
	ans=(ans*inv[n])%mod;
	ans=(ans+1)%mod;
	printf("%lld\n",ans);
	return 0;
}
