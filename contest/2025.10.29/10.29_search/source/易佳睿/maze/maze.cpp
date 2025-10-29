#include<bits/stdc++.h>
using namespace std;
constexpr int dx[5]={0,0,-1,1,0};
constexpr int dy[5]={0,-1,0,0,1};
int N,M,X,Y;
int dis=150,cnt=0;
bool mp[15][15];
void DFS(int x,int y,int stp,int dir){
	if(stp>dis) return ;
	if(x==X&&y==Y){
		if(stp<dis) dis=stp,cnt=1;
		else if(stp==dis) cnt++;
		return ;
	}
	for(int i=1;i<=4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(1>nx||nx>N) continue;
		if(1>ny||ny>M) continue;
		if(mp[nx][ny]) continue;
		if(dir+i==5) continue;
		DFS(nx,ny,stp+1,i);
	}
}
int main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	cin>>N>>M>>X>>Y;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			cin>>mp[i][j];
	DFS(1,1,0,0);
	cout<<cnt;
}
