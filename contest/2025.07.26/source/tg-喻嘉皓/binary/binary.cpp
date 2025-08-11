#include<bits/stdc++.h>
using namespace std;
int n,m;
int X,Y; 
int dep[12],spa[12],shen[12];
int cut[12][(1<<10)+10];
char mp[1030][2030];
void init(){
	dep[1]=1;dep[2]=3;
	shen[1]=1;shen[2]=3;
	for(int i=3;i<=m;i++){
		dep[i]=dep[i-1]*2;
		shen[i]=dep[i];
	}
	for(int i=2;i<=m;i++){
		spa[i]=(dep[i]-1)*2+1;
	}
	for(int i=1;i<=m/2;i++){
		swap(shen[i],shen[m-i+1]);
		swap(spa[i],spa[m-i+1]);
	}
	X=shen[1],Y=shen[1]*2-1;
	for(int i=1;i<=m;i++){
		dep[i]=X-shen[i]+1;
	}
	for(int i=1;i<=X;i++){
		for(int j=1;j<=Y;j++){
			mp[i][j]=' ';
		}		
	}

}
void solve(int now){
	if(now==m){
		int ad=1;
		for(int i=1;i<=(1<<(now-1));i++){
			if(cut[now][i]){
				if(i%2==0) ad+=2;
				else ad+=4;
				continue;
			}
			int x=dep[now],y=ad;
			mp[x][y]='o';
			if(i%2==0) ad+=2;
			else ad+=4;
		}
		return;
	}
	int ad=shen[now];
	for(int i=1;i<=(1<<(now-1));i++,ad+=spa[now]+1){//标志第now层第i个
		if(cut[now][i]) continue; 
		int x=dep[now],y=ad;
		mp[x][y]='o';
		bool flag1=1,flag2=1;
		if(cut[now+1][(i-1)*2+1]) flag1=0;
		if(cut[now+1][i*2]) flag2=0;
		for(int j=1;j<=shen[now]-shen[now+1]-1;j++){
			if(flag1) mp[x+j][y-j]='/';
			if(flag2) mp[x+j][y+j]='\\'; 
		}
	}
	solve(now+1);
	
}
void dfs(int x,int y){
	if(x>m||cut[x][y]) return;
	cut[x][y]=1;
	dfs(x+1,y*2-1);
	dfs(x+1,y*2);
}
void prin(){
	for(int i=1;i<=X;i++){
		for(int j=1;j<=Y;j++){
			cout<<mp[i][j];
		}
		cout<<'\n';
	}
}
int main(){
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		dfs(x,y);
	}
	init();
	solve(1);
	prin();
	return 0;
}

 
