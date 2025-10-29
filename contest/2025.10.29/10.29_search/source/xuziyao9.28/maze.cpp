#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define N 101
#define orz 2000000000
using namespace std;
inline int read( )
{
  int sum=0;char c=getchar( );bool f=0;
  while(c<'0' || c>'9') {if(c=='-') f=1;c=getchar( );}
  while(c>='0' && c<='9') {sum=sum*10+c-'0';c=getchar( );}
  if(f) return -sum;
	return sum;
}
bool s[N][N];
int dis[N][N],inc[N][N];
int mx[4]={0,0,1,-1},my[4]={1,-1,0,0};
int n,m,tx,ty;
struct ex{int x,y;};
queue<ex>q;
inline void BFS( )
{
	int i,j,x,y,xx,yy;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			dis[i][j]=orz;
	dis[1][1]=0;inc[1][1]=1;
	q.push((ex){1,1});
	while(!q.empty( ))
		{
			x=q.front( ).x;y=q.front( ).y;q.pop( );
			for(i=0;i<=3;i++)
				{
					xx=x+mx[i];yy=y+my[i];
					if(xx<1||xx>n||yy<1||yy>m) continue;
					if(s[xx][yy]) continue;
					if(dis[xx][yy]>dis[x][y]+1)
						{
							dis[xx][yy]=dis[x][y]+1;
							inc[xx][yy]+=inc[x][y];
							if(xx!=tx||yy!=ty) q.push((ex){xx,yy});
						}
					else if(dis[xx][yy]==dis[x][y]+1) inc[xx][yy]+=inc[x][y];
				}
		}
	printf("%d\n",inc[tx][ty]);
}												

int main( )
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	int i,j;
	n=read( );m=read( );tx=read( );ty=read( );
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			s[i][j]=read( );
	BFS( );
	return 0;
}
