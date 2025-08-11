#include<bits/stdc++.h>
using namespace std;
char ans[2111][511];
int n,m;
int xcnt[11111];
int qxcnt[11111];
int dy=5;
int dele[111][111];
void dfs(int x,int y,int xx,int yy){
	if(x>m) return ;
	ans[xx][yy]='o';
	if(!dele[x+1][2*(y-1)+1]){
		int xxx=xx+1,yyy=yy-1,k=xcnt[x];
		while(k--&&xxx>0&&yyy>0){
			ans[xxx][yyy]='/';
			xxx++;yyy--;
		}dfs(x+1,2*(y-1)+1,xxx,yyy);
	}if(!dele[x+1][2*y]){
		int xxx=xx+1,yyy=yy+1,k=xcnt[x];
		while(k--){
			ans[xxx][yyy]=92;
			xxx++;yyy++;
		}dfs(x+1,2*y,xxx,yyy);
	}
}
int main(){
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	cin.tie(0);cout.tie(0);
	for(int i=0;i<2111;i++){
		for(int j=0;j<511;j++){
			ans[i][j]=' ';
		}
	}
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		int x11,y11;
		cin>>x11>>y11;
		dele[x11][y11]=1;
	}
	xcnt[m-1]=1;
	qxcnt[m-1]=1;
	for(int i=m-2;i>=1;i--){
		xcnt[i]=qxcnt[i+1]+m-i-1;
		qxcnt[i]=xcnt[i]+qxcnt[i+1];
	}
	for(int i=1;i<=m-3;i++){
		dy=dy*2+1;
	}dy++;
	if(dele[1][1]){
		return 0;
	}
	dfs(1,1,1,dy); 
	for(int i=1;i<=qxcnt[1]+m;i++){
		for(int j=1;j<=dy*2-1;j++){
			cout<<ans[i][j];
		}cout<<endl;
	}return 0;
}
