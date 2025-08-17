#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define il inline
const int N=5e5+5;
int n,fff[N],fat[N],dep[N];
ll ans[N],a[N],dis[N];
struct edge
{
	int v,w,nxt;
}e[N<<1];
int head[N],et=0;
il void add(int u,int v,int w)
{
	e[++et].v=v;
	e[et].nxt=head[u],e[et].w=w;
	head[u]=et;
}
int g[N][25];
il int lca(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	for(int i=20;i>=0;i--)if(dep[g[u][i]]>=dep[v])u=g[u][i];
	if(u==v)return u;
	for(int i=20;i>=0;i--)
	{
		if(g[u][i]!=g[v][i])
		{
			u=g[u][i],v=g[v][i];
		}
	}
	return g[u][0];
}
il void dfs(int u,int fa,ll di)
{
//	cout<<u<<' ';
	g[u][0]=fa,dis[u]=di,dep[u]=dep[fa]+1;
	for(int i=1;i<=20;i++)g[u][i]=g[g[u][i-1]][i-1];
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].v,w=e[i].w;
		if(v==fa)continue;
		dfs(v,u,di+w);
	}
}
il void jump(int u,int s,ll now,ll step)
{
//	cout<<u<<' '<<s<<' '<<now<<' '<<dis[s]+dis[u]-2*dis[lca(u,s)]<<'\n';
	ans[u]=max(ans[u],now+dis[s]+dis[u]-2*dis[lca(u,s)]);
	if(u==1)return;
	jump(fat[u],s,now+step*a[fat[u]],step+1);
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=2;i<=n;i++)cin>>fff[i];
	for(int i=2,w;i<=n;i++)
	{
		cin>>w;
		add(fff[i],i,w),add(i,fff[i],w);
	}
	for(int i=2;i<=n;i++)cin>>fat[i];
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,0);
//	cout<<lca(1,4)<<' ';
//	for(int i=1;i<=n;i++)cout<<dis[i]<<' ';
	for(int i=2;i<=n;i++)jump(i,i,0,1);
	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
	return 0;
}

