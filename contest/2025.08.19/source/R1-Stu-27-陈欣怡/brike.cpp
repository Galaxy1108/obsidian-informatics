#include<cstdio>
#include<cstring>
#define ri register int 
using namespace std;
const int mm=60;
int a[mm][mm],s[mm][mm],f[mm][mm][mm*10];
inline int read()
{
	long long ans=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0' && ch<='9') ans=(ans<<3)+(ans<<1)+(ch^48),ch=getchar();
	return ans*f;
}
inline int max(int a,int b) {return a>b?a:b;}
int main()
{
	freopen("brike .in","r",stdin);
	freopen("brike .out","w",stdout);
	int n=read(),m=read();
	for(ri i=1;i<=n;i++)
	for(ri j=1;j<=n-i+1;j++) a[i][j]=read(),s[i][j]=s[i-1][j+1]+a[i][j];
	for(ri i=1;i<=n;i++)
	for(ri j=1;j<=n-i+1;j++)
	for(ri k=1;k<=m;k++) f[i][j][k]=max(f[i-1][j][k-i]+s[i-1][j+1],f[i-1][j+1][k-2]+a[i-1][j])+a[i][j];
	int ans=0;
	for(ri i=1;i<=n;putchar('\n'),i++)
	for(ri j=1;j<=n-i+1;j++) 
	for(ri k=1;k<=m;k++)  printf("%d ",f[i][j][k]),ans=max(ans,f[i][j][m]);
	printf("%d",ans);
	return 0;
}
