#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,a[110][110],tag[110][110],dis[110][110];
long long sum[110][110];
int tx[4]={-1,1,0,0},ty[4]={0,0,-1,1};
int check(int x,int y,int D){
	if(x<1||x>n||y<1||y>m) return 0;
	if(a[x][y]) return 0;
	if(dis[x][y]<=D) return 0;
	return 1;
}
int main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%d",&a[i][j]);
			dis[i][j]=1e9;
		}
	}
	
	queue<pair<int,int> > q;
	q.push(make_pair(1,1));
	dis[1][1]=0,sum[1][1]=1;
	while(!q.empty()){
		int x=q.front().first,y=q.front().second;
		q.pop();
		if(tag[x][y]) continue;
		tag[x][y]=1; 
		for(int o=0;o<4;++o){
			if(check(x+tx[o],y+ty[o],dis[x][y])){
				dis[x+tx[o]][y+ty[o]]=dis[x][y]+1;
				sum[x+tx[o]][y+ty[o]]+=sum[x][y];
				q.push(make_pair(x+tx[o],y+ty[o]));
			}
		}
	}
	printf("%lld\n",sum[x][y]);
	
	return 0;
} 
