#include <bits/stdc++.h>
using namespace std;
bool tu[15][15];
int ha[15][15];
int zx[4]={0,0,-1,1},zy[4]={1,-1,0,0};
struct sou
{
	int x,y,tot;
};
sou bfs[5000005];
int main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	int n,m,x,y;
	cin >> n >> m >> x >> y;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			cin >> tu[i][j];
			ha[i][j]=INT_MAX;
		}
	}
	int l=1,r=1;
	bfs[1].x=1;
	bfs[1].y=1;
	bfs[1].tot=0;
	ha[1][1]=0;
	int ans=INT_MAX,cnt=0;
	while (l <= r)
	{
		if (bfs[l].tot > ans)
		{
			break;
		}
		for (int i = 0;i < 4;i++)
		{
			int qx=bfs[l].x+zx[i],qy=bfs[l].y+zy[i];
			if (qx > n or qx < 1 or qy > m or qy < 1 or bfs[l].tot >= ha[qx][qy])
			{
				continue;
			}
			if (tu[qx][qy])
			{
				continue;
			}
			r++;
			bfs[r].x=qx;
			bfs[r].y=qy;
			bfs[r].tot=bfs[l].tot+1;
			ha[qx][qy]=bfs[r].tot;
			if (qx == x and qy == y)
			{
				if (ans == INT_MAX)
				{
					ans=bfs[r].tot;
				}
				
				if (bfs[r].tot == ans)
				{
					cnt++;
				}
			}
			
		}
		l++;
	}
	cout << cnt;
	return 0;
 } 
