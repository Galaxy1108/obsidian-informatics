#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int rd(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0') c=getchar();
	while(c<='9'&&c>='0'){
		x=10*x+c-'0';
		c=getchar();
	}
	return x;
} 
int n,m,e1,e2,cnt,ans=0,v[20][20],vis[20][20]={0},dx[]={0,0,0,-1,1},dy[]={0,1,-1,0,0};
inline void dfs(int mi,int ku,int dep){
	if(dep>cnt) return;
	if(v[mi][ku]==1) return;
	if(vis[mi][ku]==1) return;
	if(mi==e1&&ku==e2){
		ans++;
		return ;
	} 
	for(int i=1;i<=4;i++){
		int xx=mi+dx[i],yy=ku+dy[i];
		if(xx<1||xx>e1||yy<1||yy>e2) continue;
		vis[xx][yy]=1;
		dfs(xx,yy,dep+1);
		vis[xx][yy]=0;
	}
}
struct node{
	int x,y,dep;
}a;
queue<node> q;
signed main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout); 
	n=rd(),m=rd(),e1=rd(),e2=rd();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			v[i][j]=rd();
		}
	}
	a.x=1;
	a.y=1;
	a.dep=0;
	q.push(a);
	while(!q.empty()){
		node top=q.front();
		q.pop();
		if(top.x==e1&&top.y==e2){
			cnt=top.dep;
			break;
		}
		for(int i=1;i<=4;i++){
			int xx=top.x+dx[i];
			int yy=top.y+dy[i];
			if(xx<1||yy<1||xx>e1||yy>e2||v[xx][yy]) continue;
			a.x=xx,a.y=yy,a.dep=top.dep+1;
			v[xx][yy]=1;
			q.push(a);
		}
	}
	memset(v,0,sizeof(v));
	dfs(1,1,0);
	cout<<ans;
	return 0;
}
