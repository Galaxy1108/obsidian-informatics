#include<cstdio>
#include <cstring>
long long dp[1001][1001];
int a[1001],b[1001];
long long min(long long a,long long b){
	return a<b?a:b;
}
int main(){
	freopen("kyoto.in", "r", stdin);
	freopen("kyoto.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	memset(dp, 0x3f, sizeof(dp));
	dp[1][1]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			// if(i!=1&&j!=1) printf("<%10d,%10d,%10lld,%10lld>",b[j],a[i],dp[i-1][j]+b[j],dp[i][j-1]+a[i]);
			if(i!=1||j!=1) dp[i][j]=min(dp[i-1][j]+b[j],dp[i][j-1]+a[i]);
			// printf("%lld\n",dp[i][j]);
		}
		// printf("\n");
	}
	printf("%lld",dp[n][m]);
}