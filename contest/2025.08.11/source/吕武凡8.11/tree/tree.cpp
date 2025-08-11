#include<bits/stdc++.h>
using namespace std;
long long n;
long long fa[500010];
long long w[500010];
unsigned long long sum[500010];
long long num[500010];
long long ins[500010];
long long head[500010];
long long tot=0;
struct Edge
{
	long long nx,to;
}e[500010];
void edge(int u,int v)
{
	e[++tot].nx=head[u];
	e[tot].to=v;
	head[u]=tot;
}
long double calc(long long x)
{
	return (1ll*sum[x]*1.0)/(1ll*num[x]*1.0);
}
bool cmp(long long x,long long y)
{
	return 1ll*sum[x]*num[y]>1ll*sum[y]*num[x];
}
void DFS(long long x)
{
	if(ins[x]==0)
	{
		num[x]=1;
		return;
	}
	long long er[500010];
	long long len=0;
	for(int i=head[x];i;i=e[i].nx)
	{
		long long y=e[i].to;
		er[++len]=y;
		DFS(y);
	}
	sort(er+1,er+len+1,cmp);
	for(int i=1;i<=len;i++)
	{
		long long y=er[i];
		if(cmp(y,x))
		{
			sum[x]+=sum[y];
			num[x]+=num[y];
		}
	}
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		cin>>fa[i];
		edge(fa[i],i);
		ins[fa[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>sum[i];
		num[i]=1;
	}
	DFS(1);
	for(int i=1;i<=n;i++)
	{
		//cout<<sum[i]<<" "<<num[i]<<" "<<i<<endl;
		cout<<fixed<<setprecision(10)<<(1ll*sum[i]*1.0)/(1ll*num[i]*1.0)<<endl;
	}
}
/*
6 
1 2 2 1 4 
3 1 5 6 6 7
*/
