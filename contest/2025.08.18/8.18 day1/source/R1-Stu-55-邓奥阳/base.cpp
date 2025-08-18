#include<cstdio>
using namespace std;
const int inf=999999999;
int n,a[3][2010];
int f[2010][4],ans;
int max(int a,int b){return a>b?a:b;}
int main()
{
	freopen("base.in","r",stdin);
	freopen("base.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[1][i]);
	for(int i=1;i<=n;++i)scanf("%d",&a[2][i]);
	
	ans=-inf;
	for(int i=0;i<=n;++i)f[i][1]=f[i][2]=f[i][3]=-inf;
	
	for(int i=1;i<=n;++i)
	{
		f[i][1]=max(f[i-1][1],0)+a[1][i]+a[2][i];
		f[i][2]=max(f[i-1][1],f[i-1][2])+a[2][i];
		f[i][3]=max(f[i-1][2],f[i-1][3])+a[1][i]+a[2][i];
		ans=max(ans,f[i][3]);
	}
	printf("%d",ans);
	return 0;
}
