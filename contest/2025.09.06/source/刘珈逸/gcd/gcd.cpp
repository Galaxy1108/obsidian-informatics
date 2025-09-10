#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e7+5,mod=998244353;
int n,m,p[N],a[N];
int qpow(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=1ll*res*a%mod;
		b>>=1;a=1ll*a*a%mod;
	}return res;
}
int ans,inv[N];
int prime[N],tot,mu[N];
bool isp[N],fl[N];
signed main(){
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	mu[1]=-1,inv[1]=1;
	for(int i=2;i<=n;i++){
		if(!isp[i])prime[++tot]=i,inv[i]=qpow(i,mod-2);
		for(int j=1;j<=tot&&i*prime[j]<=n;j++){
			isp[i*prime[j]]=1;
			inv[i*prime[j]]=inv[i]*inv[prime[j]]%mod;
			if(i%prime[j]==0)break;
		}
	}
	for(int i=1;i<=m;i++)scanf("%lld%lld",p+i,a+i),isp[p[i]]=1,p[i]=qpow(p[i],a[i]+1);
	for(int i=2;i<=n;i++)if(!isp[i])p[++m]=i;
	for(int i=1;i<=m;i++)for(int j=n/p[i]*p[i];j;j-=p[i])mu[j]=-mu[j/p[i]];
	int cnt=-1;
	for(int i=2;i<=n;i++)if(mu[i]){
		cnt+=mu[i];
		int u=n*inv[n-n/i]%mod;
		ans=(ans+mod+mu[i]*u)%mod;
	}
	cnt=-cnt;ans=(ans+cnt)%mod;
	printf("%lld\n",ans);
	return 0;
}
