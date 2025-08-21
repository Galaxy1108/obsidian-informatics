#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n;
int pw[5010][5010];
long long ans,res;
long long a[5010],inva[5010],V;

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
	int	n=5003;
	for(int i=1;i<=n;++i) pw[0][i]=1;
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			pw[k][i]=1ll*pw[k-1][i]*i%mod;
		}
	}
	return;
}
namespace Lag{
	long long fac[5010],invfac[5010];
	long long y[5010],pre[5010],suf[5010];
	long long calc(long long k,int n){
		for(int i=1;i<=n+2;++i){
			y[i]=(y[i-1]+pw[n][i]);
			if(y[i]>=mod) y[i]-=mod;
		}
		n+=2;
		pre[0]=suf[n+1]=1;
		for(int i=1;i<=n;++i) pre[i]=pre[i-1]*(k-i)%mod;
		for(int i=n;i>=1;--i) suf[i]=suf[i+1]*(k-i)%mod;
		long long ans=0,Ans=0;
		for(int i=1;i<=n;++i){
			Ans=y[i]*pre[i-1]%mod*suf[i+1]%mod;
			Ans=Ans*invfac[i-1]%mod*invfac[n-i]%mod;
			if((n-i)&1) ans-=Ans;
			else ans+=Ans;
		}
		return (ans%mod+mod)%mod;
	}
	void Init(){
		int n=5003;fac[0]=1;
		for(int i=1;i<=n;++i) fac[i]=fac[i-1]*i%mod;
		invfac[n]=fastpow(fac[n],mod-2);
		for(int i=n;i>=1;--i) invfac[i-1]=invfac[i]*i%mod;
		return;
	}
}
int main()
{
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	Init();Lag::Init();
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		V=max(V,a[i]);
		inva[i]=fastpow(a[i],mod-2);
	}
	ans=V+1;
	for(int i=1;i<=n;++i){
		long long res=1,Ans=0;
		for(int j=i;j<=n;++j) res=res*inva[j]%mod;
		Ans=Lag::calc(a[i],n-i+1)-Lag::calc(a[i-1],n-i+1);
		Ans=(Ans*res)%mod;
		if(Ans<0) Ans+=mod;
		ans=(ans-Ans)%mod;
	}
	if(ans<0) ans+=mod;
	printf("%lld\n",ans);
	return 0;
}