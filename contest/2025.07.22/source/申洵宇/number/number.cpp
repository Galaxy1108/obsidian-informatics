#include <bits/stdc++.h>
using namespace std;
#define N 300005
int n,m;
long long val[N],a[N],sum,ans;
void dfs(int x){
	if(x>m){
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		sum+=val[x]-2ll*a[i];
		a[i]=val[x]-a[i];
		dfs(x+1);
		sum+=val[x]-2ll*a[i];
		a[i]=val[x]-a[i];
	}
}
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%lld",&val[i]);
	}
	ans=0xc0c0c0c0c0c0c0c0ll;
	sum=0;
	dfs(1);
	printf("%lld\n",ans);
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}
