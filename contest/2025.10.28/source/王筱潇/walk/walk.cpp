#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll a[200010],dp[10][200010],n;
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		dp[1][i]+=dp[1][i-1]+a[i];
		dp[2][i]+=min(dp[1][i-1],dp[2][i-1])+(a[i]&1);
		dp[3][i]+=min({dp[1][i-1],dp[2][i-1],dp[3][i-1]})+(1-(a[i]&1));
		dp[4][i]+=min({dp[1][i-1],dp[2][i-1],dp[3][i-1],dp[4][i-1]})+(a[i]&1);
		dp[5][i]+=min({dp[1][i-1],dp[2][i-1],dp[3][i-1],dp[4][i-1],dp[5][i-1]})+a[i];
		if(a[i]==0){
			dp[2][i]+=2;
			dp[4][i]+=2;
		}
	}
	printf("%lld",min({dp[1][n],dp[2][n],dp[3][n],dp[4][n],dp[5][n]}));
	return 0;
}
