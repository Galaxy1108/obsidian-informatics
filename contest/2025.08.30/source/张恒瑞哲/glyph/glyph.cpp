#include<bits/stdc++.h>
using namespace std;

#define sc scanf
#define pr printf
#define REP(a,b,c) for(int a = b;a <= c;++a)
#define DOW(a,b,c) for(int a = b;a >= c;--a)

typedef long long ll;

const int MAXN = 305;
const int MOD = 0;

int a[MAXN][MAXN];
int sx,sy,tx,ty,n,q,qt;
ll ans;
struct Num{ll v;int t;};
Num dp[MAXN][MAXN];

void Dfs(int xx,int yy,ll sum){
//	pr("Dfs %d %d\n",xx,yy);
	sum += 1ll*a[xx][yy];
	if(dp[xx][yy].t != qt) dp[xx][yy].t = qt,dp[xx][yy].v = sum;
	else dp[xx][yy].v = min(dp[xx][yy].v,sum);
	if(xx == tx && yy == ty){ ans = min(ans,sum); return; }
	if(sum > ans || sum > dp[xx][yy].v) return;
	if(xx+1 <= tx && xx+1 <= n) Dfs(xx+1,yy,sum);
	if(yy+1 <= ty && yy+1 <= n) Dfs(xx,yy+1,sum);
}

int main(){

	freopen("glyph.in","r",stdin);
	freopen("glyph.out","w",stdout);
	sc("%d%d",&n,&q);
	REP(i,1,n) REP(j,1,n) sc("%d",&a[i][j]);
	while(q--){
		ans = LLONG_MAX; qt++;
		sc("%d%d%d%d",&sx,&tx,&sy,&ty);
		Dfs(sx,sy,0);
		pr("%lld\n",ans);
	}

	return 0;
}
