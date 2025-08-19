#include<bits/stdc++.h>
#define mod 998244353
#define Phi 402653184
using namespace std;
int n,k,T,tot,cntp,x;
int prime[1000010],P[1000010],flag[1000010],tag[1000010];
int Tag[1000010],Inv[1000010];
long long ans;
int read(){
	char st=getchar();long long ans=0,tag=0;
	while(!isdigit(st)) st=getchar();
	while(isdigit(st)){
		ans=ans*10+(st^48);
		if(ans>=Phi) ans%=Phi,tag=Phi;
		st=getchar();
	}
	return ans+tag;
}
long long fastpow(long long x,int y){
	long long ans=1;
	while(y){
		if(y&1) ans=(ans*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return ans;
}
long long fastpow2(long long x,int y){
	long long ans=1;
	while(y){
		if(y&1) ans=(ans*x)%998244352;
		x=(x*x)%998244352;
		y>>=1;
	}
	return ans;
}
void Init(){
	int N=1000000;
	for(int i=2;i<=N;++i){
		if(!flag[i]) flag[i]=i,prime[++cntp]=i;
		for(int j=1;j<=cntp&&i*prime[j]<=N&&prime[j]<=flag[i];++j){
			flag[i*prime[j]]=prime[j];
		}
	}
	for(int i=1;i<=cntp;++i){
		long long x=prime[i];
		while(x<=N){
			tag[x]=prime[i];
			x=x*prime[i];
		}
	}
	Tag[0]=1;
	for(int i=1;i<=N;++i){
		if(tag[i]) P[++tot]=i;
		else tag[i]=1;
		Tag[i]=1ll*Tag[i-1]*tag[i]%mod;
	}
	for(int i=0;i<=N;++i){
		Inv[i]=fastpow(Tag[i],mod-2);
	}
	return;
}
int main()
{
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
	scanf("%d",&T);
	Init();
	while(T--){
		scanf("%d",&n);
		k=read();
		ans=1;
		for(int i=1;i<=n;){
			int r=n/(n/i);
			x=fastpow2(n,k)-fastpow2(n-n/i,k);
			if(x<0) x+=mod-1;
			ans=(ans*fastpow(1ll*Tag[r]*Inv[i-1]%mod,x))%mod;
			i=r+1; 
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
