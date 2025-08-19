#include<cstdio>
#define ll long long
using namespace std;
const ll inf=1145141919810;
int n;
ll x[1000010],p[1000010],c[1000010];
ll f[1000010],g[1000010],sumh[1000010],sump[1000010];
ll H(int a,int b)//a~b-1全扔到b的花费
{
	if(a==b)return 0;
	return sumh[b]-sumh[a]-(x[b]-x[a])*1ll*sump[a-1];
}
ll min(ll a,ll b){return a<b?a:b;}
int main()
{
	freopen("storage.in","r",stdin);
	freopen("storage.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld%lld%lld",&x[i],&p[i],&c[i]),sump[i]=sump[i-1]+p[i];
	for(int i=2;i<=n;++i)
		sumh[i]=sumh[i-1]+sump[i-1]*(x[i]-x[i-1]);
		
		
	for(int i=1;i<=n;++i)
		f[i]=g[i]=inf;
	f[n]=c[n];g[n]=c[n];
	for(int i=n-1;i>=1;--i)
	{
		f[i]=g[i+1]+c[i];
		for(int j=i;j<=n;++j)
			g[i]=min(g[i],f[j]+H(i,j));
	}
	printf("%lld",g[1]);
	return 0;
}
