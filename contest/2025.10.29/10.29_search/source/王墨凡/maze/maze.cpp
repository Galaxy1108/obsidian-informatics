#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
struct node{
	int x,y,step;
};
int s,t,n,m,map[186][186],cx[5]={-1,0,1,0},cy[5]={0,1,0,-1};
int cnt[186][186],dis[186][186];
queue<node> q;
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	cin >> n >> m >> s >> t;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> map[i][j];
		}
	}
	memset(dis,0x3f,sizeof dis);
	q.push({1,1,0});
	dis[1][1]=0;
	while(!q.empty()){
		int x=q.front().x,y=q.front().y,step=q.front().step;
		q.pop();
		for(int i=0;i<4;i++){
			int xx=x+cx[i],yy=y+cy[i],se=step+1;
			if(dis[xx][yy]<se||map[xx][yy]||xx>n||xx<1||yy>m||yy<1)continue;
			cnt[xx][yy]++;
			dis[xx][yy]=se;
			q.push({xx,yy,se});
		}
	}
	cout << cnt[s][t];
	return 0;
}
/*
4 12 4 12
0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0  
0 0 0 0 0 0 0 0 0 0 0 0  
*/
