#include<bits/stdc++.h>
using namespace std;

#define sc scanf
#define pr printf
#define REP(a,b,c) for(int a = b;a <= c;++a) 
#define REP(a,b,c) for(int a = b;a <= c;++a) 
typedef long long ll;

const int MAXN = 0;
const int MOD = 0;

int n,m;
ll p;
ll dp[3005][3005],DB_p;

ll Dfs(int m,int a){
	if(dp[m][a] != 0) return dp[m][a];
	ll ret = 0; 
	if(m == 0) return 1;
	if(a > 0) ret += (Dfs(m-1,a-1)+Dfs(m-1,a))%p;
	if(a < n) ret += (Dfs(m-1,a)+Dfs(m-1,a+1))%p;
	dp[m][a] = ret;
	return ret;
}

/*
1 1 4
1 2 8    2 1 8
1 3 16   3 1 16  2 2 16
1 4 32  ...
*/

int main(){
	
	freopen("easyhard.in","r",stdin);
	freopen("easyhard.out","w",stdout);
	sc("%d%d%lld",&n,&m,&p);
	ll ans = 1;
	REP(i,1,m+n) ans *= 2,ans %= p;
	pr("%lld",ans);
	
	return 0;
}
