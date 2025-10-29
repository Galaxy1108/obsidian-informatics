#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct edge{int s,t,n;}e[100000];
int n,m,tot,oh[305],h[305],mp[305][305],dep[305],dfn[305][2],siz[305],f[305],S[305],res,ans;

void dfs(int x,int f)
{
	dfn[x][0]=++dfn[0][0],dep[x]=dep[f]+1,siz[x]=1;
	for (int i=oh[x],y; y=e[i].t,i; i=e[i].n)
		if (y!=f)  dfs(y,x),siz[x]+=siz[y];
	dfn[x][1]=dfn[0][0];
}

bool check(int x,int y)
{
	if (dep[x]==dep[y])  return 0;
	if (dep[x]>dep[y])  swap(x,y);
	if ((dfn[x][0]<dfn[y][0])&&(dfn[y][0]<=dfn[x][1]))  return 0;
	return 1;
}

void dfs(int x,int t,int s)
{
	if (s>res)  res=s;
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if (S[y]==t-1)  S[y]++;
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if (S[y]==t)
			{
				if (s+f[y]>res)  dfs(y,t+1,s+siz[y]);
				S[y]--;
			}
}

void work()
{
	scanf("%d %d",&n,&m);
	for (int i=1,x,y; i<=m; i++)
		{
			scanf("%d %d",&x,&y);
			e[++tot]=(edge){x,y,oh[x]},oh[x]=tot;
			e[++tot]=(edge){y,x,oh[y]},oh[y]=tot;
		}
	dfs(1,0);
	for (int i=2; i<=n; i++)
		for (int j=i+1; j<=n; j++)
			if (check(i,j))
				e[++tot]=(edge){i,j,h[i]},h[i]=tot;
	for (int i=n; i>=2; i--)
		{
			res=0,dfs(i,1,siz[i]);
			f[i]=res,ans=max(ans,res);
		}
	printf("%d",n-ans);
}

int main()
{
	freopen("disease.in","r",stdin);
	freopen("disease.out","w",stdout);
	work();
	return 0;
}
