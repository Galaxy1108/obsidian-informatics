#include<bits/stdc++.h>
#define Max(a,b) a=max(a,b)
using namespace std;
int n,m; 
int mp[60][60];
int sum[60][60];
int f[60][60][510];
int main(){
	freopen("brike.in","r",stdin);
	freopen("brike.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			cin>>mp[i][j];
			sum[i][j]=sum[i-1][j]+mp[i][j];
		}
	}
	int ans=0;
	for(int j=1;j<=n+1;j++){//ÁÐ 
		for(int i=0;i<=n-j+1;i++){//ÐÐ 
			for(int k=i;k<=m;k++){
				Max(f[j][i][k],f[j-1][i][k-i]+sum[i][j]);
				Max(f[j][i][k],f[j-1][i+1][k-i]+sum[i][j]);
				if(i) Max(f[j][i][k],f[j][i-1][k-1]+mp[i][j]);
			}
		}
		ans=max(ans,f[j][0][m]);
	}
	cout<<ans;
	return 0;
}

