#include<bits/stdc++.h>
using namespace std;

#define sc scanf
#define pr printf
#define REP(a,b,c) for(int a = b;a <= c;++a)
#define DOW(a,b,c) for(int a = b;a >= c;--a)
#define mmax(a,b,c) max(a,max(b,c))
const int MAXN = 8e3+10;
const int sw[25] = {0,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2}; 
const int INF = 1e9;

int dp[MAXN][22][4],n;
int w[MAXN],u[MAXN],t[MAXN],tmp;

int dpdu(int x,int y,int z,int dt){
	int ret = dp[x][y][z];
	REP(i,y,min(y+2*dt,20)) ret = max(ret,dp[x][i][z]);
	DOW(i,y,max(y-2*dt,1)) ret = max(ret,dp[x][i][z]);
	return ret;
}

int main(){
	freopen("sniper.in","r",stdin);
	freopen("sniper.out","w",stdout);
	sc("%d",&n);
	REP(i,1,n) sc("%d%d%d",&tmp,&u[i],&t[i]),w[i] = sw[tmp];
	REP(i,2,n) REP(j,1,20) REP(k,0,1) dp[i][j][k] = -INF;
	t[0] = -10;
	REP(i,1,n) REP(j,1,20){
		int dt = t[i]-t[i-1],dpdu1 = dpdu(i-1,j,0,dt),dpdu2 = dpdu(i-1,j,1,dt-1);
		dp[i][j][0] = max(dp[i-1][j][1],mmax(dp[i][j][0],dpdu1,(dt <= 1?-INF:dpdu2)));
		if(u[i] == j) dp[i][j][1] = mmax(dp[i][j][1],dpdu1+w[i],(dt <= 1?-INF:dpdu2)+w[i]);
		if(w[i] == 50) dp[i][j][0] = -INF,dp[i][j][0] = -INF;
	}
	int ans = -INF;
//	REP(i,1,n){
//		pr("%d %d %d\n",w[i],u[i],t[i]);
//		REP(j,1,20){
//			pr("dp[%d][%d] =",i,j);
//			REP(k,0,1) pr(" [%d]%d",k,dp[i][j][k]);
//			pr("\n");
//		}
//	}
	REP(i,1,20) REP(k,0,1) ans = max(ans,dp[n][i][k]);
	pr("%d",ans);
	
	return 0;
}
