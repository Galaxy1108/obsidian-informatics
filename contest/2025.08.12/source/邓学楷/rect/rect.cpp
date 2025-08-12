#include <cstdio>

int n,m,a[510][510];

int main()
{
	int cnt=1;
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	char c;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			scanf(" %c",&c);
			a[i][j]=(c=='C');
		}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (a[i][j])
				printf("%d ",cnt++);
			else
				printf("0 ");
		}
		putchar('\n');
	}
	return 0;
}
