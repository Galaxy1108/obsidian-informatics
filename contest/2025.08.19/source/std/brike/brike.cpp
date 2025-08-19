#include<bits/stdc++.h>
#define inf 99999999
using namespace std;
int n,m,a[101][101],s[101][101],f[101][501][101],ans=-inf;
signed main(){
	freopen("brike.in","r",stdin);
	freopen("brike.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			cin>>a[i][j],s[i][j]=s[i-1][j]+a[i][j];
		}
	}
	for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)for(int k=0;k<=n;k++)f[i][j][k]=-inf;
	f[0][0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			for(int k=0;k<=min(j,n-i+1);k++){
				for(int l=0;l<=k+1;l++){
					f[i][j][k]=max(f[i][j][k],f[i-1][j-k][l]);
				}
				f[i][j][k]+=s[k][i];
			}
		}
	}
	for(int k=0;k<=1;k++)ans=max(ans,f[n][m][k]);
	cout<<ans<<endl;
	return 0;
}
