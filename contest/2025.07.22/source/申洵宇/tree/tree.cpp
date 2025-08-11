#include <bits/stdc++.h>
using namespace std;
#define N 5005
#define MOD 998244353ll
struct seg{
	int l,r;
}fs[N];
struct edge{
	int u,v,w;
}eq[N];
int n,m,f[N];
long long val[N],cnt; 
int dep[N];
long long mpow(long long b,long long p){
	long long res=1;
	while(p){
		if(p&1)res=res*b%MOD;
		p>>=1;
		b=b*b%MOD;
	}
	return res;
}
void check(){
	dep[1]=1;
	for(int i=2;i<=n;i++){
		dep[i]=dep[f[i]]+1;
	}
	for(int i=1;i<=m;i++){
		int u=eq[i].u,v=eq[i].v;
		if(dep[u]<dep[v])swap(u,v);
		while(dep[u]>dep[v]){
			val[u]+=eq[i].w;
			if(val[u]>=MOD)val[u]-=MOD;
			u=f[u];
		} 
		if(u==v)continue;
		while(u!=v){
			val[u]+=eq[i].w;
			if(val[u]>=MOD)val[u]-=MOD;
			val[v]+=eq[i].w;
			if(val[v]>=MOD)val[v]-=MOD;
			u=f[u],v=f[v];
		}
	}
}
void dfs_choose(int x){
	if(x>n){
		cnt++;
		while(cnt>=MOD){cnt-=MOD;break;}
		check();
		return ;
	}
	for(f[x]=fs[x].l;f[x]<=fs[x].r;f[x]++){
		dfs_choose(x+1);
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		scanf("%d%d",&fs[i].l,&fs[i].r);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&eq[i].u,&eq[i].v,&eq[i].w);
		eq[i].w%=MOD;
	}
	f[1]=0;
	dfs_choose(2);
	cnt=mpow(cnt,MOD-2);
	for(int i=2;i<=n;i++){
		printf("%lld ",val[i]*cnt%MOD);
	}
	return 0;
}

