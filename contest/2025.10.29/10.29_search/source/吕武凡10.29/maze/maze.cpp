#include<bits/stdc++.h>
using namespace std;
int n,m;
int x,y;
bool a[20][20];
int tot=0;
int head[6000010];
int dis[1000100];
bool vis[1000100];
long long ans[1000010];
struct Edge
{
	int nx,to;
}e[6000100];
void edge(int u,int v)
{
	e[++tot].nx=head[u];
	e[tot].to=v;
	head[u]=tot;
	return;
}
struct node
{
	int id,dis;
	bool operator<(const node&x)const
	{
		return x.dis<dis;
	}
};
priority_queue<node> q;
void dij(int s)
{
	for(int i=1;i<=n*m;i++)
	{
		dis[i]=1e9;
	}
	dis[s]=0;
	ans[1]=1;
	q.push({s,0});
	while(q.size())
	{
		node u=q.top();
		q.pop();
		int id=u.id;
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
				ans[y]=ans[id];
				q.push({y,dis[y]});
			}
			else if(dis[y]==dis[id]+1)
			{
				ans[y]+=ans[id];
			}
		}
	}
}
int pos(int x,int y)
{
    return (x-1)*m+y;
}
int main()
{
    freopen("maze.in","r",stdin);
    freopen("maze.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>x>>y;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==0)
            {
                if(a[i][j+1]==0)
                {
                    edge(pos(i,j),pos(i,j+1));
                }
                if(a[i+1][j]==0)
                {
                    edge(pos(i,j),pos(i+1,j));
                }
            }
        }
    }
    dij(1);
    cout<<ans[pos(x,y)];
}