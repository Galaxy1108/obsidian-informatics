#include<bits/stdc++.h>
using namespace std;
int q,w[1000005],ggg[100005],v[1000005],nxt[5000005],fst[1000005],fa[500005],dep[500005],f[500005][25],n,m,s,x,y,now;
bool fff[100005];
void add(int x,int y)
{
	now++;
	v[now]=y;
	nxt[now]=fst[x];
	fst[x]=now;
}
void dfs(int x,int faa)
{
	ggg[x]=ggg[faa]+fff[x];
	dep[x]=dep[faa]+1;
	f[x][0]=faa;
	for(int i = 1; (1<<i) <= dep[x]; i++)
	{
		f[x][i]=f[f[x][i-1]][i-1];
	}
	for(int i = fst[x]; i; i = nxt[i])
	{
		if(v[i]!=faa)
		{
			dfs(v[i],x);
		}
	}
	return;
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	int les=dep[x]-dep[y];
	for(int i = 20; i >= 0; i--)
	{
		if(les&(1<<i))
		{
			x=f[x][i];
		}
	}
	if(x==y) return x;
	for(int i = 20; i >= 0; i--)
	{
		if(f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
int main()
{
	freopen("currencies.in","r",stdin);
	freopen("currencies.out","w",stdout);
	cin>>n>>m>>q;
	for(int i = 1; i < n; i++)
	{
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	int pp;
	for(int i = 1; i <= m; i++)
	{
		cin>>x>>y;
		pp=y;
		fff[x]=1;
	}
	dfs(1,0);
	int xx,yy;
	for(int i = 1; i <= q; i++)
	{
		cin>>x>>y>>xx>>yy;
		yy=yy/pp;
		int noww=ggg[x]+ggg[y]-ggg[lca(x,y)]-ggg[f[lca(x,y)][0]];
		if(noww>xx+yy) cout<<-1<<endl;
		else cout<<min(xx+yy-noww,xx)<<endl;
	}
}
