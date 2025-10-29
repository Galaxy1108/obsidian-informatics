#include<bits/stdc++.h>
using namespace std;
using ll =long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=500+5;
int n,x;
const ll mod=998244353;
ll ksm(ll a,ll b){
	ll ans=1;
	while(b){
		if(b%2==1) ans=ans*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ans;
}
ll fac[maxn],ifac[maxn],f[maxn][maxn],g[maxn][maxn];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	n=read();
	x=read();
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	ifac[n]=ksm(fac[n],mod-2);
	for(int i=n-1;i>=0;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
	g[0][0]=1;
	for(int i=0;i<=n;i++) for(int j=1;j<=x;j++)
		for(int k=0;k<=i;k++)
			g[i][j]=(g[i][j]+g[i-k][j-1]*ifac[k]%mod)%mod;
	for(int i=0;i<=x;i++) f[0][i]=fac[n];
	for(int i=2;i<=n;i++) for(int j=1;j<=x;j++){
		for(int k=1;(i-1)*(k-1)<j;k++){
			int c=min((i-1)*k,j);
			for(int h=1;h<=i;h++)
				f[i][j]=(f[i][j]+f[i-h][j-c]*g[h][c-(i-1)*(k-1)]%mod)%mod;
		}
	}
	printf("%lld\n",f[n][x]);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}