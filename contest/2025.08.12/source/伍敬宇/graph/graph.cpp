#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
int n,m,k;
int U[112],V[112];
vector<int> ton[112][112];
int deg[112];
int pre[112];
int find(int x) {return (x==pre[x])?x:pre[x] = find(pre[x]);}
inline int lowbit(int x) {return x&(-x);}
inline int count(int x)
{
	int cnt = 0;
	while (x)
	{
		cnt++;
		x -= lowbit(x);
	}
	return cnt;
}
void solve(int s)
{
	for (int i=1;i<=n;i++) deg[i] = 0,pre[i] = i;
	for (int i=1;i<=m;i++)
		if (s&(1<<(i-1)))
			deg[U[i]]++,deg[V[i]]++,pre[find(U[i])]=find(V[i]);
	int fl = -1;
	for (int i=1;i<=m;i++)
		if (s&(1<<(i-1)))
		{
			if (fl==-1) fl = find(U[i]);
			if (fl!=find(U[i])||fl!=find(V[i])) return ;
		}
	int cnt = 0;
	int stk[4];
	for (int i=1;i<=n;i++)
	{
		if (deg[i]>=3) return ;
		if (deg[i]==1)
		{
			stk[++cnt] = i;
			if (cnt>2) return ;
		}
	}
	if (cnt!=2) return ;
	int u = stk[1],v = stk[2];
	if (u>v) swap(u,v);
	ton[u][v].push_back(s);
}
int sta[(1<<21)];
void print(int s,int u)
{
	printf("%d ",u);
	for (int i=1;i<=m;i++)
		if (s&(1<<(i-1)))
			if (U[i]==u) print(s^(1<<(i-1)),V[i]);
			else if (V[i]==u) print(s^(1<<(i-1)),U[i]);
}
bool dfs(int u,int v,int id,int cnt,int s)
{
	if (cnt>=k) 
	{
		return 1;
	}
	if (id>=ton[u][v].size()) return 0;
	sta[ton[u][v][id]] = 0;
	if (dfs(u,v,id+1,cnt,s)) return 1;
	if ((s&ton[u][v][id])==0)
	{
		sta[ton[u][v][id]] = 1;
		if (dfs(u,v,id+1,cnt+1,s|ton[u][v][id])) return 1;
		sta[ton[u][v][id]] = 0;
	}
	return 0;
}
void work()
{
	scanf("%d%d",&n,&m);
	k = (m+(n-1)-1)/(n-1);
	for (int i=1;i<=m;i++)
		scanf("%d%d",U+i,V+i);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			ton[i][j].clear();
	for (int s=0;s<(1<<m);s++) solve(s),sta[s] = 0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (ton[i][j].size()>=k)
				if (dfs(i,j,0,0,0))
				{
					printf("%d %d\n",i,j);
					int cnt = 0;
					for (int s=0;s<(1<<m);s++)
						if (sta[s]==1)
						{
							printf("%d ",count(s)+1);
							print(s,i);
							printf("\n");
						}
					return ;
				}
	printf("-1\n");
}
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--) work();
	return 0;
}
