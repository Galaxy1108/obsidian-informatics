#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=15;
int ans,a[N][N],n,m,x,y,st;
int dx[4]={0,0,1,-1},dy[4]={-1,1,0,0};
struct node{
	int x,y,step;
};
inline void bfs(){
	bool vis[N][N]={};
	queue<node>q;
	q.push({1,1,0});
	while(!q.empty()){
		int _x=q.front().x,_y=q.front().y,sep=q.front().step;
		q.pop();
		if(_x==x&&_y==y){
			st=sep;
			return;
		}
		for(int i=0;i<4;i++){
			int nx=_x+dx[i],ny=_y+dy[i];
			if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&!a[nx][ny]&&!vis[nx][ny]){
				q.push({nx,ny,sep+1});
				vis[nx][ny]=1;
			}
		}
	}
}
bool vis[N][N];
inline void dfs(int _x,int _y,int step){
	if(st>step)return;
	if(_x==x&&_y==y){
		if(step==st)ans++;
		return;
	}
	for(int i=0;i<4;i++){
			int nx=_x+dx[i],ny=_y+dy[i];
			if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&!a[nx][ny]&&!vis[nx][ny]){
				vis[nx][ny]=1;
				dfs(nx,ny,step+1);
				vis[nx][ny]=0;
			}
		}
}
signed main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&m,&x,&y);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%lld",&a[i][j]);
	bfs();
	dfs(1,1,0);
	printf("%lld\n",ans);
	return 0;
}
