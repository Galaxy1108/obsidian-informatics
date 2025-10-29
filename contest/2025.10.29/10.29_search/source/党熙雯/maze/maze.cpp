#include<bits/stdc++.h>
using namespace std;
const int mx=15;
int a[mx][mx];
int vis[mx][mx];
struct node
{
	int x,y,step;
};
int dr[]={0,0,0,1,-1};
int dc[]={0,-1,1,0,0};
queue<node> q;
int fread()
{
	int x=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9') w=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=getchar();
	return x*w;
}
int main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	int n=fread(),m=fread();
	int enx=fread(),eny=fread();
	q.push({1,1,0});
	for(int i=1;i<=n;i++) 
	for(int j=1;j<=m;j++)
	vis[i][j]=fread();
	int ans=0;
	memset(a,0x3f,sizeof(a));
//	cout<<a[1][1]<<endl;
	while(q.size())
	{
		node tmp=q.front();
		q.pop();
		int x=tmp.x,y=tmp.y,step=tmp.step;
		if(vis[y][x]||a[x][y]<step) continue;
//		cout<<x<<' '<<y<<' '<<step<<' '<<vis[x][y]<<endl;
		if(x==enx&&y==eny) ans++;
		a[x][y]=step;
		for(int i=1;i<=4;i++)
		{
			int xx=x+dr[i],yy=y+dc[i];
//			cout<<xx<<' '<<yy<<endl; 
			if(!vis[yy][xx]&&(a[xx][yy]==1061109567||a[xx][yy]==step+1)&&xx<=m&&xx>=1&&yy<=n&&yy>=1)
			{
				q.push({xx,yy,step+1});
			}
		}
	}
	cout<<ans;
	return 0;
}
