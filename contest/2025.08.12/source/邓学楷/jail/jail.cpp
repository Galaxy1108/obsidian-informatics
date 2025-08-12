#include <cstdio>
#include <cstring>
#include <vector>

int n,m,s[510],t[510],diff[510],ja[510],f1[510],f2[510],vis[510],depth[510];
std::vector<int> vec[510];

bool solvechain()
{
	for (int i=1;i<=n;i++)
		ja[i]=ja[i-1]+diff[i];
	for (int i=1;i<=n;i++)
		if (f1[i] && ((ja[s[i]] && ja[s[i]]!=ja[t[i]]) || ja[t[i]]!=ja[t[i]+1]))
			return 0;
	return 1;
}

void qd(int u,int fa)
{
	depth[u]=depth[fa]+1;
	for (int v:vec[u])
		if (v!=fa)
			qd(v,u);
}

bool dfs(int u,int ta,int f[])
{
	if (u==ta)
		return 1;
	for (int v:vec[u])
	{
		if (f[v])
			continue;
		f[v]=depth[u]-depth[v];
		if (dfs(v,ta,f));
			return 1;
		f[v]=0;
	}
	return 0;
}

bool solve2()
{
	qd(1,0);
	f1[s[1]]=2,f2[s[2]]=3;
	dfs(s[1],t[1],f1);
	dfs(s[2],t[2],f2);
	if ((f1[t[2]]!=f1[s[2]] && f1[s[2]] && f1[t[2]]) || 
		(f2[t[1]]!=f2[s[1]] && f2[s[1]] && f2[t[1]]))
		return 0;
	return 1;
}

int main()
{
	freopen("jail.in","r",stdin);
	freopen("jail.out","w",stdout);
	int Q,u,v;
	bool ch=1;
	scanf("%d",&Q);
	while (Q--)
	{
		scanf("%d",&n);
		for (int i=0;i<n-1;i++)
		{
			scanf("%d%d",&u,&v);
			if (u-v!=1 && u-v!=-1)
				ch=0;
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		scanf("%d",&m);
		for (int i=1;i<=m;i++)
		{
			scanf("%d%d",s+i,t+i);
			if (ch)
			{
				if (s[i]>t[i])
					diff[t[i]]=i,diff[s[i]+1]=-i;
				else
					f1[i]=1;
			}
		}
		if (ch)
			printf(solvechain()?"Yes\n":"No\n");
		else if (m==2)
			printf(solve2()?"Yes\n":"No\n");
		else
			printf("Yes\n");
		for (int i=1;i<=n;i++)
			vec[i].clear();
		memset(ja,0,sizeof ja);
		memset(diff,0,sizeof diff);
		memset(f1,0,sizeof f1);
		memset(f2,0,sizeof f2);
		memset(depth,0,sizeof depth);
		ch=1;
	} 
	return 0;
} 
