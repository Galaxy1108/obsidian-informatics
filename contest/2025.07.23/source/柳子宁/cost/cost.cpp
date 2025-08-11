#include<bits/stdc++.h>
#define inf 1000000000000000000
using namespace std;
int n;
int col[2100],L[2100],R[2100],siz[2100];
long long delta,ans;
long long C[2][2100];
long long F[2100][2100],sum[2100][2100],f[2100][2100];
void dfs(int x){
	if(x>=(1<<n)){
		f[x][0]=C[0][x-(1<<n)];
		f[x][1]=C[1][x-(1<<n)];
		return;
	}
	for(int i=0;i<=siz[x];++i) f[x][i]=inf;
	//Na>=Nb
	for(int i=L[x<<1];i<=R[x<<1];++i){
		C[0][i]=C[0][i]-sum[i][R[x<<1|1]]+sum[i][R[x<<1]];
	}
	for(int i=L[x<<1|1];i<=R[x<<1|1];++i){
		C[1][i]=C[1][i]+sum[i][R[x<<1]];
		if(L[x<<1]) C[1][i]=C[1][i]-sum[i][L[x<<1]-1];
	}
	dfs(x<<1);
	dfs(x<<1|1);
	for(int i=0;i<=siz[x<<1];++i){
		for(int j=0;j<=siz[x<<1|1];++j){
			if(i+j>siz[x<<1]) continue;
			f[x][i+j]=min(f[x][i+j],f[x<<1][i]+f[x<<1|1][j]);
		}
	}
	for(int i=L[x<<1];i<=R[x<<1];++i){
		C[0][i]=C[0][i]+sum[i][R[x<<1|1]]-sum[i][R[x<<1]];
	}
	for(int i=L[x<<1|1];i<=R[x<<1|1];++i){
		C[1][i]=C[1][i]-sum[i][R[x<<1]];
		if(L[x<<1]) C[1][i]=C[1][i]+sum[i][L[x<<1]-1];
	}
	//Na<Nb
	for(int i=L[x<<1];i<=R[x<<1];++i){
		C[1][i]=C[1][i]-sum[i][R[x<<1|1]]+sum[i][R[x<<1]];
	}
	for(int i=L[x<<1|1];i<=R[x<<1|1];++i){
		C[0][i]=C[0][i]+sum[i][R[x<<1]];
		if(L[x<<1]) C[0][i]=C[0][i]-sum[i][L[x<<1]-1];
	}
	dfs(x<<1);
	dfs(x<<1|1);
	for(int i=0;i<=siz[x<<1];++i){
		for(int j=0;j<=siz[x<<1|1];++j){
			if(i+j<=siz[x<<1]) continue;
			f[x][i+j]=min(f[x][i+j],f[x<<1][i]+f[x<<1|1][j]);
		}
	}
	for(int i=L[x<<1];i<=R[x<<1];++i){
		C[1][i]=C[1][i]+sum[i][R[x<<1|1]]-sum[i][R[x<<1]];
	}
	for(int i=L[x<<1|1];i<=R[x<<1|1];++i){
		C[0][i]=C[0][i]-sum[i][R[x<<1]];
		if(L[x<<1]) C[0][i]=C[0][i]+sum[i][L[x<<1]-1];
	}
	return;
}
void dfs1(int x){
	if(x>=(1<<n)){
		L[x]=(x)-(1<<n);
		R[x]=(x)-(1<<n);
		siz[x]=1;
		return;
	}
	dfs1(x<<1),dfs1(x<<1|1);
	L[x]=L[x<<1],R[x]=R[x<<1|1];
	siz[x]=siz[x<<1]+siz[x<<1|1];
	return;
}
int main()
{
	freopen("cost.in","r",stdin);
	freopen("cost.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<(1<<n);++i) scanf("%d",&col[i]);
	for(int i=0;i<(1<<n);++i) scanf("%lld",&C[col[i]^1][i]);
	for(int i=0;i<(1<<n);++i){
		for(int j=i+1;j<(1<<n);++j){
			scanf("%lld",&F[i][j]);
			F[j][i]=F[i][j];
			delta+=F[i][j];
		}
	}
	for(int i=0;i<(1<<n);++i){
		sum[i][0]=F[i][0];
		for(int j=0;j<(1<<n);++j){
			sum[i][j]=sum[i][j-1]+F[i][j];
		}
	}
	dfs1(1);
	dfs(1);
	ans=inf;
	for(int i=0;i<=siz[1];++i) ans=min(ans,f[1][i]);
	printf("%lld\n",ans+delta);
	return 0;
}
