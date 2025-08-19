#include <bits/stdc++.h>
#define inf 1e9
using namespace std;
int n,m,a[60][60],dp[60][2510],maxn[60][2510],ans=-1;
int main(){
	freopen("brike.in","r",stdin);
	freopen("brike.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x;
	for(int j=1;j<=n;j++){
		for(int i=n;i>=j;i--){
			scanf("%d",&x);
			a[i][j]=a[i][j-1]+x;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			for(int k=min(j+i*(i-1)/2,m);k>=j*(j+1)/2;k--){
				dp[j][k]=maxn[j-1][k-j]+a[i][j];
				maxn[j][k]=max(maxn[j+1][k],dp[j][k]);
				ans=max(ans,dp[j][k]);
			}
		}
		for(int k=i*(i-1)/2+1;k<=i*(i+1)/2;k++){
			for(int j=k-i*(i-1)/2-1;j>=0;j--){
				maxn[j][k]=max(maxn[j+1][k],dp[j][k]);
			}
		}
		for(int k=1;k<=i*(i+1)/2;k++){
			maxn[0][k]=max(maxn[1][k],maxn[0][k]);
		}
	}
	printf("%d",ans);
	return 0;
} 
