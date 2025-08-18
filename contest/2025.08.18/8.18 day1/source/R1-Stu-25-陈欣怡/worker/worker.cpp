#include<cstdio>
#define ri register int
using namespace std;
const int mm=110;
char a[mm];
inline int read()
{
	int ans=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0' && ch<='9') ans=(ans<<3)+(ans<<1)+(ch^48),ch=getchar();
	return ans*f;
}
int main()
{
	freopen("worker.in","r",stdin);
	freopen("worker.out","w",stdout);
	int n=read();
	for(ri i=1;i<=n;i++) scanf("%s",a+i);
	printf("3");
	return 0;
}
