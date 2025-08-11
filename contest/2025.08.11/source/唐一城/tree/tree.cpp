#include <bits/stdc++.h>
using namespace std;
#define il inline
#define ll long long
const int N=5e5+5;
int n;
double a[N],f[N],w[N];
struct edge {
	int v,nxt;
}e[N<<1];
int head[N],et=0;
il void add(int u,int v)
{
	e[++et].v=v;
	e[et].nxt=head[u];
	head[u]=et;
}
il void dfs(int u,int fa)
{
	f[u]=a[u];
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa)continue;
		dfs(v,u);
		if(f[v]>0)f[u]+=f[v];
	}
}
il int check(double mid,int s)
{
	for(int i=1;i<=n;i++)a[i]=w[i]-mid;
	dfs(1,0);
	if(f[s]>=0)return 1;
	return 0;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=2,x;i<=n;i++)
	{
		cin>>x;
		add(i,x),add(x,i);
	}
	double mx=0;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
		mx=max(mx,w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		double l=0,r=mx,mid,lst;
		while(r-l>1e-7)
		{
			mid=(l+r)/2;
			if(check(mid,i))l=mid+1e-7;
			else r=mid-1e-7;
		}
		printf("%.6lf\n",l);
	}
	
	return 0;
}

