#include<bits/stdc++.h>
using namespace std;
const int N=20,n=16,k=3;
int col[N][N];
int cnt[N][3];
void dfs(int x,int y){
	if(x==n+1){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				printf("%d%c",col[i][j]," \n"[j==n]);
		exit(0);
	}
	for(int i=0;i<3;i++)if(cnt[x][i]&&cnt[y][i]){
//		fprintf(stderr,"%d %d %d\n",x,y,i);
		bool flag=1;
		for(int j=1;j<x;j++)if(col[j][x]==i&&col[j][y]==i){
			flag=0;
			break;
		} 
		if(flag){
			cnt[x][i]--,cnt[y][i]--;
			col[x][y]=i;
			if(y==n)dfs(x+1,x+2);
			else dfs(x,y+1);
			cnt[x][i]++,cnt[y][i]++;
		}
	}
}
int main(){
	freopen("ramsey3.out","w",stdout);
	for(int i=1;i<=n;i++)for(int j=0;j<3;j++)cnt[i][j]=5;
	dfs(1,2);
	return 0;
}
