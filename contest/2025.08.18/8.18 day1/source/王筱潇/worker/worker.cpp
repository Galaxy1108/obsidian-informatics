#include<bits/stdc++.h>
using namespace std;
int dp[110][20][20][20],i,j,k,m,n;
char c[110];
int main(){
	freopen("worker.in","r",stdin);
	freopen("worker.out","w",stdout);
	scanf("%d\n",&n);
	for(i=1;i<=n;i++){
		scanf("%c\n",&c[i]);
	}
	for(i=0;i<=n;i++){
		for(j=0;j<=10;j++){
			for(k=0;k<=10;k++){
				for(m=0;m<=10;m++){
					dp[i][j][k][m]=100;
				}
			}
		}
	}
	dp[0][0][0][0]=0;
	for(i=1;i<=n;i++){
		for(j=0;j<=10;j++){
			for(k=0;k<=10;k++){
				for(m=0;m<=10;m++){
					if(j+k+m>10) continue;
					if(c[i]=='A'&&j) dp[i][j][k][m]=dp[i-1][j-1][k][m];
					if(c[i]=='B'&&k) dp[i][j][k][m]=dp[i-1][j][k-1][m];
					if(c[i]=='C'&&m) dp[i][j][k][m]=dp[i-1][j][k][m-1];
					dp[i][0][k][m]=min(dp[i][0][k][m],dp[i][j][k][m]+1);
					dp[i][j][0][m]=min(dp[i][j][0][m],dp[i][j][k][m]+1);
					dp[i][j][k][0]=min(dp[i][j][k][0],dp[i][j][k][m]+1);
				}
			}
		}
	}
	printf("%d",dp[n][0][0][0]);
	return 0;
} 
