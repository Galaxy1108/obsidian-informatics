#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	int n,m,mod;cin>>n>>m>>mod;
	vector<vector<vector<int>>>f(n+1);
	for(int i=0;i<=n;i++){
		f[i].resize(m+1);
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			f[i][j].resize(m+1);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			f[0][i][j]=1;
		}
	}
	cout<<"now\n;";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=j;k<=m;k++){
				//[j,k]
				for(int l=1;l<j;l++){
					for(int r=l;r<j;r++){
						f[i][l][r]=(f[i][l][r]+f[i-1][j][k])%mod;
					}
				}
				for(int l=j+1;l<=m;l++){
					for(int r=l;r<=m;r++){
						f[i][l][r]=(f[i][l][r]+f[i-1][j][k])%mod;
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=m;i++){
		for(int j=i;j<=m;j++){
			ans=(ans+f[n][i][j])%mod;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
