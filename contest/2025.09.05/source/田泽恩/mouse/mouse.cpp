#include <bits/stdc++.h>
using namespace std;
int n,m,now;
double dp[2][1145][1145];
double ans;
const double eps=1e-10;
int main(){
	freopen("mouse.in","r",stdin);
	freopen("mouse.out","w",stdout);
	scanf("%d%d",&n,&m);
	dp[0][n][m]=1.0;
	for(int i=1;i<=(m+1)>>1;++i){
		for(int j=0;j<=n;++j){
			for(int k=0;k<=m-2*(i-1);++k){
				if(dp[now][j][k]<eps) continue;
				ans+=dp[now][j][k]*j/(j+k);
				if(k>=3) dp[now^1][j][k-3]+=dp[now][j][k]*k*(k-1)*(k-2)/(j+k)/(j+k-1)/(j+k-2);
				if(j>=1&&k>=2) dp[now^1][j-1][k-2]+=dp[now][j][k]*k*(k-1)*j/(j+k)/(j+k-1)/(j+k-2);
				dp[now][j][k]=0.0;
			}
		}
		now^=1;
	}
	printf("%.9lf",ans);
	return 0;
}
