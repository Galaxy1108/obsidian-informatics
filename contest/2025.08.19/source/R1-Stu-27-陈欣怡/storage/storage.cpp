#include<cstdio>
#include<cstring>
#define ri register int 
using namespace std;
const long long inf=0x3f3f3f3f3f3f3f3f;
const int mm=2e3+100;
int d[mm],p[mm],c[mm];
long long s1[mm],s2[mm],f[mm][mm];
inline int read()
{
	long long ans=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0' && ch<='9') ans=(ans<<3)+(ans<<1)+(ch^48),ch=getchar();
	return ans*f;
}
inline long long min(long long a,long long b) {return a<b?a:b;}
int main()
{
	freopen("storage.in","r",stdin);
	freopen("storage.out","w",stdout);
	int n=read();
	for(ri i=1;i<=n;i++) d[i]=read(),p[i]=read(),c[i]=read(),s1[i]=s1[i-1]+p[i],s2[i]=s2[i-1]+1LL*d[i]*p[i];
	memset(f,0x3f3f,sizeof(f));
	f[n][n]=0;
	for(ri i=n;i>=1;i--)
	for(ri j=i;j>=1;j--)
	for(ri k=j;k>=1;k--)  f[k][j]=min(f[k][j],f[j][i]+1LL*d[j]*(s1[j-1]-s1[k])-s2[j-1]+s2[k]+(k!=j)*c[j]);	
	long long ans=f[1][1]+c[1];
	for(ri i=2;i<=n;i++) ans=min(ans,f[1][i]+min(1LL*c[i],1LL*d[i]*p[1]));
	printf("%lld",ans);
	return 0;
 } 
