#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int N=15;
int n,m,x,y;
int a[N][N];
int dis[N][N];
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
void bfs(){
	queue<pair<int,int> > q;
	q.push({1,1});
	dis[1][1]=1;int ans=0;
	while(!q.empty()){
		int tx=q.front().first,ty=q.front().second;
		if(a[tx][ty]==1) continue;
		q.pop();
		if(tx==x&&ty==y){
			ans++;
			continue;
		}
		if(dis[tx][ty]>dis[x][y]) continue;
		for(int i=0;i<4;i++){
			int nx=tx+dx[i],ny=ty+dy[i];
			if(nx<1||nx>n||ny<1||ny>m||a[nx][ny]==1||dis[nx][ny]<dis[tx][ty]+1) continue;
				dis[nx][ny]=dis[tx][ty]+1;
				q.push({nx,ny});
		}
	}
	printf("%d",ans);
}
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
		if(a[i][j]==0) dis[i][j]=1e9;
		else dis[i][j]=0;
	}
	bfs();
	return 0;
} 
