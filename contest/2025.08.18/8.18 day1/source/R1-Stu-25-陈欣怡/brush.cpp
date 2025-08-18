#include<cstdio>
#include<cstring>
#define ri register int
using namespace std;
const int mm=1e4+100;
const int inf=0x3f3f3f3f;
int a[mm],f[mm][mm];
inline int read()
{
	int ans=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0' && ch<='9') ans=(ans<<3)+(ans<<1)+(ch^48),ch=getchar();
	return ans*f;
}
inline int min(int a,int b) {return a<b?a:b;}
inline int max(int a,int b) {return a>b?a:b;}

int main()
{
	freopen("brush.in","r",stdin);
	freopen("brush.out","w",stdout);
	memset(f,0x3f,sizeof(f));
	int n=read(),m=read();
	for(ri i=1;i<=n;i++) a[i]=read();
	for(ri i=0;i<=n;i++) f[i][0]=0;
	f[1][1]=a[1],f[2][1]=min(a[1],a[2]),f[2][2]=a[1]+a[2];
	for(ri i=3;i<=n;i++)
	{
		int minf=inf,mins=inf,t=max(0,i-m);
		for(ri j=t+1;j<=i;j++)  if(a[j]<minf) mins=minf,minf=a[j];else if(a[j]<mins) mins=a[j];
		f[t][-1]=-mins;
		for(ri j=1;j<=i;j++)
		f[i][j]=min(f[i][j],f[t][j-2]+minf+mins);	
	}
	int ans=0;
	for(ri i=1;i<=n;i++) {if(f[n][i]==inf) break; ans=f[n][i];}
	printf("%d",ans);
	return 0;
}
