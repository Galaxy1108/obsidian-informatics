#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n,x,m;
int a[110];
long long f[(1<<20)|5],g[(1<<20)|5];
int prime[21]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
long long fac[100010],invfac[100010];
long long v0,v1;
long long fastpow(long long x,int y){
	long long ans=1;
	while(y){
		if(y&1) ans=(ans*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return ans;
}
long long C(int n,int m){
	if(n<0||m<0||n<m) return 0;
	return fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
void Init(){
	int N=100000;
	fac[0]=invfac[0]=1;
	for(int i=1;i<=N;++i) fac[i]=fac[i-1]*i%mod;
	invfac[N]=fastpow(fac[N],mod-2);
	for(int i=N;i>=1;--i) invfac[i-1]=invfac[i]*i%mod;
	return;
}
int main()
{
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	Init();
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&x);
		++a[x];
	}
	m=70;
	g[0]=1;
	for(int i=1;i<=m;++i){
		memcpy(f,g,sizeof(f));
		memset(g,0,sizeof(g));
		v0=v1=0;
		for(int j=0;j<=a[i];++j){
			if(j&1) v1=v1+C(a[i],j);
			else v0=v0+C(a[i],j); 
		}
		v1%=mod,v0%=mod;
		int T=0;
		for(int j=1;j<=19;++j){
			if(i%prime[j]==0) T=(T|(1<<(j-1)));
		}
		for(int S=0;S<(1<<19);++S){
			g[S^T]=(g[S^T]+f[S]*v1)%mod;
			g[S]=(g[S]+f[S]*v0)%mod;
		}
	}
	printf("%lld\n",(g[0]-1+mod)%mod);
	
	return 0;
}
