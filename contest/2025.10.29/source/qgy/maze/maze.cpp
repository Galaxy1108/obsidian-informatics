#include <bits/stdc++.h>
#define ps emplace
using namespace std;
constexpr int N=15,inf=1e9;
constexpr int dx[]={1,0,0,-1},dy[]={0,1,-1,0};
int n,m,ex,ey,ans=1e9,cnt;
int a[N][N];
int vis[N][N];
struct node{
	int x,y,stp;
	node()=default;
	node(int x,int y,int stp):x(x),y(y),stp(stp){}
};
queue<node>q;
int main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>ex>>ey;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	q.ps(1,1,0);
	memset(vis,0x3f,sizeof vis);
	vis[1][1]=0;
	while(!q.empty())
	{
		node tmp=q.front();q.pop();
		int x=tmp.x,y=tmp.y,stp=tmp.stp;
		if(x==ex && y==ey)
		{
			ans=stp,cnt++;
			continue;
		}
		if(stp>=ans)continue;
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i],ny=y+dy[i];
			if(nx<1 || ny<1 || nx>n || ny>m || stp+1>vis[nx][ny] || a[nx][ny])
				continue;
			vis[nx][ny]=stp+1;
			q.ps(nx,ny,stp+1);
		}
	}
	cout<<cnt;
	return 0;
}