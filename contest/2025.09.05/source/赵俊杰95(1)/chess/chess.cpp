#include<bits/stdc++.h>
using namespace std;
const int N=205;
const int MOD=9999973;
int f[N][N][N];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	f[0][0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			for(int k=0;k<=m;k++)
			{
				if(j+k>m)continue;
				f[i][j][k]=f[i-1][j][k];
				if(k>0)f[i][j][k]+=1ll*f[i-1][j+1][k-1]*(j+1)%MOD;
				if(j>0)f[i][j][k]+=1ll*f[i-1][j-1][k]*(m-j-k+1)%MOD;
				if(j>0&&k>0)f[i][j][k]+=1ll*f[i-1][j][k-1]*j*(m-j-k+1)%MOD;
				if(j>1)f[i][j][k]+=1ll*f[i-1][j-2][k]*(m-j-k+2)*(m-j-k+1)/2%MOD;
				if(k>1)f[i][j][k]+=1ll*f[i-1][j+2][k-2]*(j+2)*(j+1)/2%MOD;
				f[i][j][k]%=MOD;
				//cout<<j<<' '<<k<<' '<<f[i][j][k]<<'\n';
			}
		}
	}
	int ans=0;
	for(int j=0;j<=m;j++)
		for(int k=0;k<=m;k++)
			ans=(ans+f[n][j][k])%MOD;
	cout<<ans<<'\n';
	return 0;
}
