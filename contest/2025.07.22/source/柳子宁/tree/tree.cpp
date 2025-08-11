#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,m,p,q;
int l[5010],r[5010];
long long w,len[5010],invlen[5010],sum[5010];
long long ans[5010];
int f[5010][5010],g[5010][5010],add1[5010][5010],add2[5010][5010];
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
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=2;i<=n;++i) scanf("%d%d",&l[i],&r[i]),len[i]=r[i]-l[i]+1;
	for(int i=2;i<=n;++i) invlen[i]=fastpow(len[i],mod-2);
	for(int x=1;x<=n;++x){
		memset(sum,0,sizeof(sum));
		f[x][x]=1,sum[x]=1;
		for(int p=x+1;p<=n;++p){
			f[x][p]=sum[r[p]]-sum[l[p]-1];
			f[x][p]=1ll*f[x][p]*invlen[p]%mod;
			if(f[x][p]<0) f[x][p]+=mod;
			sum[p]=(sum[p-1]+f[x][p])%mod;
		}
	}
	scanf("%d",&m);
	for(int t=1;t<=m;++t){
		scanf("%d%d%lld",&p,&q,&w);
		for(int x=1;x<=n;++x){
			ans[x]=(ans[x]+1ll*w*(f[x][p]+f[x][q]))%mod;
			if(ans[x]<0) ans[x]+=mod;
		}
		g[p][q]=(-2ll*w+g[p][q])%mod;
		if(g[p][q]<0) g[p][q]+=mod;
	}
	for(int p=n;p>=1;--p){
		for(int q=n;q>=1;--q){
			add1[p][q]=(add1[p][q]+add1[p+1][q])%mod;
			add2[p][q]=(add2[p][q]+add2[p][q+1])%mod;
			g[p][q]=(g[p][q]+add1[p][q])%mod;
			g[p][q]=(g[p][q]+add2[p][q])%mod;
			if(p==q) continue;
			if(p>q){
				add1[r[p]][q]=(1ll*g[p][q]*invlen[p]+add1[r[p]][q])%mod;
				add1[l[p]-1][q]=(-1ll*g[p][q]*invlen[p]+add1[l[p]-1][q])%mod;
			}
			else{
				add2[p][r[q]]=(1ll*g[p][q]*invlen[q]+add2[p][r[q]])%mod;
				add2[p][l[q]-1]=(-1ll*g[p][q]*invlen[q]+add2[p][l[q]-1])%mod;
			}
		}
	}
	for(int i=2;i<=n;++i){
		for(int j=1;j<=n;++j){
			ans[i]=(ans[i]+1ll*g[j][j]*f[i][j])%mod;
		}
		if(ans[i]<0) ans[i]+=mod;
		printf("%lld ",ans[i]);
	}
	printf("\n");
	return 0;
}
