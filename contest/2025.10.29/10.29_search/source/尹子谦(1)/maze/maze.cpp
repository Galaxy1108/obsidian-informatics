#include<bits/stdc++.h>
using namespace std;
const int N=14;
int vis[N][N],tim[N][N],dx[]={1,0,0,-1},dy[]={0,1,-1,0},n,m,ex,ey;//到达n的最短时间,到达n的路径条数 
bool wall[N][N];
struct Node
{
	int x,y,tim;
};
queue<Node> q;
int main() 
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	cin>>n>>m>>ex>>ey;
	memset(vis,0x3f,sizeof vis);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		 cin>>wall[i][j];
	q.push({1,1,0});
	vis[1][1]=0,tim[1][1]=1;
	while(q.size())
	{
		Node ft=q.front();
		q.pop();
		int x=ft.x,y=ft.y,t=ft.tim;
		if(t>vis[ex][ey]) continue;
		if(x==ex&&y==ey)continue;
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i],ny=y+dy[i];
			if(nx>n||nx<1||ny>m||ny<1||(wall[nx][ny])) continue;
		    int ntim=t+1; 
			if(ntim>vis[nx][ny]) continue;
			if(ntim==vis[nx][ny]) tim[nx][ny]++;
			if(ntim<vis[nx][ny]) tim[nx][ny]=1,vis[nx][ny]=ntim;
			q.push({nx,ny,ntim}); 
		}	
	}
	cout<<tim[ex][ey];
	return 0;
}
