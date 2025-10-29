#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
int map[20][20];
int n,m,x,y;
int vis[20][20];
int dep[20][20];
int f[20][20];
int q[20*20][2];
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
void work()
{
	scanf("%d%d%d%d",&n,&m,&x,&y);
  int i,j,s,t,xx,yy;
  for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			scanf("%d",&map[i][j]);
			map[i][j]^=1;  
		}if(map[1][1]==0||map[x][y]==0){printf("0\n");return;}
  q[1][0]=1;q[1][1]=1;
  vis[1][1]=1;f[1][1]=1;dep[1][1]=1;
  int fir=1,las=1;
  for(;fir<=las;fir++){
		s=q[fir][0];t=q[fir][1];//printf("out %d %d\n",s,t);
    for(i=0;i<4;i++)
			{xx=s+dx[i];
				yy=t+dy[i];//printf("vis %d %d\n",xx,yy);
				if(map[xx][yy])
					{if(!vis[xx][yy])
							{dep[xx][yy]=dep[s][t]+1;f[xx][yy]=0;
								q[++las][0]=xx;q[las][1]=yy;
								vis[xx][yy]=1;}
						if(dep[xx][yy]==dep[s][t]+1)
							{f[xx][yy]+=f[s][t];}
          }
     }
  }
	printf("%d\n",f[x][y]);
}

int main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	work();
  fclose(stdin);
  fclose(stdout);
	return 0;
}
