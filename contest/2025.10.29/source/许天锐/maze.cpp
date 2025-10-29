#include<bits/stdc++.h>
using namespace std;
int n,m,ex,ey;
int a[15][15],vis[15][15];
struct node{
	int x,y,step;
};
queue<node>q;
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	cin>>n>>m>>ex>>ey;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cin>>a[i][j];
	}
	q.push((node){1,1,0});
	int ans=145,cnt=0;
	while(q.size()){
		node now=q.front();
		q.pop();
		vis[now.x][now.y]=1;
		if(now.step>ans)break;
		if(now.x==ex&&now.y==ey){
			if(ans==145)ans=now.step,cnt++;
			else if(ans==now.step)cnt++;
			continue;
		}
		if(now.step==ans)continue;
		if(now.x!=n)if(a[now.x+1][now.y]!=1&&!vis[now.x+1][now.y])q.push((node){now.x+1,now.y,now.step+1});
		if(now.y!=m)if(a[now.x][now.y+1]!=1&&!vis[now.x][now.y+1])q.push((node){now.x,now.y+1,now.step+1});
		if(now.x!=1)if(a[now.x-1][now.y]!=1&&!vis[now.x-1][now.y])q.push((node){now.x-1,now.y,now.step+1});
		if(now.y!=1)if(a[now.x][now.y-1]!=1&&!vis[now.x][now.y-1])q.push((node){now.x,now.y-1,now.step+1});
	}
	cout<<cnt<<endl;
	return 0;
}
/*
12 12 12 12
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 
*/
