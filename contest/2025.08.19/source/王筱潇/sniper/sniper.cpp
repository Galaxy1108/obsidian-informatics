#include <bits/stdc++.h>
using namespace std;
int a[30]={0,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2};
int dp[30][25010],f[30][25010],n;
int main(){
	freopen("sniper.in","r",stdin);
	freopen("sniper.out","w",stdout);
	scanf("%d",&n);
	int w,u,t,flag=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&w,&u,&t);
		if(w==15){
			for(int k=1;k<=20;k++){
				f[k][t]=0;
			}
			f[u][t]=w;
			flag=t;
		}
		if(t==flag) continue;
		else f[u][t]=w;
	}
	for(int j=1;j<=t+1;j++){
		for(int i=1;i<=20;i++){
			if(f[i][j]!=0&&f[i][j]!=15){
				dp[i][j]=dp[i][j-1];
				for(int k=i-2;k<=i+2;k++){
					if(k<1) continue;
					if(k>20) break;
					if(f[k][j-1]!=-1){
						dp[i][j]=max(dp[i][j],dp[k][j-1]+a[f[k][j]]);
					}
				}
				if(dp[i][j]!=dp[i][j-1]) f[i][j]=-1;
			}
			else if(f[i][j]==15){
				for(int k=1;k<=20;k++){
					dp[k][t]=0;
				}
				for(int k=i-2;k<=i+2;k++){
					if(k<1) continue;
					if(k>20) break;
					if(f[k][j-1]!=-1){
						dp[i][j]=max(dp[i][j],dp[k][j-1]+a[f[k][j]]);
					}
				}
				f[i][j]=-1;
				break;
			}
			else if(f[i][j]==0){
				for(int k=i-2;k<=i+2;k++){
					if(k<1) continue;
					if(k>20) break;
					dp[i][j]=max(dp[i][j],dp[k][j-1]);
				}
			}
//			printf("%d ",dp[i][j]); 
		}
//		printf("\n");
	}
	int ans=0; 
	for(int i=1;i<=20;i++){
		ans=max(ans,dp[i][t+1]);
	}
	printf("%d",ans);
	return 0;
}
