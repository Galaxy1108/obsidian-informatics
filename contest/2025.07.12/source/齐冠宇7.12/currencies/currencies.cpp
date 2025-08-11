#include<bits/stdc++.h>
#define pb emplace_back
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
constexpr int N=1e5+5;
int n,m,q;
int cnt;
vector<int>c[N]
int dep[N],fa[N],tf[N];
vector<int>e[N];
bool sub1=1;
priority_queue<int,vector<int>,greater<int>q;
int f[N][20];
void dfs(int u,int ff)
{
	f[u][0]=ff;
	dep[u]=dep[ff]+1;
	fa[u]=ff;
	for(auto v:e[u])
	{
		if(v.fi==fa)
			continue;
		dfs(v.fi,u);
	}
}
void add(int& x)
{
	cnt+=c[tf[x]].size();
	if(!sub)
		for(auto v:c[tf[x]])
			q.push(v);
	x=fa[x];
}
int main()
{
	freopen("currencies.in","r",stdin);
	freopen("currencies.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].pb(mp(v,i));
		e[v].pb(mp(u,i));
	}
	int las=0;
	dfs(1,0);
	for(int i=1;i<=m;i++)
	{
		int p,cc;
		scanf("%d%d",&p,&cc);
		c[p].pb(cc);
		if(i!=1 && las!=cc)
			sub1=0;		
		las=cc;
	}
	while(q--)
	{
		int u,v,xk,yk;
		scanf("%d%d%d%d",&u,&v,&xk,&yk);
		while(!q.empty())q.pop();
		cnt=0;
		if(sub1)
		{
			
		}
	}
	return 0;
}
