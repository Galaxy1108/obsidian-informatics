#include<bits/stdc++.h>
using namespace std;
int dp[55][55][505],n,m;
int su[55][55];
int mi[55][55][505],ans;
int h[55][55];
int main(){
	freopen("brike.in","r",stdin);
	freopen("brike.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n-i+1;++j){
			scanf("%d",&h[i][j]);
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n-i+1;++j){
			su[i][j]=su[i][j-1]+h[j][i];
		}
	}
	memset(dp,-(0x3f),sizeof(dp));
	memset(mi,-(0x3f),sizeof(mi));
	for(int i=0;i<=n;++i) dp[0][i][0]=0;
	mi[0][0][0]=dp[0][0][0];
	for(int i=1;i<=n;++i) {
		mi[0][i][0]=max(mi[0][i-1][0],dp[0][i][0]);
	}
	for(int i=1;i<=n;++i) dp[i][0][0]=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=n-i+1;++j){
			for(int k=0;k<=m;++k){
				dp[i][j][k]=max(dp[i][j][k],su[i][j]+max(mi[i-1][j][k-j],dp[i-1][j+1][k-j]));
				if(k==m&&j==1){
					ans=max(ans,dp[i][j][k]);
				}
				if(j==0)mi[i][j][k]=dp[i][0][k];
				else mi[i][j][k]=max(mi[i][j-1][k],dp[i][j][k]);
			}
		}
	}
	cout<<ans;
	return 0;
}
