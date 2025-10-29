#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,anslt;
int mp[15][15],mi[15][15];
bool vis[15][15];
void dfs(int px,int py,int dis)
{
	if(px==x&&py==y)
	{
		if(dis==mi[px][py])anslt++;
		if(dis<mi[px][py])anslt=1,mi[px][py]=dis;
		return;
	}
	if(dis>mi[px][py])return;
	mi[px][py]=min(mi[px][py],dis);
	if(px>1&&!mp[px-1][py]&&!vis[px-1][py])
	{
		vis[px-1][py]=true;
		dfs(px-1,py,dis+1);
		vis[px-1][py]=false;
	}
	if(px<n&&!mp[px+1][py]&&!vis[px+1][py])
	{
		vis[px+1][py]=true;
		dfs(px+1,py,dis+1);
		vis[px+1][py]=false;
	}
	if(py>1&&!mp[px][py-1]&&!vis[px][py-1])
	{
		vis[px][py-1]=true;
		dfs(px,py-1,dis+1);
		vis[px][py-1]=false;
	}
	if(py<m&&!mp[px][py+1]&&!vis[px][py+1])
	{
		vis[px][py+1]=true;
		dfs(px,py+1,dis+1);
		vis[px][py+1]=false;
	}
	return;
}
int main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	memset(mi,0x3f,sizeof(mi));
	cin>>n>>m>>x>>y;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	if(mp[1][1])
	{
		cout<<0;
		return 0;
	}
	vis[1][1]=true;
	dfs(1,1,0);
	cout<<anslt;
	
	return 0;
}
