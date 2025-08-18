#include<bits/stdc++.h>
#define inf 1000000000000000000
using namespace std;
int n,m;
long long a[10010],ans;
long long f[2][110][110];
int main()
{
	freopen("brush.in","r",stdin);
	freopen("brush.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	for(int o=0;o<=1;++o){
		for(int i=0;i<m;++i){
			for(int j=0;j<m;++j){
				f[o][i][j]=inf;
			}
		}
	}
	f[0][0][0]=0;
	for(int k=1;k<=n;++k){
		int o=k&1;
		for(int i=0;i<m;++i){
			for(int j=i;j<m;++j){
				f[o][i][j]=inf;
			}
		}
		for(int i=0;i<m;++i){
			for(int j=i;j<m;++j){
				if(f[o^1][i][j]==inf) continue;
				int x=i+1,y=j+1;
				if(y<m) f[o][x][y]=min(f[o][x][y],f[o^1][i][j]);
				x=0,y=i+1;
				if(y<m) f[o][x][y]=min(f[o][x][y],f[o^1][i][j]+a[k]);
			}
		}
	}
	ans=1000000000000000000;
	for(int i=0;i<m;++i){
		for(int j=i;j<m;++j){
			ans=min(ans,f[n&1][i][j]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
