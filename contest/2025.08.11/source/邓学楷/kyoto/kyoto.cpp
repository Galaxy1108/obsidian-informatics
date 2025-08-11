#include <cstdio>
typedef long long ll;

int h,w;
ll ans[5010][5010],hl[5010],wl[5010];

ll min(ll x,ll y)
{
	return x<y?x:y;
}

int main()
{
	freopen("kyoto.in","r",stdin);
	freopen("kyoto.out","w",stdout);
	scanf("%d%d",&h,&w);
	for (int i=1;i<=h;i++)
		scanf("%lld",hl+i);
	for (int i=1;i<=w;i++)
		scanf("%lld",wl+i);
	for (int i=2;i<=h;i++)
		ans[i][1]=ans[i-1][1]+wl[1];
	for (int i=2;i<=w;i++)
		ans[1][i]=ans[1][i-1]+hl[1];
	for (int i=2;i<=h;i++)
		for (int j=2;j<=w;j++)
			ans[i][j]=min(ans[i-1][j]+wl[j],ans[i][j-1]+hl[i]);
	printf("%lld\n",ans[h][w]);
	return 0;
}
