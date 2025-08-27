#include<cstdio>
using namespace std;
long long n,s,t,A,B,l,r,mid;
__int128 calc(__int128 x)
{
	return s-A*x+B*(n-x);
}
int T;
int main()
{
	freopen("never.in","r",stdin);
	freopen("never.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld%lld%lld",&n,&s,&t,&A,&B);
		s-=t;
		l=0,r=n;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(calc(mid)>=B) l=mid+1;
			else r=mid;
		}
		t+=calc(l);
		printf("%lld\n",t);
	}
}