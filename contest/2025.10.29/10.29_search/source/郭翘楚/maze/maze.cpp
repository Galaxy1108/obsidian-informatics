#include <bits/stdc++.h>
using namespace std;
int a[13][13];
int ex,ey;
struct node
{
	int x,y,t;
};
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int t[13][13];
int main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	memset(t,0x3f,sizeof(t));
	int n,m;
	cin>>n>>m>>ex>>ey;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	queue<node> q;
	q.push({1,1,0});
	int ans=0;
	bool flag=false;
	while(!q.empty())
	{
		node p=q.front();
		q.pop();
		t[p.x][p.y]=p.t;
		if(p.x==ex and p.y==ey)
		{
			ans++;
			flag=true;
		}
		if(!flag)
		{
			for(int i=0;i<4;i++)
			{
				int nx=p.x+dx[i],ny=p.y+dy[i];
				if(nx>n or ny>m or nx<1 or ny<1 or a[nx][ny]) continue;
				if(t[nx][ny]<p.t)
				{
					continue;
				}
				q.push({nx,ny,p.t+1});
			}
		}
//		cerr<<q.size()<<'\n';
	}
	cout<<ans;
}
