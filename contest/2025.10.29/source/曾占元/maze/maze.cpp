#include<bits/stdc++.h>
using namespace std;
int n,m,X,Y,cnt,ans;
int dir[4][2]={1,0,-1,0,0,1,0,-1},step[15][15];
bool a[15][15],vis[15][15];
struct cxt
{
	int x,y;
};
queue<cxt>q;
bool ck(int x,int y)
{
	return x>=1&&x<=n&&y>=1&&y<=m&&!a[x][y]&&!vis[x][y];
}
void dfs(int x,int y,int step)
{
	if(!ck(x,y))
		return ;
	if(x==X&&y==Y&&step==ans)
	{
		cnt++;
		return ;
	}
	vis[x][y]=1;
	for(int i=0;i<=3;i++)
	{
		int xx=x+dir[i][0];
		int yy=y+dir[i][1];
		dfs(xx,yy,step+1);
	}
	return ;
}
int main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	cin>>n>>m>>X>>Y;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	vis[1][1]=1;
	q.push((cxt){1,1});
	while(!q.empty())
	{
		cxt cxtcxt=q.front();
		q.pop();
		int x=cxtcxt.x,y=cxtcxt.y;
		for(int i=0;i<=3;i++)
		{
			int xx=x+dir[i][0];
			int yy=y+dir[i][1];
			if(!ck(xx,yy))
				continue;
			vis[xx][yy]=1;
			step[xx][yy]=step[x][y]+1;
			if(xx==X&&yy==Y)
			{
				ans=step[xx][yy];
				goto ccxxtt;
			}
			q.push((cxt){xx,yy});
		}
	}
	ccxxtt:;
	memset(vis,0,sizeof(vis));
	dfs(1,1,0);
	cout<<cnt;
	return 0;
}
