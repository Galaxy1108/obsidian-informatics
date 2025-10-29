#include<bits/stdc++.h>
#include<queue>
using namespace std;

inline int qread()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=x*10+(c^48);
		c=getchar();
	}
	return x*f;
}
#define re register

const int N=20;
int n,m,X,Y;
bool mp[N][N];
#define pii pair<int,int>
#define mkp make_pair
queue< pii > q;

int dx[4]= {1,-1,0,0};
bool vis[N][N];
int dy[4]= {0,0,1,-1};

signed main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	n=qread(),m=qread(),X=qread(),Y=qread();
	for(re int i=1; i<=n; i++)
	{
		for(re int j=1; j<=m; j++)
		{
			cin>>mp[i][j];
		}
	}
	q.push(mkp(1,1));
	int ans=0;
	while(q.size())
	{
		pii now=q.front();
		vis[now.first][now.second]=1;
		if(now.first==X&&now.second==Y)
		{
			cout<<ans<<endl;
			exit(0);
		}
		q.pop();
		for(re int k=0; k<=3; k++)
		{
			int nx=now.first+dx[k],ny=now.second+dy[k];
			if(nx<1||nx>n||ny<1||ny>m)continue;
			if(mp[nx][ny]==1)continue;
			if(nx==X&&ny==Y)ans++;
			if(vis[nx][ny])continue;
			q.push(mkp(nx,ny));
		}
	}
	return 0;
}
/*
12 12 12 12 
0 1 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 1 1 0 0 0 
0 0 0 0 0 0 1 0 0 0 0 1 
0 0 0 0 0 0 0 0 0 0 1 0 
0 0 0 0 1 0 0 1 1 0 0 0 
0 0 0 0 1 0 1 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 
0 0 1 0 0 1 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 1 0 0 0 
0 0 1 0 0 1 1 1 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 1 0 
0 0 0 1 0 0 0 0 0 0 1 0 

*/
