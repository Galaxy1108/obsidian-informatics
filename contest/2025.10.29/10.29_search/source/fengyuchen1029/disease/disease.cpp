#include<bits/stdc++.h>
#define il inline
#define ll long long
using namespace std;
const int N=305;
vector<int> g[N];
int dep[N],sz[N],p[N];
bool vis[N];
il void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1;
	sz[u]=1;
	for(int v:g[u])
	{
		if(v==fa) continue;
		p[v]=u;
		dfs(v,u);
		sz[u]+=sz[v];
	}
}
ll ans;
il void solve()
{
	int cur=0,pre=1;
	queue<int> q;
	q.push(1);
	while(q.size())
	{
		int u=q.front();q.pop();
		if(dep[u]!=pre)
			pre=dep[u],vis[cur]=1,ans-=sz[cur],cur=0;
		for(int v:g[u])
		{
			if(vis[p[v]]) continue;
			if(v==p[v]) continue;
			if(sz[v]>cur) cur=v;
			q.push(v);
		}
//		cout<<ans<<'\n';
	}
	cout<<ans<<'\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("disease.in","r",stdin);
	freopen("disease.out","w",stdout);
	int n,m,u,v;
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>u>>v;
		g[u].push_back(v);g[v].push_back(u);
	}
	for(int i=1;i<=n;++i) p[i]=i;
	dfs(1,0);
//	for(int i=1;i<=n;++i) cout<<i<<sz[i]<<dep[i]<<'\n';
	ans=n;
	solve();
	return 0;
}
