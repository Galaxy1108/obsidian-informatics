#include<bits/stdc++.h>
using namespace std;
const long long p=9999973;
int n,m;
long long dp[101][101][101];
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m;
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			for(int k=0;k+j<=m;k++){
				dp[i][j][k]=dp[i-1][j][k];
				if(j)dp[i][j][k]=(dp[i][j][k]+dp[i-1][j-1][k]*(m-j-k+1))%p;
				if(k)dp[i][j][k]=(dp[i][j][k]+dp[i-1][j+1][k-1]*(j+1))%p;
				if(j>=2)dp[i][j][k]=(dp[i][j][k]+dp[i-1][j-2][k]*(m-j-k+2)*1ll*(m-j-k+1)/2)%p;
				if(j&&k)dp[i][j][k]=(dp[i][j][k]+dp[i-1][j][k-1]*j*(m-j-k+1)*1ll)%p;//!!!
				if(k>=2)dp[i][j][k]=(dp[i][j][k]+dp[i-1][j+2][k-2]*(j+2)*1ll*(j+1)/2)%p;
			}
		}
	}
	long long ans=0;
	for(int i=0;i<=m;i++){
		for(int j=0;j+i<=m;j++){
			ans=(dp[n][i][j]+ans)%p;
		}
	}
	cout<<ans<<endl;
	return 0;
}
