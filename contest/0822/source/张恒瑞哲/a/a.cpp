#include<bits/stdc++.h>
using namespace std;

#define sc scanf
#define pr printf
#define REP(a,b,c) for(int a = b;a <= c;++a) 
#define DOW(a,b,c) for(int a = b;a >= c;--a)
typedef long long ll;

const int MAXN = 1;
const int MOD = 0;

int m,n;
ll dp[2][60][60],p;
int a = 1;
int main(){
	
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	
	sc("%d%d%lld",&n,&m,&p); ll ans = 1;
	if(m == 1){ pr("1"); return 0; }
	if(n == 1){ 
		REP(i,2,m) ans += i,ans %= p;
		pr("%lld",ans);
		return 0 ;
	}
	
	REP(l,1,m) REP(r,l,m) dp[1][l][r] = 1;
	REP(i,2,n){
		a^=1;
		REP(l,1,m) REP(r,l,m){
			ll ttmp = 0;
			REP(s,1,r) REP(t,max(l,s),m) ttmp += dp[a^1][s][t],ttmp %= p;
			dp[a][l][r] = ttmp;
		//	pr("dp[%d->%d][%d][%d] = %d\n",i,a,l,r,dp[a][l][r]);
		}
	} 	
		
	ans = 0;
	REP(l,1,m) REP(r,l,m) ans += dp[a][l][r],ans %= p;
	pr("%lld",ans);
	
	return 0;
}
