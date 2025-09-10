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

const int MAXN = 15;
const ll MOD = 9999973;

bool mmap[MAXN][MAXN];

int row[MAXN],col[MAXN];
int m,n;
ll ans;

void Dfs(int y){
	if(y == n+1){
		REP(i,1,m) if(col[i] > 2) return;
		ans++;
		ans %= MOD;
		return;
	}
	Dfs(y+1);
	REP(i,1,m){
		col[i]++;
		Dfs(y+1);
		col[i]--;
	}
	REP(i,1,m){
		REP(j,i+1,m){
			col[i]++,col[j]++;
			Dfs(y+1);
			col[i]--,col[j]--;
		}
	}
}

int main(){

	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	sc("%d%d",&n,&m);
	Dfs(1);
	pr("%lld",ans);

	return 0;
}

