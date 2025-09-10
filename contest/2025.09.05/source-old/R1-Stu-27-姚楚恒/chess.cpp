#include<bits/stdc++.h>
#define p 9999973
#define int long long
using namespace std;
int n,m,dp[110][110][110],ans;
inline int C(int x){return x*(x-1)/2%p;}
signed main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			for(int k=0;k<=m-j;k++){
				dp[i][j][k]=dp[i-1][j][k];
				if(k>=1)dp[i][j][k]+=dp[i-1][j+1][k-1]*(j+1);
				if(j>=1)dp[i][j][k]+=dp[i-1][j-1][k]*(m-j-k+1);
				if(k>=2)dp[i][j][k]+=dp[i-1][j+2][k-2]*(j+2)*(j+1)/2;
				if(k>=1)dp[i][j][k]+=dp[i-1][j][k-1]*j*(m-j-k+1);
				if(j>=2)dp[i][j][k]+=dp[i-1][j-2][k]*C(m-j-k+2);
				dp[i][j][k]%=p;
			}
		}
	}
	for(int i=0;i<=m;i++)for(int j=0;j<=m;j++)ans+=dp[n][i][j],ans%=p;
	return printf("%lld",ans%p),0;
}
