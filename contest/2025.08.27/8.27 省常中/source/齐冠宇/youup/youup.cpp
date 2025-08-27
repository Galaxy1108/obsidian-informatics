#include <bits/stdc++.h>
#define vi vector<int>
#define pb emplace_back
#define ppc __builtin_popcount
using namespace std;
constexpr int N=22,R=3e5+5,mod=998244353; 
int cid;
int n,x;
vi e[N];
int fa[N],dep[N],siz[N],son[N],top[N];
void dfs1(int u,int fa)
{
	::fa[u]=fa;
	dep[u]=dep[fa]+1;
	siz[u]=1;
	for(auto v:e[u])
	{
		if(v==fa)continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[son[u]]<siz[v])
			son[u]=v;
	}
}
void dfs2(int u,int top)
{
	::top[u]=top;
	if(son[u])
		dfs2(son[u],top);
	for(auto v:e[u])
	{
		if(v==son[u] || v==fa[u])continue;
		dfs2(v,v);
	}
}
int lca(int u,int v)
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]])
			swap(u,v);
		u=fa[top[u]];
	}
	return dep[u]>dep[v]?v:u;
}
int dis(int u,int v)
{
	return dep[u]+dep[v]-dep[lca(u,v)]*2;
}
int ans[R];
bool nt[N][N];
int main()
{
	freopen("youup.in","r",stdin);
	freopen("youup.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>cid>>n>>x;
	for(int i=1,u,v;i<n;i++)
		cin>>u>>v,e[u].pb(v),e[v].pb(u);
	if(e[1].size()==n-1)
	{
		if(x==0)
			ans[1]=n;
		else if(x==1)
			ans[1]=n,ans[2]=n-1; 
		else if(x==2)
			ans[1]=n,ans[2]=(n-1+(1ll*(n-1)*(n-2)/2)%mod)%mod,ans[3]=(1ll*(n-1)*(n-2)/2)%mod;
		for(int i=1;i<=n;i++)
			cout<<ans[i]<<' ';
		return 0;
	}
	dfs1(1,0);
	dfs2(1,1);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			nt[i][j]=dis(i,j)<=x;
	ans[1]=n;
	for(int S=1;S<(1<<n);S++)
	{
		if(ppc(S)==1)
			continue;
		bool fl=1;
		for(int i=1;i<=n && fl;i++)
			if(S&(1<<(i-1)))
				for(int j=i+1;j<=n;j++)
					if(S&(1<<(j-1)))
						if(!nt[i][j])
						{
							fl=0;
							break;
						}
		ans[ppc(S)]+=fl;
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<' ';
	return 0;
}
