#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int a[23][1122];
int n,m[23];
int x[23];
int temp[1122],len;
long long ans;
inline long long sqr(int x)
{
	return 1ll*x*x;
}
long long cal()
{
	long long res = 0;
	for (int i=1;i<=n;i++)
	{
		int j = i+1;
		if (j>n) j = 1;
		len = 0;
		for (int t=x[i];t<=m[i];t++)
			temp[++len] = a[i][t];
		for (int t=1;t<x[j];t++)
			temp[++len] = a[j][t];
		temp[++len] = 0;
		temp[++len] = 2e6;
		sort(temp+1,temp+len+1);
		for (int i=1;i<len;i++)
			res += sqr(temp[i+1]-temp[i]);
	}
	return res;
}
void dfs(int id)
{
	if (id>n)
	{
		ans = min(ans,cal());
		return ;
	}
	for (int t=1;t<=m[id];t++)
	{
		x[id] = t;
		dfs(id+1);
	}
}
int main()
{
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",m+i);
		for (int j=1;j<=m[i];j++)
			scanf("%d",a[i]+j);
	}
	ans = 1e18;
	dfs(1);
	printf("%lld",ans);
	return 0;
}
