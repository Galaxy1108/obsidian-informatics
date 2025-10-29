#include<bits/stdc++.h>
#define il inline
#define ll long long
#define pii pair<int,int>
using namespace std;
int a[13][13],dis[13][13];
bool vis[13][13];
const int bx[]={1,-1,0,0},by[]={0,0,1,-1};
int n,m;
il void bfs(int sx,int sy,int ex,int ey)
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j) dis[i][j]=0x3f;
	static ll cnt=0;
	queue<pii> q;
	q.push({sx,sy});
	dis[sx][sy]=1;vis[sx][sy]=1;
	while(q.size())
	{
		pii f=q.front();q.pop();
		int x=f.first,y=f.second;
		for(int i=0;i<4;++i)
		{
			int nx=x+bx[i],ny=y+by[i];
			if(nx==ex&&ny==ey)
			{
				if(dis[x][y]+1<dis[nx][ny]){
					dis[nx][ny]=dis[x][y]+1;
					cnt=1;
				}
				else if(dis[x][y]+1==dis[nx][ny]) ++cnt;
			}
			if(nx<1||nx>n||ny<1||ny>m||a[nx][ny]||vis[nx][ny]) continue;
			vis[nx][ny]=1;
			dis[nx][ny]=dis[x][y]+1;
			q.push({nx,ny});
		}
	}
	cout<<cnt<<'\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	int x,y,i,j;
	cin>>n>>m>>x>>y;
	char ch;
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			cin>>ch,a[i][j]=(ch^48);
	bfs(1,1,x,y);
	return 0;
}
