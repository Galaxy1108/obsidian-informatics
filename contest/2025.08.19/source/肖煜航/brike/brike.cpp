#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=55;
int n,m;
int a[N][N];
int s[N][N];
int f[N][N][505];
int dfs(int x,int y,int z){
	if(f[x][y][z]!=-1) return f[x][y][z];
	if(y>z) return -1e9;
	if(x==0){
		if(y==0&&z==0) return 0;
		else return -1e9;
	}
	int res=0;
	int to=x-1;
	for(int i=0;i<=n-to+1;i++){
		if(y>=i-1){
			res=max(res,dfs(x-1,i,z-y)+s[y][x]);
		}
	}
	return f[x][y][z]=res;
}
int main(){
	freopen("brike.in","r",stdin);
	freopen("brike.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n-j+1;i++){
			s[i][j]=s[i-1][j]+a[i][j];
		}
	}
	memset(f,-1,sizeof f);
	printf("%d",max(dfs(n,1,m),dfs(n,0,m)));
	return 0;
}
