#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
typedef long double ld;
int n,m;
ld dp[N][N][2];
int main(){
	freopen("mouse.in","r",stdin);
	freopen("mouse.out","w",stdout);
	scanf("%d%d",&n,&m);
	dp[0][0][0]=dp[0][0][1]=0;
	for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)for(int k=0;k<2;k++)if(i||j){
		if(k==0){//A先 
			if(j)dp[i][j][k]=(ld)j/(i+j)*dp[i][j-1][!k];
			dp[i][j][k]+=(ld)i/(i+j);
		}else{
			if(j){
				if(j>=2)dp[i][j][k]+=(ld)(j-1)/(i+j-1)*dp[i][j-2][!k];
				if(i>=1)dp[i][j][k]+=(ld)i/(i+j-1)*dp[i-1][j-1][!k];
				dp[i][j][k]*=(ld)j/(i+j);
			}
		}
	}printf("%.9Lf\n",dp[n][m][0]);
	return 0;
}
/*
记dp[x][y]表示x个白球,y个黑球,A先手,A获胜的概率 
*/
