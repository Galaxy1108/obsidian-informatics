#include<cstdio>
#define ri register int 
using namespace std;
const int mm=2020;
long long f[mm][mm];
int a[mm],b[mm],s1[mm],s2[mm],maxn=-0x3f3f3f3f;
inline int read()
{
	int ans=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0' && ch<='9') ans=(ans<<3)+(ans<<1)+(ch^48),ch=getchar();
	return ans*f;
}
inline int max(int a,int b) {return a>b?a:b;}

int main()
{
	freopen("base.in","r",stdin);
	freopen("base.out","w",stdout);
	int n=read();
	for(ri i=1;i<=n;i++) a[i]=read(),s1[i]=s1[i-1]+a[i];
	for(ri i=1;i<=n;i++) b[i]=read(),s2[i]=s2[i-1]+b[i];
	for(ri len=3;len<=n;len++)
	for(ri l=1;l<=n;l++)
	{
		int r=l+len-1;f[l][r]=maxn;
		for(ri i=l;i+2<=r;i++)
		for(ri j=i+2;j<=r;j++)
		f[l][r]=max(f[l][r],s2[r]-s2[l-1]+s1[r]-s1[j-1]+s1[i]-s1[l-1]);
		maxn=max(maxn,f[l][r]);
	}
	printf("%lld",f[1][n]);
	return 0;
}
/*
4
1 3 -4 5
-2 6 -1 7
*/
