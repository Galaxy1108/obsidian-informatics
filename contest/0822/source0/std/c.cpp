#include <cstdio>
#include <random>
#include <algorithm>
using namespace std;
int read(){
	char c=getchar();int x=0;
	while(c<48||c>57) c=getchar();
	do x=(x<<1)+(x<<3)+(c^48),c=getchar();
	while(c>=48&&c<=57);
	return x;
}
int n,seed;
const int N=5004;
int a[N][N],b[N][N],c[N];
bool vis[N];
int res[N];
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	n=read();seed=read();
	mt19937 rng(seed);
	if(seed){
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n+1;++j){
				a[i][j]=j;
				swap(a[i][j],a[i][rng()%j+1]);
			}
	}
	else{
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n+1;++j) a[i][j]=read();
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n+1;++j) b[i][a[i][j]]=j;
	for(int i=n;i;--i){
		c[i]=1;
		while(vis[b[i][c[i]]]) ++c[i];
		vis[b[i][c[i]]]=1;
	}
	int cur=1;
	while(vis[cur]) ++cur;
	res[1]=cur;
	for(int i=n;i>1;--i){
		int x=b[i][c[i]];
		vis[x]=0;
		for(int t=i-1;t;--t)
			if(a[t][x]<c[t]){
				vis[x]=1;
				int tmp=b[t][c[t]];
				c[t]=a[t][x];
				vis[x=tmp]=0;
			}
		for(int t=n;t>i;--t)
			if(a[t][x]<c[t]){
				vis[x]=1;
				int tmp=b[t][c[t]];
				c[t]=a[t][x];
				vis[x=tmp]=0;
			}
		if(a[i][x]>a[i][cur]) swap(cur,x);
		vis[x]=1;
		c[i]=a[i][x];
		res[i]=cur;
	}
	for(int i=1;i<=n;++i) printf("%d ",res[i]);
	putchar('\n');
	return 0;
}
