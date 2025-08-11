#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,p,ans=1;
ll a[30][30];
void dfs(ll f,ll g){
	if(f==n+1){
		ll cnt=1,minn;
		for(ll i=1;i<=n;i++){
			minn=10;
			for(int j=1;j<=m;j++){
				minn=min(minn,a[i][j]);
			}
			cnt=(cnt*minn)%p;
		}
		for(ll j=1;j<=m;j++){
			minn=1;
			for(int i=1;i<=n;i++){
				minn=min(minn,a[i][j]);
			}
			cnt=(cnt*minn)%p;
		}
		ans=(ans+cnt)%p;
		return;
	}
	for(ll i=1;i<=k;i++){
		a[f][g]=i;
		g++;
		if(g>m){
			g=1;
			f++;
		}
		dfs(f,g);
		g--;
		if(g<1){
			g=m;
			f--;
		}
	}
	return;
}
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&m,&k,&p);
	dfs(1,1);
	printf("%lld",ans);
}
