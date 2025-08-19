#include<cstdio>
#define ll long long
#define db double
using namespace std;
int n;
ll cost;
int w[2010];
db c[2010],d[2010],ans;
template <class T>
T max(T a,T b){return a>b?a:b;}
void dfs(int now,db hv1,db hv2)
{
	if(now==n+1)
	{
		ans=max(ans,hv1);
		return;
	}
	hv1+=w[now];
	if(hv1+hv2*d[now]>=cost)dfs(now+1,hv1+hv2*d[now]-cost,0);
	dfs(now+1,0,hv2+c[now]*hv1);
	dfs(now+1,hv1,hv2);
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d%lld",&n,&cost);
	for(int i=1;i<=n;++i)
		scanf("%d%lf%lf",&w[i],&c[i],&d[i]);
	dfs(1,0,0);
	printf("%.4lf",ans);
	return 0;
}
