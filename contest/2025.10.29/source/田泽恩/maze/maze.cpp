#include <bits/stdc++.h>
using namespace std;
int vis[20][20],w[20][20],dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
queue<pair<int,int> > q;
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	int n,m,ex,ey;
	cin>>n>>m>>ex>>ey;
	for(int i=1,u;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>u;
			vis[i][j]=u?-1:0x3f3f3f3f;
		}
	}
	if(vis[1][1]==-1){
		cout<<0;
		return 0;
	}
	w[1][1]=1;
	q.push({1,1});
	vis[1][1]=1;
	while(!q.empty()){
		int x=q.front().first,y=q.front().second;
		q.pop();
		if(vis[x][y]>=vis[ex][ey]) break;
		for(int i=0,X,Y;i<4;++i){
			X=x+dx[i];
			Y=y+dy[i];
			if(X&&X<=n&&Y&&Y<=m){
				if(vis[X][Y]>vis[x][y]){
					w[X][Y]+=w[x][y];
					if(vis[X][Y]>vis[x][y]+1) q.push({X,Y});
					vis[X][Y]=vis[x][y]+1;
				}
			}
		}
	}
	cout<<w[ex][ey];
	return 0;
}
