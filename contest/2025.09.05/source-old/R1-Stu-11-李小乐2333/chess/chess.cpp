#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=101,mod=9999973;
int f[2][N][N],c[N][N],n,m;
signed  main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m;
	f[0][0][0]=1;
	for(int i=0;i<=m;i++){
		c[i][0]=1;
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			for(int l=0;j+l<=m;l++){
				f[i&1][j][l]=(f[i&1^1][j][l]
				+c[m-j+1-l][1]*f[i&1^1][j-1][l]*(j-1>=0)
				+c[j+1][1]*f[i&1^1][j+1][l-1]*(j+1<=m)*(l-1>=0)
				+c[m-j+2-l][2]*f[i&1^1][j-2][l]*(j-2>=0)
				+c[j+2][2]*f[i&1^1][j+2][l-2]*(j+2<=m)*(l-2>=0)
				+c[m-j-l+1][1]*c[j][1]*f[i&1^1][j][l-1]*(l-1>=0))%mod;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=m;i++)
		for(int j=0;j<=m;j++)
			ans=(ans+f[n&1][i][j])%mod;
	cout<<ans<<endl;
}
