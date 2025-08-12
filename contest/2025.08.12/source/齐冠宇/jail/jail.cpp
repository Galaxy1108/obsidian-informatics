#include <bits/stdc++.h>
#define debug(x) cout<<#x<<' '<<x<<'\n';
#define vi vector<int>
#define pb emplace_back
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define id(x,y) (((x)-1)*20+(y)+1)
using namespace std;
constexpr int N=1.2e5+5,V=8e6+5;
int T;
int n,m;
vector<int>e[N<<1];
int f[N<<1][20];
int idx;
int dfn[N<<1],dep[N<<1],siz[N<<1];
vi ne[V];
int d[V];
void dfs(int u,int fa)
{
	dfn[u]=++idx;
	f[u][0]=fa;
	dep[u]=dep[fa]+1;
	siz[u]=1;
	for(int i=1;i<20;i++)
		f[u][i]=f[f[u][i-1]][i-1];
	for(auto v:e[u])
	{
		if(v==fa)
			continue;
		dfs(v,u);
		siz[u]+=siz[v];
	}
}
inline int fr(int u,int d)
{
	for(int i=19;~i;i--)
		if(d&(1<<i))
			u=f[u][i];
	return u;
}
inline vi getfr(int u,int d)
{
	vi res;
	for(int i=19;~i;i--)
		if(d&(1<<i))
			res.pb(id(u,i)),u=f[u][i];
	return res;
}
inline int lca(int u,int v)
{
	if(dep[u]<dep[v])
		swap(u,v);
	for(int i=19;~i;i--)
		if(dep[f[u][i]]>=dep[v])
			u=f[u][i];
	if(u==v)
		return u;
	for(int i=19;~i;i--)
		if(f[u][i]!=f[v][i])
			u=f[u][i],v=f[v][i];
	return f[u][0];
}
inline vi getpa(int u,int v)
{
	int l=lca(u,v);
//	debug(u);
//	debug(v);
//	debug(l);
	vi fru=getfr(u,dep[u]-dep[l]+1);
	vi frv=getfr(v,dep[v]-dep[l]+1);
//	cout<<fru[0]<<' '<<frv[0]<<' ';
	for(auto val:frv)fru.pb(val);
//	cout<<fru[0]<<' '<<fru[1]<<' ';
	return fru;
}
inline int nxt(int u,int v)
{
	return (dfn[v]>dfn[u] && dfn[v]<dfn[u]+siz[u])?fr(v,dep[v]-dep[u]-1):f[u][0];
}
inline bool topo(int n)
{
	for(int i=1;i<=n;i++)
		for(auto v:ne[i])
			d[v]++;
	queue<int>q;
	int tim=0;
	for(int i=1;i<=n;i++)
		if(!d[i])
			q.push(i);
	while(!q.empty())
	{
		int u=q.front();
		tim++;
		q.pop();
		for(auto v:ne[u])
			if(!(--d[v]))
				q.push(v);
	}
	for(int i=1;i<=n;i++)
		d[i]=0;
	return n==tim;
}
inline void init()
{
	for(int i=1;i<=n;i++)
	{
		e[i].clear();
		for(int j=0;j<20;j++)
			f[i][j]=0;
	}
	idx=0;
}
int main()
{
	freopen("jail.in","r",stdin);
	freopen("jail.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		init();
		for(int i=1,u,v;i<n;i++)
			cin>>u>>v,e[u].pb(v),e[v].pb(u);
		dfs(1,0);
		int tot=id(n,19);
//		debug(tot);
		cin>>m;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=19;j++)
			{
				ne[m+id(i,j-1)].pb(m+id(i,j));
				if(f[i][j-1])
					ne[m+id(f[i][j-1],j-1)].pb(m+id(i,j));
				ne[m+tot+id(i,j)].pb(m+tot+id(i,j-1));
				if(f[i][j-1])
					ne[m+tot+id(i,j)].pb(m+tot+id(f[i][j-1],j-1));
			}
		for(int i=1,u,v;i<=m;i++)
		{
			cin>>u>>v;
			int nu=nxt(u,v),nv=nxt(v,u);
//			debug(nu);
//			debug(nv);
			vi pu=getpa(nu,v),pv=getpa(u,nv);
//			for(auto v:pu)
//				cout<<v<<' ';
//			cout<<'\n';
//			for(auto v:pv)
//				cout<<v<<' ';
//			cout<<'\n';
			for(auto x:pu)
				ne[x+m].pb(i);
			ne[i].pb((u-1)*20+1+m);
			for(auto x:pv)
				ne[i].pb(x+m+tot);
			ne[(v-1)*20+1+m+tot].pb(i);
		}
		if(topo(m+(tot<<1)))
			cout<<"Yes\n";
		else
			cout<<"No\n";
		for(int i=1;i<=m+(tot<<1);i++)
			ne[i].clear();
	}
	return 0;
}
