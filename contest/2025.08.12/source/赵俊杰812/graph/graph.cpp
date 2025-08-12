#include<bits/stdc++.h>
using namespace std;
const int N=1005;
struct T
{
	int ne,to,v;
}e[2*N];
int he[N],idx=1,q[N],d[N],n,m,k,now[N],top;
vector<int>c[N];
void add(int x,int y)
{
	e[++idx].ne=he[x];
	e[idx].to=y;
	e[idx].v=1;
	he[x]=idx;
}
int bfs(int s,int t)
{
	for(int i=1;i<=n;i++)d[i]=0;
	now[s]=he[s];
	int l=1,r=0;
	q[++r]=s;
	d[s]=1;
	while(r>=l)
	{
		int x=q[l];l++;
		for(int i=he[x];i;i=e[i].ne)
		{
			int y=e[i].to;
			if(d[y]||!e[i].v)continue;
			now[y]=he[y];
			d[y]=d[x]+1;
			q[++r]=y;
			if(y==t)return 1;
		}
	}
	return 0;
}
int dfs(int x,int t,int flow)
{
	if(!flow)return 0;
	if(x==t)return flow;
	int sum=0;
	for(int i=now[x];i;i=e[i].ne)
	{
		now[x]=i;
		int y=e[i].to;
		if(d[y]<=d[x]||!e[i].v)continue;
		int c=dfs(y,t,min(flow,e[i].v));
		if(!c)d[y]=0;
		sum+=c;
		flow-=c;
		e[i].v-=c;
		e[i^1].v+=c;
	}
	return sum;
}
int dfs_(int x,int t,int flow)
{
	//cout<<x<<' '<<t<<' '<<flow<<'\n';
	if(!flow)return 0;
	if(x==t)
	{
		c[top].push_back(t);
		//cout<<t<<'\n';
		top++;
		return flow;
	}
	int sum=0;
	for(int i=now[x];i;i=e[i].ne)
	{
		now[x]=i;
		int y=e[i].to;
		if(d[y]!=d[x]+1||!e[i].v)continue;
		c[top].push_back(x);
		//cout<<x<<'\n';
		int w=dfs_(y,t,min(flow,e[i].v));
		if(!w)c[top].pop_back();
		if(!w)d[y]=0;
		sum+=w;
		flow-=w;
		e[i].v-=w;
		e[i^1].v+=w;
	}
	return sum;
}
int dinic(int s,int t)
{
	for(int i=2;i<=idx;i++)
		e[i].v=1;
	int sum=0;
	while(bfs(s,t))sum+=dfs(s,t,1e9);
	return sum;
}
int dinic_(int s,int t)
{
	for(int i=2;i<=idx;i++)
		e[i].v=1;
	int sum=0;
	while(bfs(s,t))sum+=dfs_(s,t,1e9);
	return sum;
}
void run()
{
	cin>>n>>m;k=(m+n-2)/(n-1);
	for(int i=1;i<=n;i++)he[i]=0;
	idx=1;
	int x,y;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	if(k==1)
	{
		cout<<x<<' '<<y<<'\n';
		cout<<2<<' '<<x<<' '<<y<<'\n';
		return;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(dinic(i,j)>=k)
			{
				cout<<i<<' '<<j<<'\n';
				top=1;
				dinic_(i,j);
				for(int p=1;p<=k;p++)
				{
					cout<<c[p].size()<<' ';
					for(int u=0;u<c[p].size();u++)
						cout<<c[p][u]<<' ';
					cout<<'\n';
				}
				for(int p=1;p<=top;p++)c[p].clear();
				return;
			}
		}
	}
	cout<<"-1\n";
}
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--)run();
	return 0;
}
/*
1
4 7 1 2 2 3 3 4 4 1 1 3 2 4 1 4 
*/
