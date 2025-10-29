#include <bits/stdc++.h>
using namespace std;
struct node {
	int step,x,y;
}q[4000001];
int n,m,x,y,ans=0,dis=0;
int g[20][20],f[20][20];
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	cin>>n>>m;
	cin>>x>>y;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>g[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		if(g[i][1]!=1)f[i][1]=1;
	}
	for(int i=1;i<=m;i++){
		if(g[1][i]!=1) f[1][i]=1;
	} 
	for(int i=2;i<=x;i++){
		for(int j=2;j<=y;j++){
			if(g[i][j]=='1') f[i][j]=0;
			else f[i][j]=f[i-1][j]+f[i][j-1];
		}
	}
	cout<<f[x][y]<<endl;
	return 0;
} 
