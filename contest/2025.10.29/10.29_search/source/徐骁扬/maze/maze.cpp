#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
typedef pair<int,int> pos;
int n,m,stx,sty,i,j,x,y;
bool abl[20][20];
int dis[20][20],num[20][20];
queue<pos> Q;
pos rea;
int main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	n=Qread(),m=Qread(),stx=Qread(),sty=Qread();
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
		abl[i][j]=Qread();
	rea.first=rea.second=1;
	dis[1][1]=num[1][1]=1;
	Q.push(rea);
	while(!Q.empty())
	{
		rea=Q.front();Q.pop();
		x=rea.first,y=rea.second;
		if(x==stx&&y==sty)
		{
			printf("%d\n",num[x][y]);
			break;
		}
		if(x!=1&&!abl[x-1][y])
		{
			if(dis[x-1][y]==0) dis[x-1][y]=dis[x][y]+1,Q.push(make_pair(x-1,y));
			if(dis[x-1][y]==dis[x][y]+1) num[x-1][y]+=num[x][y];
		}
		if(y!=1&&!abl[x][y-1])
		{
			if(dis[x][y-1]==0) dis[x][y-1]=dis[x][y]+1,Q.push(make_pair(x,y-1));
			if(dis[x][y-1]==dis[x][y]+1) num[x][y-1]+=num[x][y];
		}
		if(x!=n&&!abl[x+1][y])
		{
			if(dis[x+1][y]==0) dis[x+1][y]=dis[x][y]+1,Q.push(make_pair(x+1,y));
			if(dis[x+1][y]==dis[x][y]+1) num[x+1][y]+=num[x][y];
		}
		if(y!=m&&!abl[x][y+1])
		{
			if(dis[x][y+1]==0) dis[x][y+1]=dis[x][y]+1,Q.push(make_pair(x,y+1));
			if(dis[x][y+1]==dis[x][y]+1) num[x][y+1]+=num[x][y];
		}
	}
	return 0;
}
