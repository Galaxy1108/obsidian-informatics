#include <bits/stdc++.h>
using namespace std;
const int N=110;
const int mod=9999973;
int f[N][N][N],n,m,ans;
inline int C(int x)
{
	return (x*(x-1)/2)%mod;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m;
	f[0][0][0]=1;
	for(int i=1;i<=n;i++)
	for(int j=0;j<=m;j++)
	for(int k=0;k<=m-j;k++)
	{f[i][j][k]=f[i-1][j][k];
	if(k>=1)(f[i][j][k]+=f[i-1][j+1][k-1]*(j+1));
	if(j>=1)(f[i][j][k]+=f[i-1][j-1][k]*(m-j-k+1));
	if(k>=2)(f[i][j][k]+=f[i-1][j+2][k-2]*(((j+2)*(j+1))/2));
	if(k>=1)(f[i][j][k]+=f[i-1][j][k-1]*j*(m-j-k+1));
	if(j>=2)(f[i][j][k]+=f[i-1][j-2][k]*C(m-j-k+2));
	f[i][j][k]%=mod;
    }
	for(int i=0;i<=m;i++)
	for(int j=0;j<=m;j++)
	ans+=f[n][i][j],ans%=mod;
	cout<<ans;
	return 0;
} 
