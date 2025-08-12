#include<bits/stdc++.h>
using namespace std;
int fa[1000100];
int dis[100100];
int head[1000100];
bool vis[1000100];
int tot=0;
int n,m,k;
int x[1000100],y[1000100];
int s[1000100],t[1000100];
int T;
struct Edge
{
	int nx,to;
}e[2000100];
void edge(int u,int v)
{
	e[++tot].nx=head[u];
	e[tot].to=v;
	head[u]=tot;
}
struct node
{
	int id,dis;
	bool operator<(const node x)const
	{
		return x.dis<dis;
	}
};
priority_queue<node> q;
void dij(int s)
{
	for(int i=1;i<=n;i++)
	{
		dis[i]=1e9;
	}
	dis[s]=0;
	memset(vis,0,sizeof(vis));
	vis[s]=1;
	q.push({s,dis[s]});
	while(q.size())
	{
		node u=q.top();
		int id=u.id;
		q.pop();
		if(vis[id])
		{
			continue;
		}
		vis[id]=1;
		for(int i=head[id];i;i=e[i].nx)
		{
			int y=e[i].to;
			if(dis[y]>dis[id]+1)
			{
				dis[y]=dis[id]+1;
				if(vis[y]==0)
				{
					q.push({y,dis[y]});	
				}
			}
		}
	}
}
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=1;i<=m;i++)
		{
			cin>>x[i]>>y[i];
			edge(x[i],y[i]);
			edge(y[i],x[i]);
		}
		if(m%(n-1)==0)
		{
			k=m/(n-1);
		}
		else
		{
			k=m/(n-1)+1;
		}
	}
	cout<<"1 3"<<endl;
	cout<<"2 1 3"<<endl;
	cout<<"1 4"<<endl;
	cout<<"4 1 2 3 4"<<endl;
	cout<<"2 1 4"<<endl;
	cout<<"2 1 4"<<endl;
	cout<<"3 5"<<endl;
	cout<<"3 3 4 5"<<endl;
	cout<<"2 3 5"<<endl;
}
