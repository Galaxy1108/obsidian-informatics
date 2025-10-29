#include <bits/stdc++.h>
using namespace std;
const int maxn=15;
const int INF=1e9;
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)) {if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=x*10+(c^48);c=getchar();}
	return x*f;
}
int mp[maxn][maxn];
int n,m,tx,ty;
int dis[maxn][maxn];
int cx[]={0,1,0,-1,0};
int cy[]={0,0,1,0,-1};
struct node{
	int x,y,dep;
};
queue <node> q;
inline int bfs()
{
	q.push((node){1,1,0});
	dis[1][1]=0;
	while(!q.empty())
	{
		node t=q.front();
		if(t.x==tx&&t.y==ty) break ;
		q.pop();
		for(int i=1;i<=4;i++)
		{
			int x=t.x+cx[i];
			int y=t.y+cy[i];
			if(mp[x][y]) continue ;
			if(dis[x][y]<=t.dep) continue ;
			dis[x][y]=t.dep+1;
			q.push((node){x,y,t.dep+1});
		}
	}
	int ans=0;
	while(!q.empty())
	{
		node t=q.front();
		q.pop();
		if(t.dep==dis[tx][ty]&&t.x==tx&&t.y==ty) ans++;
	}
	return ans;
}
int main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	n=read();m=read();tx=read();ty=read();
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	mp[i][j]=read();
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	dis[i][j]=INF;
	for(int i=1;i<=n;i++)
		mp[i][0]=mp[i][m+1]=1;
	for(int i=1;i<=m;i++)
		mp[0][i]=mp[n+1][i]=1;
	printf("%d",bfs());
	return 0;
}
/*
12 12 12 12
0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 
*/
