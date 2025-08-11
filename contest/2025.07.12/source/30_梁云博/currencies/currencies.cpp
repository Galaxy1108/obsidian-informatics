#include <bits/stdc++.h>
#define int long long
#define N 200005
#define M 200005
#define pii pair<int,int>
using namespace std;
int n,m,Q;
int head[N],val[M<<1],nxt[M<<1],to[M<<1];
void add(int u,int v,int w)
{
	static int idx=0;
	to[++idx]=v;
	nxt[idx]=head[u];
	val[idx]=w;
	head[u]=idx;
}
struct E
{
	int u,v,w;
}e[N];
struct P
{
	int u,g,s;
	P(){}
	P(int u,int g,int s):u(u),g(g),s(s){}
};
signed main()
{
//	freopen("currencies.in","r",stdin);
//	freopen("currencies.out","w",stdout);
	cin>>n>>m>>Q;
	int flg2=1,flg3=1;
	for(int i=1;i<n;i++)
	{
		cin>>e[i].u>>e[i].v;
		add(e[i].u,e[i].v,0);
		add(e[i].v,e[i].u,0);
	}
	for(int i=1,p;i<=m;i++)
	{
		cin>>p;
		cin>>e[p].w;
		val[2*p-1]+=e[p].w;
		val[2*p]+=e[p].w;
	}
	while(Q--)
	{
		int st,t,x,y;
		cin>>st>>t>>x>>y;
		priority_queue<pii,vector<pii >,greater<pii > >q;
		priority_queue<int>q2;
		int vis[N]={0},pre[N]={0},prev[N]={0},dis[N];
		for(int i=1;i<=n;i++)dis[i]=1e18;
		dis[st]=0;
		pre[st]=-1;
		q.push(make_pair(0,st));
		while(!q.empty())
		{
			int u=q.top().second;
			q.pop();
			if(vis[u])continue;
			vis[u]=1;
			for(int i=head[u];i;i=nxt[i])
			{
				int v=to[i],w=val[i];
				if(vis[v])continue;
				if(dis[v]>dis[u]+w)
				{
					dis[v]=dis[u]+w;
					pre[v]=u;
					prev[v]=w;
					q.push(make_pair(dis[v],v));
				}
			}
		}
		for(int i=t;i!=-1;i=pre[i])
		{
			q2.push(prev[i]);
		}
		while(x && y<dis[t])
		{
			dis[t]-=q2.top();
			x--;
			q2.pop();
		}
		if(y>=dis[t])cout<<x<<"\n";
		else cout<<"-1\n";
	}
	
	return 0;
}
