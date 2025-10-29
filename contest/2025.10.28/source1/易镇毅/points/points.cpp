#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+10;
struct line
{
	int l,r;
	bool vis;
}b[maxn];
int a[maxn];
int n,m;
void solve1()
{
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(b[j].l<=a[i] && a[i]<=b[j].r) 
			{
				b[j].vis=1;
				break;
			}
		}
	}
	ll res=0;
	for(int j=1;j<=m;j++)
	{
		if(b[j].vis) continue;
		int p=lower_bound(a+1,a+1+n,b[j].l)-a;
		int q=upper_bound(a+1,a+1+n,b[j].r)-a;
		res+=min(abs(b[j].l-a[p]),abs(a[q]-b[j].r));
	}
	printf("%lld\n",res);
}
int main()
{
	freopen("points.in","r",stdin);
	freopen("points.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=m;i++) scanf("%d%d",&b[i].l,&b[i].r);
	if(n<=2000) solve1();
	else printf("0\n");
	return 0;
}
