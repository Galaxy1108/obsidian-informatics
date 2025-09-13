#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int k,T,x,cntp;
long long f[1000010],sum[1000010],g[1000010],ans[1000010];
int flag[1000010],prime[1000010],phi[1000010];
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
	int n=1000002;
	phi[1]=1;
	for(int i=2;i<=n;++i){
		if(!flag[i]) flag[i]=i,phi[i]=i-1,prime[++cntp]=i;
		for(int j=1;j<=cntp&&1ll*i*prime[j]<=n;++j){
			flag[i*prime[j]]=prime[j];
			if(i%prime[j]==0){
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			else phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
	return;
}
void calc(){
	int n=1000002;
	f[0]=1;
	for(int i=0;i<=k;++i) sum[i]=1;
	for(int i=k+1;i<=n;++i){
		f[i]=sum[i-k-1];
		if(f[i]>=mod) f[i]-=mod;
		sum[i]=(sum[i-1]+f[i]);
		if(sum[i]>=mod) sum[i]-=mod;
	}
	long long val=k,S=k;
	for(int i=k+1;i<=n;++i){
		S=(S+sum[i-1])%mod;
		val=(val+sum[i-1]-sum[i-1-k]);
		val=(val-1ll*k*f[i-k-1])%mod;
		if(val<0) val+=mod;
		g[i]=(S-val);
		if(g[i]<0) g[i]+=mod;
	}

	for(int d=1;d<=n;++d){
		for(int N=d;N<=n;N+=d){
			ans[N]=(ans[N]+1ll*phi[N/d]*g[d])%mod;
		}
	}
	for(int i=1;i<=n;++i){
		long long inv=fastpow(i,mod-2);
		ans[i]=(1ll*ans[i]*inv)%mod; 
	}
	return;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

	cin>>k>>T;
	Init();
	calc();
	while(T--){
		cin>>x;
		cout<<g[x]<<' '<<ans[x]<<'\n';
	}
	return 0;
}
