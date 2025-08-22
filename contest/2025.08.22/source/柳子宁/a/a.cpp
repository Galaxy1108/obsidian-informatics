#include<bits/stdc++.h>
using namespace std;
int n,m,mod;
long long pre,suf;
long long F[2][10000010],G[2][10000010],all[2];
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d%d%d",&n,&m,&mod);
	F[0][1]=1,G[0][m]=1,all[0]=1;
	for(int i=1,o=1;i<=n;++i,o^=1){
		memset(F[o],0,(m+5)<<3);
		memset(G[o],0,(m+5)<<3);
		all[o]=0;
		for(int x=1;x<=m;++x){
			G[o^1][x]=(G[o^1][x-1]+G[o^1][x]);
			if(G[o^1][x]>=mod) G[o^1][x]-=mod;
		} 
		for(int x=m;x>=1;--x){
			F[o^1][x]=(F[o^1][x+1]+F[o^1][x]);
			if(F[o^1][x]>=mod) F[o^1][x]-=mod;
		}
		pre=suf=0;
		for(int x=m;x>=1;--x){
			F[o][x]=(F[o][x]+all[o^1]*(m-x+1))%mod;
			F[o][x]=(F[o][x]-G[o^1][x-1]*(m-x+1))%mod;
			if(F[o][x]<0) F[o][x]+=mod;
			suf=suf+F[o^1][x+1]; if(suf>=mod) suf-=mod;
			F[o][x]=F[o][x]-suf; if(F[o][x]<0) F[o][x]+=mod;
			all[o]=(all[o]+F[o][x]);
		}
		for(int x=1;x<=m;++x){
			G[o][x]=(G[o][x]+all[o^1]*x)%mod;
			G[o][x]=(G[o][x]-F[o^1][x+1]*x)%mod;
			if(G[o][x]<0) G[o][x]+=mod;
			pre=pre+G[o^1][x-1]; if(pre>=mod) pre-=mod;
			G[o][x]=G[o][x]-pre; if(G[o][x]<0) G[o][x]+=mod;
		}
		all[o]%=mod;
	}
	printf("%lld\n",(all[n&1]%mod+mod)%mod);
	return 0;
}
