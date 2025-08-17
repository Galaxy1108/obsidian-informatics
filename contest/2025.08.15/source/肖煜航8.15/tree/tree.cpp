#include<cstdio>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
int read(){
	int p=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') p=(p<<1)+(p<<3)+ch-'0',ch=getchar();
	return p*w;
}
const int N=5e5+5;
vector<int> e1[N],e2[N];
int n,f[N][21],fa[N];
ll dis[N];
int sz[N],now[N],lst[N],dfn,a[N],dep[N];
ll all[N],la[N],lb[N];
void dfs1(int u){
	dfn++;
	now[u]=dfn;
	lst[dfn]=u;
	sz[u]=1;
	dis[u]+=dis[fa[u]];
	for(int v:e1[u]){
		dfs1(v);
		sz[u]+=sz[v];
	}
}
void dfs2(int u){
	for(int i=1;i<21;i++){
		f[u][i]=f[f[u][i-1]][i-1];
	}
	int fat=f[u][0];
	dep[u]=dep[fat]+1;
	all[u]=all[fat]+1ll*dep[u]*a[u];
	la[u]=a[u]+la[fat];
	lb[u]=lb[fat]+la[u];
	for(int v:e2[u]){
		dfs2(v);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	int tmp=dep[x]-dep[y];
	for(int i=20;i>=0;i--){
		if(tmp>=(1<<i)){
			tmp-=1<<i;
			x=f[x][i];
		}
	}
	if(x==y) return x;
	for(int i=20;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
ll get(int x,int y){
	int lc=lca(x,y);
	return la[x]+la[y]-2*la[lc]+a[lc];
}
ll solve(int s,int t){
	if(s==t) return 0;
	int lc=lca(s,t);
	ll sum=0;
	if(s!=lc){
		sum+=lb[s];
		sum-=lb[lc];
		sum-=1ll*la[lc]*(dep[s]-dep[lc]);
	}
	ll op=la[t]-la[fa[lc]];
	sum+=all[t]-all[fa[lc]]-op*(dep[lc]-1)+op*(dep[s]-dep[lc]);
	return sum-get(s,t);
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read();
	for(int i=2;i<=n;i++){
		fa[i]=read();
		e1[fa[i]].push_back(i);
	}
	for(int i=2;i<=n;i++) dis[i]=read();
	for(int i=2;i<=n;i++){
		f[i][0]=read();
		e2[f[i][0]].push_back(i);
	} 
	for(int i=1;i<=n;i++) a[i]=read();
	dfs1(1);
	dfs2(1); 
	for(int i=1;i<=n;i++){
		ll mx=-1e18;
		for(int j=now[i];j<now[i]+sz[i];j++){
			int v=lst[j];
			ll sum=0;
			sum+=dis[v]-dis[i];
			sum+=solve(v,i);
			mx=max(mx,sum);
		}
		printf("%lld ",mx);
	}
	return 0;
}
