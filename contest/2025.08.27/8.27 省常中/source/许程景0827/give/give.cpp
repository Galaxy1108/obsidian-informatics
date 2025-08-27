#include <cstdio>
int all[2001],dp[2001][2];
int main(){
	freopen("give.in","r",stdin);
	freopen("give.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int m,s,n;
		scanf("%d%d%d",&m,&s,&n);
		for(int i=0;i<n;i++) scanf("%d",&all[i]);
		dp[0][0]=1;for(int i=1;i<=s;i++) dp[i][0]=0;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=s;j++){
				dp[j][i&1]=0;
				for(int k=0;k<n;k++){
					if(j>=all[k]) dp[j][i&1]^=dp[j-all[k]][!(i&1)];
				}
			}
			dp[0][!(i&1)]=0,dp[0][!(i&1)]=0;
		}
		printf("%d\n",dp[s][m&1]);
	}
}