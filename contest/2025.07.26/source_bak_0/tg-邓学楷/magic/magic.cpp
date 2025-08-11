#include <cstdio>
#include <cstring>

int n,q,a[200010],b[200010];

void card(int x[])
{
	int l[100010],r[100010];
	for (int i=1;i<=n/2;i++)
		l[i]=x[i],r[i]=x[i+n/2];
	int al=1,ar=1,ind=1;
	while (al<=n/2 && ar<=n/2)
		x[ind++]=l[al]<r[ar]?l[al++]:r[ar++];
	if (al>n/2)
	{
		while (ar<=n/2)
			x[ind++]=r[ar++];
	}
	else if (ar>n/2)
	{
		while (al<=n/2)
			x[ind++]=l[al++];
	}
}

int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout); 
	int t,x;
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	while (q--)
	{
		memcpy(b+1,a+1,(n+1)*4);
		scanf("%d%d",&t,&x);
		while (t--)
			card(b);
		printf("%d\n",b[x]);
	}
	return 0;
}
