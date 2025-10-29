#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#define mp  make_pair
using namespace std;

typedef pair<int,int>  PII;
const int mx[4]={-1,1,0,0},my[4]={0,0,-1,1};
int n,m,X,Y,map[15][15],dis[15][15],f[15][15],vis[15][15];
priority_queue <PII,vector<PII> ,greater<PII> > Q;

void work()
{
	scanf("%d %d %d %d",&n,&m,&X,&Y);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			scanf("%d",&map[i][j]),dis[i][j]=1<<30;
	for (int i=1; i<=n; i++)  map[i][0]=map[i][m+1]=1;
	for (int i=1; i<=m; i++)  map[0][i]=map[n+1][i]=1;
	if (map[1][1])  {puts("0");  return;}
	dis[1][1]=0,f[1][1]=1,Q.push(mp(0,0));
	while (!Q.empty())
		{
			int x=Q.top().second/m+1,y=Q.top().second%m+1;  Q.pop();
			if (vis[x][y])  continue;
			if ((x==X)&&(y==Y))  {printf("%d",f[x][y]);  return;}
			vis[x][y]=1;
			for (int i=0; i<4; i++)
				if (!map[x+mx[i]][y+my[i]])
					{
						if (dis[x+mx[i]][y+my[i]]>dis[x][y]+1)
							{
								dis[x+mx[i]][y+my[i]]=dis[x][y]+1;
								f[x+mx[i]][y+my[i]]=f[x][y];
								Q.push(mp(dis[x][y]+1,(x+mx[i]-1)*m+y+my[i]-1));
							}else  if (dis[x+mx[i]][y+my[i]]==dis[x][y]+1)
							f[x+mx[i]][y+my[i]]+=f[x][y];
					}
		}
	puts("0");
}

int main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	work();
	return 0;
}
