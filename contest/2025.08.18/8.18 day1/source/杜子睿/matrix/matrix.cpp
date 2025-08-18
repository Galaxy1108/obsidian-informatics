#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[105][15],a[105][3],s[105][3],dp[2][105][105][15],ans[105][15];
int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			s[i][j]=s[i-1][j]+a[i][j];
		}
	if(m==1){
		for(int i=0;i<=n;i++){
			f[i][0]=0;
			for(int j=1;j<=k;j++)
				f[i][j]=-1e9;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++)
				f[i][j]=f[i-1][j];
			for(int j=i;j>=1;j--)
				for(int o=1;o<=k;o++)
					f[i][o]=max(f[i][o],f[j-1][o-1]+s[i][1]-s[j-1][1]);
		}
		cout<<f[n][k];
		return 0;	
	}
	for(int i=0;i<=n;i++)
		for(int j=i;j<=n;j++){
			dp[0][i][j][0]=dp[1][i][j][0]=0;
			for(int l=1;l<=k;l++)	
				dp[0][i][j][k]=dp[1][i][j][k]=-1e9;
		}
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--)
			for(int l=1;l<=k;l++){
				dp[0][j][i][l]=dp[0][j][i-1][l];
				dp[1][j][i][l]=dp[1][j][i-1][l];
			}
		for(int j=1;j<=i;j++)
			for(int l=j;l<=i;l++)
				for(int o=1;o<=k;o++){
					dp[0][j][i][o]=max(dp[0][j][i][o],dp[0][j][l-1][o-1]+s[i][1]-s[l-1][1]);
					dp[1][j][i][o]=max(dp[1][j][i][o],dp[1][j][l-1][o-1]+s[i][2]-s[l-1][2]);
				}
	}
	for(int i=0;i<=n;i++){
		ans[i][0]=0;
		for(int j=1;j<=k;j++)	
			ans[i][j]=-1e9;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++)
			ans[i][j]=ans[i-1][j];
		for(int j=1;j<=i;j++)
			for(int l=1;l<=k;l++){
				ans[i][l]=max(ans[i][l],ans[j-1][l-1]+s[i][1]-s[j-1][1]+s[i][2]-s[j-1][2]);
				for(int o=0;o<=l;o++)
					for(int p=0;p<=l-o;p++){
						ans[i][l]=max(ans[i][l],ans[j-1][l-o-p]+dp[0][j][i][o]+dp[1][j][i][p]);
					}
			}
	}
	cout<<ans[n][k];
	return 0;
}

