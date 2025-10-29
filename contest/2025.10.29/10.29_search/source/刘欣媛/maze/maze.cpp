#include <bits/stdc++.h>
using namespace std;
bool mp[20][20];
struct node{
	int x,y,st;
};
int bk[20][20],f[2][4]={0,0,1,-1,1,-1,0,0},ans;
queue<node> q;
int main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m,x,y;
	cin>>n>>m>>x>>y;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>mp[i][j];
			bk[i][j]=2e9;
		}
	}
	node o={1,1,0};
	q.push(o);
	while(q.size())
	{
		node a=q.front();
		q.pop();
		node b;
		if(a.x==x&&a.y==y)
		{
			if(a.st<=bk[x][y])
			{
				bk[x][y]=a.st;
				ans++;
			}
			else
			{
				break;
			}
		}
		for(int i=0;i<4;i++)
		{
			b.x=a.x+f[0][i],b.y=a.y+f[1][i],b.st=a.st+1;
			if(b.x>n||b.x<1||b.y>m||b.y<1||mp[b.x][b.y]==1) continue;
			if(b.st>bk[b.x][b.y]) continue;
			bk[b.x][b.y]=b.st;
			q.push(b);
		}
	}
	cout<<ans;
	
	return 0;
 } 
