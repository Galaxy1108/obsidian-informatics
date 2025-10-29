#include<bits/stdc++.h>
#define int long long
#define N 12
using namespace std;
struct Node{int x,y,v;};
int n,m,sx,sy,cnt,minn=INT_MAX,a[N+5][N+5],f[N+5][N+5];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
Node u;
queue<Node>q;
int read(){
	int f=1,g=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		g=g*10+ch-'0';
		ch=getchar();
	}
	return f*g;
}
void print(int x){
	if(x<0){
		putchar('-');
		x*=-1;
	}
	if(x>9)print(x/10);
	putchar(x%10+'0');
	return;
}
main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	n=read(),m=read(),sx=read(),sy=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)a[i][j]=read();
	}
	if(a[1][1]){
		print(0);
		return 0;
	}
	q.push({1,1,0});
	while(q.size()){
		if(q.front().v>n*m||q.front().v>minn)break;
		u=q.front(),q.pop(),f[u.x][u.y]=1;
		if(u.x==sx&&u.y==sy)minn=u.v,cnt++;
		for(int i=0;i<4;i++){
			int xx=u.x+dx[i],yy=u.y+dy[i];
			if(xx<1||xx>n||yy<1||yy>m||a[xx][yy]||f[xx][yy])continue;
			q.push({xx,yy,u.v+1});
		}
	}
	print(cnt);
	return 0;
} 
