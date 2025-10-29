#include<bits/stdc++.h>
using namespace std;

int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int n,m,ex,ey,cnt=0;
int a[20][20];
bool b[20][20]={0};

void dfs(int x,int y)
{
	if(x==ex&&y==ey)
	{
		cnt++;
		return;
    }
	for(int i=0;i<4;i++)
	{
		int now_x=x+dx[i];
		int now_y=y+dy[i];
		if(now_x>=1&&now_x<=n&&now_y>=1&&now_y<=m&&b[now_x][now_y]==0)
		{
			b[now_x][now_y]=1;
			dfs(now_x,now_y);
			b[now_x][now_y]=0;
		} 
	} 
	return ;
}
	
int main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	cin>>n>>m>>ex>>ey;
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=m;j++)
	    {
	    	cin>>a[i][j];
	    	if(a[i][j]==1) b[i][j]=1;
		}
	b[1][1]=1;
	dfs(1,1);
	cout<<cnt;
	return 0;
}
