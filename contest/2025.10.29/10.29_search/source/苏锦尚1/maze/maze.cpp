#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
int a[20][20];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
long long ans=0;
int sign[20][20];
vector <long long> dis;
long long dist[20][20];
void dfs(int nx,int ny){
	if(nx==n&&ny==y){
		dis.push_back(dist[nx][ny]);
		return ;
	}
	else{
		sign[nx][ny]=1;
	    for(int i=0;i<4;i++){
		int lx=nx+dx[i];
		int ly=ny+dy[i];
		if(sign[lx][ly]) continue;
		if(lx<1||lx>n||ly<1||ly>n) continue;
		if(a[lx][ly]==1) continue;
		dist[lx][ly]=dist[nx][ny]+1;
		dfs(lx,ly);
		//dist[lx][ly]=dist[nx][ny]+1;
	    }	
	    sign[nx][ny]=0;
	}
	
}
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	cin>>n>>m>>x>>y;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	dfs(1,1);
	sort(dis.begin(),dis.end());
	long long ans=1;
	for(int i=1;i<dis.size();i++){
		if(dis[i]==dis[i-1])
		ans++;
		else break;
	}
	cout<<ans;
	return 0;
}
