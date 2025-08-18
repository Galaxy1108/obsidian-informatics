#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	if(m==1){
		int a[110],dp[110][20];
		memset(dp,0,sizeof(dp));
		int x;
		a[0]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			a[i]=a[i-1]+x;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++){
				dp[i][j]=dp[i-1][j];
				for(int v=0;v<i;v++){
					dp[i][j]=max(dp[i][j],dp[v][j-1]+a[i]-a[v]);
				}
			}
		}
		printf("%d",dp[n][k]);
	}
	if(m==2){
		int a[110],b[110],dp[110][110][20];
		int x,y;
		a[0]=0;
		b[0]=0;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			scanf("%d%d",&x,&y);
			a[i]=a[i-1]+x;
			b[i]=b[i-1]+y;
		}
		for(int v=1;v<=k;v++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dp[i][j][v]=max(dp[i-1][j][v],dp[i][j-1][v]);
					for(int c=0;c<i;c++){
						dp[i][j][v]=max(dp[i][j][v],dp[c][j][v-1]+a[i]-a[c]);
					}
					for(int c=0;c<j;c++){
						dp[i][j][v]=max(dp[i][j][v],dp[i][c][v-1]+b[j]-b[c]);
					}
					if(i==j){
						for(int c=0;c<i;c++){
							dp[i][j][v]=max(dp[i][j][v],dp[c][c][v-1]+a[i]-a[c]+b[j]-b[c]);
						}
					}
				}
			}
		}
		printf("%d",dp[n][n][k]);
	}
	return 0;
} 
