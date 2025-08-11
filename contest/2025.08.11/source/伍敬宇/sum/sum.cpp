#include <cstdio>
using namespace std;
int t;
long long s,k;
void work()
{
	scanf("%lld%lld",&s,&k);
	if (k>(s-1)/2)
	{
		printf("-1\n");
		return ;
	}
	if (s%2==1)
	{
		printf("%lld\n",k*2);
		return ;
	}
	long long x = 1;
	while (s%x==0) x++;
	long long kl = (s/2-1)/x;
	if (k<=kl)
	{
		printf("%lld\n",x*k);
		return ;
	}
	else 
	{
		long long kr = (s/2-1) - k + 1;
		long long idx = (kr-1)/(x-1);
		long long cur = idx*x + (kr-1)%(x-1)+1;
		printf("%lld\n",s-cur);
	}
}
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%d",&t);
	while(t--) work();
	return 0;
}
