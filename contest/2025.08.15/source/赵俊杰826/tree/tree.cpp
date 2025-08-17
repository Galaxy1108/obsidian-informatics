#include<bits/stdc++.h>
using namespace std;
const int N=500005;
typedef long long ll;
struct T
{
	int ne,to,v;
}e[2][N];
int he[2][N],idx[2],d[2][N],fa[2][N],sz[N],son[N],top[N];
ll f[2][N],a[N],ans;
void add(int t,int x,int y,int z)
{
	e[t][++idx[t]].ne=he[t][x];
	e[t][idx[t]].to=y;
	e[t][idx[t]].v=z;
	he[t][x]=idx[t];
}
void dfs1(int x)
{
	d[0][x]=d[0][fa[0][x]]+1;sz[x]=1;
	f[0][x]+=f[0][fa[0][x]];
	for(int i=he[0][x];i;i=e[0][i].ne)
	{
		int y=e[0][i].to;
		f[0][y]+=e[0][i].v;
		dfs1(y);
		sz[x]+=sz[y];
		if(sz[y]>sz[son[x]])son[x]=y;
	}
}
void dfs2(int x,int t)
{
	top[x]=t;
	if(son[x])dfs2(son[x],t);
	for(int i=he[0][x];i;i=e[0][i].ne)
	{
		int y=e[0][i].to;
		if(y==son[x])continue;
		dfs2(y,y);
	}
}
int lca(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(d[top[x]]<d[top[y]])swap(x,y);
		x=fa[0][top[x]];
	}
	if(d[0][x]>d[0][y])swap(x,y);
	return x;
}
ll dis(int x,int y)
{
	return f[0][x]+f[0][y]-2*f[0][lca(x,y)];
}
void dfs3(int x)
{
	f[1][x]=a[x];
	f[1][x]+=f[1][fa[1][x]];
	for(int i=he[1][x];i;i=e[1][i].ne)
	{
		int y=e[1][i].to;
		dfs3(y);
	}
}
void get(int u,int x,ll s)
{
	ans=max(ans,dis(x,u)+s);
	s+=f[1][x]-f[1][fa[1][u]];
	for(int i=he[1][x];i;i=e[1][i].ne)
	{
		int y=e[1][i].to;
		get(u,y,s);
	}
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=2;i<=n;i++)cin>>fa[0][i];
	for(int i=2;i<=n;i++)
	{
		int w;
		cin>>w;
		add(0,fa[0][i],i,w);
	}
	for(int i=2;i<=n;i++)
	{
		cin>>fa[1][i];
		add(1,fa[1][i],i,0);
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs1(1);
	dfs2(1,1);
	dfs3(1);
	for(int i=1;i<=n;i++)
	{
		ans=-1e18;
		get(i,i,0);
		cout<<ans<<' ';
	}
	cout<<'\n';
	return 0;
}
