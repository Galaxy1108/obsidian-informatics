#include <bits/stdc++.h>
using namespace std;
#define N 105
#define INF 0x3f3f3f3f
int n,m,k,mx[N][N],minh[N],minl[N];
long long MOD,ans=0; 
void solve(){
	for(int i=1;i<=m;i++){
		minl[i]=INF;
	}
	for(int i=1;i<=n;i++){
		minh[i]=INF;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			minh[i]=min(minh[i],mx[i][j]);
			minl[j]=min(minl[j],mx[i][j]);
		}
	}
	long long tot=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			tot=tot*min(minh[i],minl[j])%MOD;
		}
	}
	ans=(ans+tot);
	while(ans>=MOD){
		ans-=MOD;
		break;
	}
	return ;
}
void dfs(int x,int y){
	if(x>n){
		solve();
		return ;
	}
	if(y>m){
		dfs(x+1,1);
		return ;
	}
	for(int i=1;i<=k;i++){
		mx[x][y]=i;
		dfs(x,y+1);
	}
}
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%d%d%d%lld",&n,&m,&k,&MOD);
	dfs(1,1);
	printf("%lld",ans);
	return 0;
}
