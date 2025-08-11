#include <cstdio>
#include <vector>
typedef long long ll;

int n,w[500010],sz[500010];
ll ans[500010];
std::vector<int> vec[500010];

void dfs(int u,int f)
{
	sz[u]=1;
	ans[u]+=w[u];
	for (int v:vec[u])
	{
		if (v==f)
			continue;
		dfs(v,u);
		if ((double)ans[u]/sz[u]<(double)(ans[u]+ans[v])/(sz[u]+sz[v]))
		{
			ans[u]+=ans[v];
			sz[u]+=sz[v];
		}
	} 
}

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int p;
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
	{
		scanf("%d",&p);
		vec[i].push_back(p);
		vec[p].push_back(i);
	}
	for (int i=1;i<=n;i++)
		scanf("%d",w+i);
	dfs(1,0);
	for (int i=1;i<=n;i++)
		printf("%.10lf\n",(double)ans[i]/sz[i]);
	return 0;
}
