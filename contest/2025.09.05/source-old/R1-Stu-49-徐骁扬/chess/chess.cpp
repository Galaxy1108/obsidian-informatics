#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
const int Mod=9999973;
int n,m,i,j,k;
long long f[110][110][110];
long long C[110][110],ans;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	for(i=1;i<=100;i++)
	for(j=0;j<=i;j++)
	{
		if(j==0||j==i) C[i][j]=1;
		else C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
	}
	n=Qread();m=Qread();
	f[0][0][0]=1;
	for(i=1;i<=n;i++)
	for(j=0;j<=m&&j<=i;j++)
	for(k=0;k+j<=m;k++)
	{
		(f[i][j][k]+=f[i-1][j][k])%=Mod;
		if(i>=2&&j>=2) (f[i][j][k]+=f[i-1][j-2][k+2]*C[k+2][2])%=Mod;
		if(i>=2&&j>=1&&k>=1) (f[i][j][k]+=f[i-1][j-1][k]*C[k][1]%Mod*C[m-j-k+1][1])%=Mod;
		if(i>=2&&j>=1) (f[i][j][k]+=f[i-1][j-1][k+1]*C[k+1][1])%=Mod;
		if(k>=2) (f[i][j][k]+=f[i-1][j][k-2]*C[m-j-k+2][2])%=Mod;
		if(k>=1) (f[i][j][k]+=f[i-1][j][k-1]*C[m-j-k+1][1])%=Mod;
	}
	for(j=0;j<=m;j++)
	for(k=0;k+j<=m;k++)
		(ans+=f[n][j][k]%Mod%Mod)%=Mod;
	printf("%lld",ans);
	return 0;
}
