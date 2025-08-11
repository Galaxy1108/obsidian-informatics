#include <cstdio>

int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int T;
	long long s,k;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lld%lld",&s,&k);
		if (s%2==1 && k<=s/2)
			printf("%lld\n",k*2);
		else
			printf("-1\n");
	}
	return 0;
}
