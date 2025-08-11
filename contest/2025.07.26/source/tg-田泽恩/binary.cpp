#include <bits/stdc++.h>
using namespace std;
int n,m,posx[2048],posy[2048],hgt,wid;
bool deleted[2048];
char tree[2048][3071];
void dfs1(int now,int lay){
	posx[now]=(lay==n)?hgt:hgt-(3<<(n-lay-1))+1;
	if(now&1) posy[now]=posy[now>>1]+(posx[now]-posx[now>>1]);
	else posy[now]=posy[now>>1]-(posx[now]-posx[now>>1]);
	if(lay>=n) return;
	dfs1(now<<1,lay+1);
	dfs1(now<<1|1,lay+1);
}
void dfs2(int now){
	tree[posx[now]][posy[now]]='o';
	if(now>=(1<<(n-1))) return;
	if(!deleted[now<<1]){
		for(int i=1;i<posx[now<<1]-posx[now];++i) tree[posx[now]+i][posy[now]-i]='/';
		dfs2(now<<1);
	}
	if(!deleted[now<<1|1]){
		for(int i=1;i<posx[now<<1|1]-posx[now];++i) tree[posx[now]+i][posy[now]+i]='\\';
		dfs2(now<<1|1);
	}
}
int main(){
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	cin>>n>>m;
	if(n==1){
		hgt=1;
		wid=1;
		posx[1]=1;
		posy[1]=1;
	}
	if(n==2){
		hgt=3;
		wid=5;
		posx[1]=1;
		posy[1]=3;
	}
	else{
		hgt=(3<<(n-2));
		wid=6*(1<<(n-2))-1;
		posx[1]=1;
		posy[1]=hgt;
	}
	
	dfs1(2,2);
	dfs1(3,2);
	int i,j;
	while(m--){
		cin>>i>>j;
		deleted[(1<<(i-1))+j-1]=true;
	}
	for(int i=1;i<=hgt;++i){
		for(int j=1;j<=wid;++j) tree[i][j]=' ';
	}
	if(!deleted[1]){
		dfs2(1);
	}
	for(int i=1;i<=hgt;++i){
		for(int j=1;j<=wid;++j) cout<<tree[i][j];
		puts("");
	}
	return 0;
} 
