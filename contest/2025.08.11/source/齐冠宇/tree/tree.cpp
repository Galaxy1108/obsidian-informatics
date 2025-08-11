#include <bits/stdc++.h>
#define pb emplace_back
using namespace std;
typedef double db;
typedef long long ll;
constexpr int N=5e5+5;
constexpr db eps=1e-10;
int n,fa[N],val[N];
db ans[N];
vector<int>e[N];
bool sub1=1;
namespace bf
{
int siz[N]={};
ll f[1005][1005]={};
void dfs(int u)
{
	ans[u]=val[u];
	f[u][1]=val[u];
	siz[u]=1;
	if(e[u].size())
	{
		for(auto v:e[u])
		{
			dfs(v);
			for(int i=siz[u]+siz[v];i;i--)
				for(int j=max(1,i-siz[u]);j<=min(siz[v],i-1);j++)
					f[u][i]=max(f[u][i],f[u][i-j]+f[v][j]);
			siz[u]+=siz[v];
		}
		for(int i=1;i<=siz[u];i++)
			ans[u]=max(ans[u],1.0*f[u][i]/i);
	}
}
}
namespace sub
{
ll sum[N]={},f[N][4]={};
int g[N][4]={},cnt[N]={};
void dfs(int u)
{
	ans[u]=val[u];
	sum[u]=val[u];
	cnt[u]=1;
	if(e[u].size())
	{
		for(auto v:e[u])
			dfs(v);
		for(int S=0;S<(1<<e[u].size());S++)
			f[u][S]=val[u],g[u][S]=1;
		for(int S=0;S<(1<<e[u].size());S++)
			for(int i=0;i<e[u].size();i++)
				if(S&(1<<i))
					f[u][S]+=sum[e[u][i]],g[u][S]+=cnt[e[u][i]];
		for(int S=0;S<(1<<e[u].size());S++)
		{
			db nans=1.0*f[u][S]/g[u][S];
			if(ans[u]-nans<eps)
				ans[u]=nans,sum[u]=f[u][S],cnt[u]=g[u][S];
			if(ans[u]-nans==eps && cnt[u]>g[u][S])
				sum[u]=f[u][S],cnt[u]=g[u][S];
		}
	}
}
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&fa[i]),e[fa[i]].pb(i);
		if(fa[i]!=i/2)sub1=0;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&val[i]);
	if(!sub1)
		bf::dfs(1);
	else
		sub::dfs(1);
	for(int i=1;i<=n;i++)
		printf("%.8lf\n",ans[i]);
	return 0;
} 
