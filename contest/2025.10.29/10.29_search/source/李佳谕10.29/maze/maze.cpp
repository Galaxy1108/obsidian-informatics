#include<iostream>
#include<climits>
#include<cstring>
#include<queue>
using namespace std;
int minstep=INT_MAX;
int n,m,tx,ty;
bool a[15][15]={0};
struct node{
	int x,y,step;
};
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool visited[15][15];
int cnt=0;
int mem[15][15][144+5];
void dfs(int sx,int sy,int sstep){
	// cout<<"dfs sx:"<<sx<<" sy:"<<sy<<" sstep:"<<sstep<<endl;
	if(mem[sx][sy][sstep]){
		cnt+=mem[sx][sy][sstep];
		return;
	}
	int f=cnt;
	if(sstep>minstep){
		if(sx==tx&&sy==ty){
			cnt++;
			// cout<<"+1"<<endl;
		}
		return;
	}
	for(int i=0;i<4;i++){
		int nx=sx+dx[i],ny=sy+=dy[i],nstep=sstep+1;
		if(nx<1||ny<1||nx>n||ny>m)continue;
		if(visited[nx][ny])continue;
		if(a[nx][ny])continue;
		visited[nx][ny]=1;
		dfs(nx,ny,nstep);
		visited[nx][ny]=0;
	}
	int r=cnt;
	mem[sx][sy][sstep]=r-f;
	// cout<<"back"<<endl;
}
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	cin>>n>>m>>tx>>ty;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int in;
			cin>>in;
			if(in){
				a[i][j]=1;
			}
		}
	}
	int sx=1,sy=1;
	queue<node>q;
	visited[sx][sy]=1;
	q.push({sx,sy,0});
	while(!q.empty()){
		sx=q.front().x,sy=q.front().y;
		int sstep=q.front().step;
		q.pop();
		if(sx==tx&&sy==ty){
			minstep=sstep;
			break;
		}
		for(int i=0;i<4;i++){
			int nx=sx+dx[i],ny=sy+=dy[i],nstep=sstep+1;
			if(nx<1||ny<1||nx>n||ny>m)continue;
			if(visited[nx][ny])continue;
			if(a[nx][ny])continue;
			visited[nx][ny]=1;
			q.push({nx,ny,nstep});
		}
	}
	if(minstep==INT_MAX){
		cout<<0;
		return 0;
	}
	// cout<<minstep<<endl;
	memset(visited,0,sizeof(visited));
	sx=1,sy=1;
	visited[sx][sy]=1;
	dfs(sx,sy,1);
	cout<<cnt;
	return 0;
}