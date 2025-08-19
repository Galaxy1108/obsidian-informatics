#include<bits/stdc++.h>
using namespace std;
const int N=60,M=505;
int n,m,anslt,ans,ary[N][N];
bool vis[N][N];
void dfs(int x,int y,int nowm)
{
	if(nowm>m)return;
	if(x==n&&y==2)
	{
		if(nowm==m)anslt=max(anslt,ans);
		return;
	}
	if(y>n-x+1)y=1,x++;
	if(x==1)
	{
		vis[x][y]=1;
		ans+=ary[x][y];
		dfs(x,y+1,nowm+1);
		vis[x][y]=0;
		ans-=ary[x][y];
		dfs(x,y+1,nowm);
	}
	else
	{
		if(vis[x-1][y]&&vis[x-1][y+1])
		{
			vis[x][y]=1;
			ans+=ary[x][y];
			dfs(x,y+1,nowm+1);
		}
		vis[x][y]=0;
		ans-=(vis[x-1][y]&&vis[x-1][y+1])*ary[x][y];
		dfs(x,y+1,nowm);
	}
}
int main()
{
	freopen("brike.in","r",stdin);
	freopen("brike.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n-i+1;j++)
			cin>>ary[i][j];
	dfs(1,1,0);
	cout<<anslt;
		
	return 0;
}
