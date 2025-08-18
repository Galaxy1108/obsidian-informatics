#include<cstdio>
using namespace std;
int n,m,a[10010];
bool vis[10010];
int ans=999999999;
void dfs(int now,int hv,int nans)
{
	if(nans>=ans)return;
	if(hv<1&&now>=m)return;
	if(now==n+1)
	{
		ans=nans;return;
	}
	if(vis[now-m])hv--;
	if(hv>1||now<m)dfs(now+1,hv,nans);
	vis[now]=1,dfs(now+1,hv+1,nans+a[now]),vis[now]=0;
}
int main()
{
	freopen("brush.in","r",stdin);
	freopen("brush.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	dfs(1,0,0);
	printf("%d",ans);
	return 0;
}
