#include<cstdio>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
int read(){
	int p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=(p<<1)+(p<<3)+ch-'0',ch=getchar();
	return p;
}
const int N=1e6+5;
bool st;
vector<pair<int,int> > e[N];
vector<ll> pre[N],nxt[N];
int n,fa[N],sz[N],son[N];
ll up[N];
ll b[N<<1];
ll a[N];
int tot,m;
int al[N<<1];
int c[N<<1];
int ans;
void dfs1(int u){
	sz[u]=1;
	for(pair<int,int> v:e[u]){
		dfs1(v.first);
		sz[u]+=sz[v.first];
		if(sz[v.first]>sz[son[u]]) son[u]=v.first;
	}
}
void dfs(int u,ll f){
	a[u]=max(a[u],f);
	ll mx=0; 
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i].first;
		ll w=e[u][i].second;
		b[++tot]=w*sz[v];
		up[u]=max(up[u],w*sz[v]);	
		mx=max(mx,max(w*sz[v],up[v]));
		pre[u].push_back(mx);
	}
	mx=0;
	for(int i=e[u].size()-1;i>=0;i--){
		int v=e[u][i].first;
		ll w=e[u][i].second;
		mx=max(mx,max(w*sz[v],up[v]));
		nxt[u].push_back(mx);
	}
	reverse(nxt[u].begin(),nxt[u].end());
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i].first;
		ll w=e[u][i].second;
		b[++tot]=w*(n-sz[v]);
		ll d=w*(n-sz[v]);
		d=max(d,f);
		if(i) d=max(d,pre[u][i-1]);
		if(i<e[u].size()-1) d=max(d,nxt[u][i+1]);
		dfs(v,d);		
	}
	up[fa[u]]=max(up[fa[u]],up[u]);
	a[u]=max(a[u],up[u]);
}
int dfn[N],L[N],R[N],low[N],tim;
void solve(int u,bool limit){
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i].first;
		ll w=e[u][i].second;
		if(v==son[u]) continue;
		solve(v,0);
		for(int j=L[v];j<=R[v];j++) c[a[low[j]]]++;
		int sum=0;
		int o=lower_bound(b+1,b+m+1,w*(n-sz[v]))-b;
		sum+=c[o];
		o=lower_bound(b+1,b+m+1,w*sz[v])-b;
		sum+=al[o]-c[o];
		ans^=sum;
		for(int j=L[v];j<=R[v];j++) c[a[low[j]]]--;
	}
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i].first;
		ll w=e[u][i].second;
		if(v!=son[u]) continue;
		solve(v,1);
		int sum=0;
		int o=lower_bound(b+1,b+m+1,w*(n-sz[v]))-b;
		sum+=c[o];
		o=lower_bound(b+1,b+m+1,w*sz[v])-b;
		sum+=al[o]-c[o];
		ans^=sum; 
	}
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i].first;
		ll w=e[u][i].second;
		if(v==son[u]) continue;
		for(int j=L[v];j<=R[v];j++) c[a[low[j]]]++;
	}
	c[a[u]]++;
	if(!limit){
		for(int i=L[u];i<=R[u];i++) c[a[low[i]]]--;
	}
}
void dfs3(int u){
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i].first;
		ll w=e[u][i].second;
		dfs3(v);
		up[u]=max(up[u],sz[v]*w);
		up[u]=max(up[u],up[v]);
	}	
}
void dfs2(int u){
	tim++;
	dfn[u]=tim;
	low[tim]=u;
	L[u]=tim;
	R[u]=tim+sz[u]-1;
	for(int i=0;i<e[u].size();i++) dfs2(e[u][i].first);
}
bool ed;
int main(){
	freopen("treeq.in","r",stdin);
	freopen("treeq.out","w",stdout);
	n=read();
	for(int i=2;i<=n;i++){
		fa[i]=read();
		int x=read();
		e[fa[i]].push_back(make_pair(i,x));
	}
	dfs1(1);
	dfs3(1);
	dfs(1,0);
	dfs2(1);
	sort(b+1,b+tot+1);
	m=unique(b+1,b+tot+1)-b-1;
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(b+1,b+m+1,a[i])-b;
		al[a[i]]++;
	}
	solve(1,0);
	printf("%d",ans);
	return 0;
}
