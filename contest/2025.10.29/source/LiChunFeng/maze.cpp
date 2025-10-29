#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define File(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define N 1001

using namespace std;
typedef long long llg;

int zx[4]={0,0,-1,1},zy[4]={1,-1,0,0};
int n,m,X,Y,dx[N],dy[N],l,r;
int w[14][14],dis[15][15],f[15][15];

int main(){
	File("maze");
	scanf("%d %d %d %d",&n,&m,&X,&Y);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",&w[i][j]);
			dis[i][j]=-1;
		}
	dx[r]=1,dy[r++]=1; f[1][1]=dis[1][1]=1;
	while(l!=r){
		int x=dx[l],y=dy[l++];
		for(int k=0,i,j;k<4;k++){
			i=x+zx[k],j=y+zy[k];
			if(i>=1 && i<=n && j>=1 && j<=m && !w[i][j])
				if(dis[i][j]==-1){
					dis[i][j]=dis[x][y]+1;
					f[i][j]=f[x][y];
					dx[r]=i,dy[r++]=j;
				}
				else if(dis[i][j]==dis[x][y]+1)
					f[i][j]+=f[x][y];
		}
	}
	printf("%d",f[X][Y]);
}
