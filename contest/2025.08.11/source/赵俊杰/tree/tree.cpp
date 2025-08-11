#include<bits/stdc++.h>
using namespace std;
const int N=500005;
const double eps=1e-9;
struct T
{
	int ne,to;
}e[N];
int he[N],idx;
double w[N],f[N];
void add(int x,int y)
{
	e[++idx].ne=he[x];
	e[idx].to=y;
	he[x]=idx;
}
void dfs(int x,double c)
{
	f[x]=w[x]-c;
	for(int i=he[x];i;i=e[i].ne)
	{
		int y=e[i].to;
		dfs(y,c);
		f[x]+=max(0.0,f[y]);
	}
}
bool ok(int s,double k)
{
	dfs(s,k);
	return f[s]>=0;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n;
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		add(x,i);
	}
	for(int i=1;i<=n;i++)scanf("%lf",&w[i]);
	for(int i=1;i<=n;i++)
	{
		double l=0,r=1000000000,mid;
		for(int t=1;t<=100;t++)
		{
			mid=(l+r)/2.0;
			if(ok(i,mid))l=mid;
			else r=mid;
		}
		printf("%.7lf\n",r);
	}
	return 0;
}
