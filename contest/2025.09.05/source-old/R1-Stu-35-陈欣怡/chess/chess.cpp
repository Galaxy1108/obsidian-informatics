#include<cstdio>
#define ri register int 
#define il inline 
#define gc getchar()
using namespace std;
const int mm=110,mod=9999973;
long long f[mm][mm][mm];
il int read()
{
	int ans=0,f=1;char ch=gc;
	while(ch<'0' || ch>'9') {if(ch=='-') f=-1;ch=gc;}
	while(ch>='0' && ch<='9') ans=(ans<<3)+(ans<<1)+(ch^48),ch=gc;
	return ans;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int n=read(),m=read();
	f[0][0][0]=1;
	for(ri k=1;k<=n;k++)
	for(ri i=0;i<=m;i++)
	for(ri j=0;j<=m-i;j++) 
	{
		f[k][i][j]=f[k-1][i][j];
		if(j>=1) f[k][i][j]=(f[k][i][j]+f[k-1][i+1][j-1]*(i+1))%mod;
		if(i>=1) f[k][i][j]=(f[k][i][j]+f[k-1][i-1][j]*(m-i-j+1))%mod;
		if(j>=1) f[k][i][j]=(f[k][i][j]+(f[k-1][i][j-1]*i)*(m-i-j+1))%mod;
		if(i>=2) f[k][i][j]=(f[k][i][j]+(f[k-1][i-2][j]*(m-i-j+2)*(m-i-j+1)/2))%mod;
		if(j>=2) f[k][i][j]=(f[k][i][j]+((f[k-1][i+2][j-2]*(i+2)*(i+1)/2)))%mod;  
	}
	long long ans=0;
	for(ri i=0;i<=m;i++)
	for(ri j=0;j<=m-i;j++) ans=(ans+f[n][i][j])%mod;
	printf("%lld",ans);
	return 0;
}
