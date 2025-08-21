#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,m,d;
long long U1,l,r;
int f[(1<<20)|5],g[(1<<20)|5],val[(1<<20)|5];
int main()
{
	freopen("far.in","r",stdin);
	freopen("far.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1){
		int d=m/2;
		long long U1=0,U2=0,U22=0,revl=0,revr=0;
		for(int i=0;i<d;++i) U1|=(1ll<<i);
		for(int i=m-d;i<m;++i) U2|=(1ll<<i);
		for(int i=d;i<m;++i) U22|=(1ll<<i);
		scanf("%lld%lld",&l,&r);
		long long ul=U2&l,ur=U2&r;
		long long ul2=U22&l,ur2=U22&r;
		long long dl=U1&l,dr=U1&r;
		ul>>=(m-d);ur>>=m-d;
		ul2>>=(d);ur2>>=(d);
		for(int i=0;i<d;++i){
			if(ul&(1ll<<i)) revl|=(1<<(d-1-i));
			if(ur&(1ll<<i)) revr|=(1<<(d-1-i));
		}
		if(ul2==ur2){
			if(dl<=revl&&revl<=dr) printf("1\n");
			else printf("0\n");
		}
		else{
			long long ans=ur2-ul2-1;
			if(dl<=revl) ++ans;
			if(revr<=dr) ++ans;
			printf("%lld\n",ans); 
		}
		return 0;
	}
	else if(m>30){
		long long v=(1ll<<((m+1)/2))%mod;
		long long val=(1ll<<(m))%mod;
		for(int i=1;i<=n;++i) printf("%lld\n",v),v=(v*val)%mod;
		return 0;
	}
	int d=m/2;
	for(int i=0;i<d;++i) U1|=(1ll<<i);
	f[0]=1;
	for(int i=1;i<=n;++i){
		scanf("%lld%lld",&l,&r);
		for(int S=l;S<=r;++S){
			int T=S&U1;
			for(int k=m-d;k<m;++k){
				if(S&(1ll<<k)) T^=(1ll<<(m-k-1));
			}
			val[T]++;
		}
		for(int S=0;S<(1<<d);++S){
			for(int T=0;T<(1<<d);++T){
				g[S^T]=(1ll*f[S]*val[T]+g[S^T])%mod;
			}
		}
		for(int S=0;S<(1<<d);++S){
			f[S]=g[S],g[S]=val[S]=0;
		}
		printf("%lld\n",f[0]);
	}
	
	return 0;
}
