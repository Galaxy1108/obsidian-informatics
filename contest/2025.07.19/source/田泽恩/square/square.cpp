#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long n,a[114514],cntofone,ans,b[114514],c[114514],tot2,tot,dp[114514][2048],p[20],id[70],ID[114514];
bool isp[70];
inline void sieve(){
	int cnt=0;
	for(register int i=2;i<=67;++i){
		if(!isp[i]){
			p[++cnt]=i;
			id[i]=cnt;
		}
		for(register int j=1;j<=cnt;++j){
			isp[i*p[j]]=true;
			if(i%p[j]==0) break;
		}
	}
}
inline int Id(int x){
	int res=0;
	for(register int i=1;i<=11;++i){
		if(x%p[i]) continue;
		res+=1<<(i-1);
	}
	return res;
}
inline long long fpow(long long x,long long y){
	long long base=1;
	while(y){
		if(y&1) base=base*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return base;
}
inline int Id2(int x){
	return 1<<(id[x]-12);
}
int main(){
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	sieve();
	scanf("%lld",&n);
	for(register int i=1;i<=n;++i){
		scanf("%lld",a+i);
		if(id[a[i]]&&a[i]>31){
			c[++tot2]=a[i];
		}
		else{
			for(register int j=1;j<=4;++j){
				while(a[i]%(p[j]*p[j])==0) a[i]/=p[j]*p[j];
			}
			if(a[i]==1) cntofone++;
			else{
				b[++tot]=a[i];
				ID[tot]=Id(b[tot]);
			}
		}
	}
	dp[0][0]=1;
	for(register int i=1;i<=tot;++i){
		for(register int j=0;j<2048;++j){
			dp[i][j]=(dp[i-1][j]+dp[i][j])%mod;
			dp[i][j^ID[i]]=(dp[i-1][j]+dp[i][j^ID[i]])%mod;
		}
	}
	ans=dp[tot][0];
	for(register int i=0;i<=tot;++i){
		for(register int j=0;j<2048;++j) dp[i][j]=0;
	}
	dp[0][0]=ans;
	for(register int i=1;i<=tot2;++i){
		for(register int j=0;j<256;++j){
			dp[i][j]=(dp[i-1][j]+dp[i][j])%mod;
			dp[i][j^Id2(c[i])]=(dp[i-1][j]+dp[i][j^Id2(c[i])])%mod;
		}
	}
	ans=dp[tot2][0];
	ans=(ans*fpow(2,cntofone)%mod-1+mod)%mod;
	cout<<ans;
	return 0;
} //燃尽了，卡不动一点
//本机1.8s，大抵是没了
//看来暴力是出不了奇迹了罢（大悲 
