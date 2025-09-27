#include <cstdio>
#define max(x,y) ((x)>(y)?(x):(y))

int n,a[100010],xsum[100010],st[100010][30],log[100010];
long long cnt;

void build()
{
	for (int i=1;i<=n;i++)
		st[i][0]=a[i];
	for (int j=1;j<=log[n];j++)
		for (int i=1;i<=n-(1<<j)+1;i++)
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}

int query(int l,int r)
{
	int k=log[r-l+1];
	return max(st[l][k],st[r-(1<<k)+1][k]);
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		xsum[i]=xsum[i-1]^a[i];
		if (i>1)
			log[i]=log[i/2]+1;
	}
	build();
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
			if ((xsum[j]^xsum[i-1])<=query(i,j))
				cnt++;
	printf("%lld\n",cnt);
	return 0;
}
