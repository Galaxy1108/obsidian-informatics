#include<bits/stdc++.h>
using namespace std;
int tot=0;
int head[100001];
int n,m,t,l;
int x,y,z;
int dis[100001];
int pos[100001];
bool vis[100001];
bool tick[2010][2010];
int f[100001];
int s;
struct Edge
{
	int nx,to,w;
}e[100001];
void edge(int u,int v,int val)
{
	e[++tot].nx=head[u];
	e[tot].to=v;
	e[tot].w=val;
	head[u]=tot;
}
struct node
{
	int r,id,dis;
	bool operator<(const node&a)const
	{
		return a.dis<dis;
	}
};
priority_queue<node> q;
int dij(int s,int t)
{
	for(int i=1;i<=n;i++)
	{
		dis[i]=1e9;
	}
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	q.push({s,s,0});
	while(q.size())
	{
		node u=q.top();
		q.pop();
		int r=u.r;
		int id=u.id;
		int w=u.dis;
		
		if(vis[id]==1)
		{
			continue;
		}
		vis[id]=1;
		f[id]=r;
		if(id==t)
		{
			return w;
		}
		for(int i=head[id];i;i=e[i].nx)
		{
			r=e[i].to;
			int l=e[i].w;
			if(dis[r]>dis[id]+l&&tick[r][id]==0)
			{
				dis[r]=dis[id]+l;
				f[r]=id;
			}
			if(!vis[r])
			{
				q.push({id,r,dis[r]});
			}
		}
	}
	return dis[t];
}
int main()
{
	freopen("wildboar.in","r",stdin);
	freopen("wildboar.out","w",stdout);
	cin>>n>>m>>t>>l;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		edge(x,y,z);
		edge(y,x,z);
	}
	for(int i=1;i<=l;i++)
	{
		cin>>pos[i];
	}
	for(int i=1;i<=t;i++)
	{
		memset(f,0,sizeof(f));
		memset(tick,0,sizeof(tick));
		cin>>x>>y;
		pos[x]=y;
		int ans=0;
		int j;
		for(int i=1;i<l;i++)
		{
			ans+=dij(pos[i],pos[i+1]);
			
			for(j=pos[i+1];j!=f[j];j=f[j])
			{
				tick[j][f[j]]=tick[f[j]][j]=1;
			}
		}
		cout<<ans<<endl;
	}
}
/*
3 3 1 3 
1 2 1 
2 3 1 
1 3 1 
1 
2 
3 
3 1

4 4 4 3 
1 2 1 
2 3 1 
1 3 1 
1 4 1 
4 
1 
3 
3 4 
1 2 
3 2 
2 4

5 10 1 10
1 2 4
1 3 10
1 4 5
1 5 6
2 3 2
2 4 1
2 5 1
3 4 9
3 5 10
4 5 10
4
2
3
1
4
3
1
3
2
3
10 1
*/
