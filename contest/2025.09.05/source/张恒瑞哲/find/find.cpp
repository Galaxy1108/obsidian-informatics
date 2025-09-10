#include<bits/stdc++.h>
using namespace std;

#define pr printf
#define sc scanf
#define REP(a,b,c) for(int a = b;a <= c;++a)
#define DOW(a,b,c) for(int a = b;a >= c;--a)
#define fi first
#define se second

typedef long long ll;

const int INF = INT_MAX;
const long long LNF = LLONG_MAX;
const double Pi = 3.1415926535;
const double EPS = 1e-7;

const int MAXN = 1e3+5;
const int MOD = 1e9+7;

int mmap[MAXN][MAXN];
int f[MAXN],ans[MAXN*MAXN];

int ff(int x){
	int ret = 1;
	while(x){
		ret *= x%10;
		x /= 10;
	}
	return ret;
}



int main(){

	freopen("find.in","r",stdin);
	freopen("find.out","w",stdout);

	int m,n,tot = 0;
	sc("%d%d",&m,&n);
	ll fans = 0;
	REP(i,1,m) f[i] = ff(i);
	REP(i,1,m) REP(j,1,m) mmap[f[i]][f[j]]++;
	REP(i,1,m) REP(j,1,m) ans[tot++] = mmap[i][j];
	sort(ans,ans+1+m*m,[](int a,int b){ return a > b; });
	REP(i,0,n-1) fans += ans[i],fans %= MOD;
	pr("%lld",fans);

	return 0;
}
