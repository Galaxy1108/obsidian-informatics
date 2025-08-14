#include<bits/stdc++.h>
using namespace std;
int T,n,mod;
long long ans;
long long f[1000010],inv[1000010],mul[1000010],g[1000010];
long long fastpow(long long x,int y){
	long long ans=1;
	while(y){
		if(y&1) ans=(ans*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return ans;
}
int main()
{
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
	clock_t st=clock();
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&mod);
		for(int i=1;i<=n;++i) mul[i]=1,f[i]=inv[i]=g[i]=0;
		f[1]=1,inv[1]=1,g[1]=1;ans=1;
		for(int i=2;i<=n;++i){
			f[i]=(2ll*f[i-1]+f[i-2])%mod;
			mul[i]=(mul[i]*f[i])%mod;
			inv[i]=fastpow(mul[i],mod-2);
			g[i]=g[i-1]*mul[i]%mod;
			ans=(ans+1ll*i*g[i])%mod;
			for(int j=2;1ll*i*j<=n;++j){
				mul[i*j]=(1ll*mul[i*j]*inv[i])%mod;
			}
		}
		printf("%lld\n",ans);
	}

	cerr<<(clock()-st)*1.0/CLOCKS_PER_SEC<<'\n';

	return 0;
}