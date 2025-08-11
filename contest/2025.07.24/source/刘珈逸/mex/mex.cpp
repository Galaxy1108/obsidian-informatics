#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,mod=998244353;
int n,m,s[N];
int dp[N][N];//第i个,有j个数 
void chk(int&x,int y){
	x+=y;if(x>=mod)x-=mod;
}
int main(){
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	scanf("%d%d",&n,&m);m++;
	for(int i=1;i<=n;i++)scanf("%d",s+i);
	dp[0][0]=1;
	for(int i=0;i<n;i++)for(int j=0;j<=min(i,m);j++)
		if(s[i+1])chk(dp[i+1][j+1],dp[i][j]);
		else chk(dp[i+1][j+1],1ll*dp[i][j]*(m-j-1)%mod),chk(dp[i+1][j],1ll*dp[i][j]*j%mod);
	int ans=0;
	for(int i=0;i<=min(n,m);i++)chk(ans,dp[n][i]);
	printf("%d\n",ans);
	return 0;
}
/*
n<=m是显然的
若1的个数>m 无解
*/
