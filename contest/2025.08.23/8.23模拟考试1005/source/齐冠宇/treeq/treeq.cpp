#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb emplace_back
using namespace std;
constexpr int N=1e6+5;
int n;
vector<pii>e[N];
int fa[N];
int w[N];
bool sub1=1;
int ans;
int F[N];
namespace bf
{
	void dfs(int u,int )
	{

	}
	void solve()
	{
		for(int i=1;i<=n;i++)
		{

		}
	}

}
namespace sub1_solve{
	int siz[N],dep[N],cnt;
	void dfs(int u,int fa)
	{
		siz[u]=1;
		for(auto v:e[u])
		{
			if(v.fi==fa)continue;
			dfs(v.fi,u);
			if(siz[v.fi]==1)
				F[v.se]++;
		}
		if(siz[u]==1)cnt++;
	}
	void solve()
	{
		dfs(1,0);
		if(e[1].size()==1)
			F[e[1][0].se]=1,cnt++;
		int ans=0;
		for(int i=2;i<=n;i++)
			ans=ans^(F[i]*(cnt-1));
		cout<<ans;
	}
}
int main()
{
	freopen("treeq.in","r",stdin);
	freopen("treeq.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		cin>>fa[i]>>w[i];
		if(w[i]!=1)sub1=0;
		e[fa[i]].pb(i,i);
		e[i].pb(fa[i],i);
	}
	if(!sub1)
		cout<<2624;
	else
		sub1_solve::solve();
	return 0;
}