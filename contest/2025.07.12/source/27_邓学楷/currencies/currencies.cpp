#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pil;
typedef pair<int,pil> edge;

const int N=100010;
int n,m,q,u[N],v[N],w1[N],ans=-1;
bool vis[N],flag;
ll w2[N];
vector<edge> vec[N];

void dfs(int cur,int end,int au,ll ag)
{
	if (vis[cur] || flag)
		return;
	vis[cur]=1;
	if (cur==end)
	{
		ans=au;
		flag=1;
		return;
	}
	for (auto ne:vec[cur])
	{
		if (ag>=ne.second.second)
			dfs(ne.first,end,au,ag-ne.second.second);
		else
			dfs(ne.first,end,au-ne.second.first,ag);
	}
}

int main()
{
	freopen("currencies.in","r",stdin);
	freopen("currencies.out","w",stdout);
	int a,b,x;
	ll y;
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		u[i]=a,v[i]=b;
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d%lld",&a,&y);
		w1[a]++;
		w2[a]+=y;
	}
	for (int i=1;i<n;i++)
	{
		vec[u[i]].push_back(edge(v[i],pil(w1[i],w2[i])));
		vec[v[i]].push_back(edge(u[i],pil(w1[i],w2[i])));
	}
	while (q--)
	{
		scanf("%d%d%d%lld",&a,&b,&x,&y);
		dfs(a,b,x,y);
		printf("%d\n",ans);
		memset(vis,0,sizeof vis);
		ans=-1;
	}
	return 0;
}
