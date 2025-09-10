#include<bits/stdc++.h>
#define ll unsigned long long
#define F(i,a,b) for(int i(a);i<=b;++i)
#define R(i,a,b) for(int i(a);i>=b;--i)
#define _ 0
using namespace std;
const int MOD=9999973;
int n,m;
ll dp[2][101][101],ans;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	dp[1][0][0]=1,dp[1][1][0]=m,dp[1][2][0]=m*(m-1)/2;
	F(i,2,n) F(j,0,m) F(k,0,m){
		if(j+k>m) break;
		dp[i&1][j][k]=dp[(i-1)&1][j][k];
		if(j-1>=0) dp[i&1][j][k]=(dp[i&1][j][k]+(m-j-k+1)*dp[(i-1)&1][j-1][k]%MOD)%MOD;
		if(j+1<=m&&k-1>=0) dp[i&1][j][k]=(dp[i&1][j][k]+(j+1)*dp[(i-1)&1][j+1][k-1]%MOD)%MOD;
		if(j-2>=0) dp[i&1][j][k]=(dp[i&1][j][k]+(m-j-k+2)*(m-j-k+1)/2*dp[(i-1)&1][j-2][k]%MOD)%MOD;
		if(k-1>=0) dp[i&1][j][k]=(dp[i&1][j][k]+(m-j-k+1)*j*dp[(i-1)&1][j][k-1]%MOD)%MOD;
		if(j+2<=m&&k-2>=0) dp[i&1][j][k]=(dp[i&1][j][k]+(j+2)*(j+1)/2*dp[(i-1)&1][j+2][k-2]%MOD)%MOD;
	}
	F(j,0,m) F(k,0,m){
		if(j+k>m) break;
		ans=(ans+dp[n&1][j][k])%MOD;
	}
	cout<<ans;
	return ~~(0^_^0);
}
