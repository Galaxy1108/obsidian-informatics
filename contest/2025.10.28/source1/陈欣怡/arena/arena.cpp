#include<cstdio>
#define il inline
#define ri register int
#define gc getchar()
using namespace std;
il int read()
{
	int ans=0,f=1;char ch=gc;
	while(ch<'0' || ch>'9') {if(ch=='-') f=-1;ch=gc;}
	while(ch>='0' && ch<='9') ans=(ans<<3)+(ans<<1)+(ch^48),ch=gc;
	return ans*f; 
}
const int mm=510,mod=998244353;
int f[2][mm][mm][mm],c[mm][mm];
il int ksm(int base,int k)
{
	int ans=1;
	while(k)
	{
		if(k&1) ans=1LL*ans*base%mod;
		base=1LL*base*base%mod,k>>=1;
	}
	return ans;
}
il void init(int n)
{
	for(ri i=0;i<=n;i++) c[0][i]=1;
	for(ri j=1;j<=n;j++)
	for(ri i=1;i<=j;i++) c[i][j]=(c[i][j-1]+c[i-1][j-1])%mod;
}
il int min(int a,int b) {return a<b?a:b;}
il void file()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
}
int main()
{
	file();
	int n=read(),x=read();
	if(n>x) {printf("%d",ksm(x,n));return 0;}
	if(n==1){puts("0");return 0;}
	init(n),f[0][n][n][0]=1;
	int i=0,flag=true;long long ans=0;
	while(flag)
	{
		flag=false;
		for(ri j=2;j<=n;j++)
		for(ri k=0;k<=n;k++)
		for(ri p=0;p<=x;p++)
		{
			if(k==1 || f[i][j][k][p]==0 || x-p<j) continue ;
			if(k==0) {ans=(ans+f[i][j][k][p])%mod,f[i][j][k][p]=0;continue;}
			for(ri t=0;t<=k;t++)
			if(t!=1) f[i^1][k][t][p+j-1]=(((1LL*f[i][j][k][p]*ksm(min(x-p,k-1),k-t))%mod)*c[k-t][k])%mod,flag=true;
			f[i][j][k][p]=0;
		}
		i^=1;
	}
	printf("%lld",ans);
	return 0;
 } 
