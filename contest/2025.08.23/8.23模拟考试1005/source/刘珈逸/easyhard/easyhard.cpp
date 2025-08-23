#include<bits/stdc++.h>
using namespace std;
const int N=6e3+5;
int n,m,mod,dp[N/2][N][2];//当前是第i次,黑球有j个,黑球是否取完过 
void chk(int&x,int y){
	x+=y;if(x>=mod)x-=mod;
}
int ans;
int main(){
	freopen("easyhard.in","r",stdin);
	freopen("easyhard.out","w",stdout);
	scanf("%d%d%d",&n,&m,&mod);
	dp[0][0][1]=1;
	for(int i=1;i<=n;i++)dp[0][i][0]=1;
	for(int i=0;i<=m;i++)for(int j=0;j<=n;j++)for(int k=0;k<2;k++){
		if(j)chk(dp[i+1][j][k||(j==1)],dp[i][j][k]),chk(dp[i+1][j-1][k||(j==1)],dp[i][j][k]);
		if(j!=n)chk(dp[i+1][j][k],dp[i][j][k]),chk(dp[i+1][j+1][k],dp[i][j][k]);
	}
	for(int i=0;i<=n;i++)chk(ans,dp[m][i][1]);
	printf("%d\n",ans);
	return 0;
}
