#include<bits/stdc++.h>
using namespace std;
const int N=105,mod=9999973;
int n,m,dp[N][N][N];//dp[i][j][k]表示现在是第i行,有j列放0个子,k列放1个子 
int C2(int x){
	return x*(x-1)/2;
}
void chk(int&x,int y){
	(x+=y)>=mod&&(x-=mod);
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	dp[0][m][0]=1;
	for(int i=0;i<n;i++)for(int j=0;j<=m;j++)for(int k=0;k+j<=m;k++){
		chk(dp[i+1][j][k],dp[i][j][k]);
		if(j)chk(dp[i+1][j-1][k+1],1ll*dp[i][j][k]*j%mod);
		if(k)chk(dp[i+1][j][k-1],1ll*dp[i][j][k]*k%mod);
		if(j>=2)chk(dp[i+1][j-2][k+2],1ll*dp[i][j][k]*C2(j)%mod);
		if(j&&k)chk(dp[i+1][j-1][k],1ll*dp[i][j][k]*j*k%mod);
		if(k>=2)chk(dp[i+1][j][k-2],1ll*dp[i][j][k]*C2(k)%mod);
	}
	int ans=0;
	for(int i=0;i<=m;i++)for(int j=0;i+j<=m;j++)chk(ans,dp[n][i][j]);
	printf("%d\n",ans);
	return 0;
}
