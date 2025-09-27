#include <cstdio>
#include <algorithm>
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define abs(x) ((x)>=0?(x):(-(x)))
#define inf 0x7f7f7f7f

int n,m,L[100010],R[100010];

bool check(int x)
{
	int il=1,ir=1;
	if (n<=m)
	{
		while (il<=n && ir<=m)
		{
			while (abs(L[il]-R[ir])>x && ir<=m)
				ir++;
			if (abs(L[il]-R[ir])>x)
				return 0;
			il++,ir++;
		}
		return il==n+1;
	}
	else
	{
		while (il<=n && ir<=m)
		{
			while (abs(L[il]-R[ir])>x && il<=n)
				il++;
			if (abs(L[il]-R[ir])>x)
				return 0;
			ir++,il++;
		}
		return ir==m+1;
	}
}

int main()
{
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout);
	int l,r,mid,ans;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",L+i);
	for (int i=1;i<=m;i++)
		scanf("%d",R+i);
	std::sort(L+1,L+n+1);
	std::sort(R+1,R+m+1);
	l=0,r=max(L[n]-R[0],R[m]-L[0]);
	while (l<=r)
	{
		mid=(l+r)/2;
		if (check(mid))
			r=mid-1,ans=mid;
		else
			l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}
