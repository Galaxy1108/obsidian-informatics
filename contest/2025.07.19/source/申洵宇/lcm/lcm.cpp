#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353ll
long long n,k,ans;
inline long long gcd(long long x,long long y){
	static long long t;
	while(y!=0){
		t=y;
		y=x%y;
		x=t;
	}
	return x;
}
void dfs(long long now,int x){
	if(x>k){
		ans=(ans*now)%MOD;
		return ;
	}
	for(long long i=1;i<=n;i++){
		dfs(now/gcd(now,i)*i,x+1);
	}
}
void solve(){
	ans=1;
	scanf("%lld%lld",&n,&k);
	dfs(1,1);
	printf("%lld\n",ans);
}
int main(){
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}
