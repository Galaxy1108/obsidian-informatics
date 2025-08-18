#include<cstdio>
#include<cstring>
#define ri register int 
using namespace std;
const int mm=110;
int a[mm][mm],f[mm][mm][mm/10],s[mm][mm];
inline int read()
{
	int ans=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0' && ch<='9') ans=(ans<<3)+(ans<<1)+(ch^48),ch=getchar();
	return ans*f;
}
inline int max(int a,int b) {return a>b?a:b;}
inline int min(int a,int b) {return a<b?a:b;}
int main()
{
	memset(f,-0x3f,sizeof(f));
	int n=read(),m=read(),t=read();
	for(ri i=1;i<=n;i++) 
	for(ri j=1;j<=m;j++) a[i][j]=read(),s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
	
	return 0;
}
/*
3 2 2
1 -3
2 3
-2 3
*/
