#include <cstdio>
#define N 15
#define L 1000
#define IL inline
#define REP(a,b,c) for(a=b;a<=c;a++)
using namespace std;
const int st[][2]={{0,1},{1,0},{0,-1},{-1,0}},inf=1e9;
bool path[N][N];int dis[N][N],way[N][N];
int q[L][2];
//只有某点被更新才可能放入队列中，只有当前最优才能更新出最短路
//由于路径长度为1，故每个点至多入队一次
IL int rd(){
	int res=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')res=res*10+c-'0',c=getchar();
	return res;
}
int main(){
	freopen("maze.in","r",stdin),freopen("maze.out","w",stdout);
	int n=rd(),m=rd(),tx=rd(),ty=rd(),i,j,x,y,nx,ny,fr=0,tp=1;
	REP(i,1,n)
		REP(j,1,m)path[i][j]=(rd()==0),dis[i][j]=inf;
	dis[q[0][0]=1][q[0][1]=1]=0;
	while(fr!=tp){
		x=q[fr][0],y=q[fr++][1];
		REP(i,0,3){
			nx=x+st[i][0],ny=y+st[i][1];
			if(!path[nx][ny])continue;
			if(dis[nx][ny]>dis[x][y]+1)
				dis[nx][ny]=dis[x][y]+1,way[nx][ny]=1,q[tp][0]=nx,q[tp++][1]=ny;
			else if(dis[nx][ny]==dis[x][y]+1)way[nx][ny]++;
		}
	}
	printf("%d",way[tx][ty]);
	return 0;
}
