#include <cstdio>
using namespace std;
const int MAXN = 1e6 + 12;
long long f[MAXN],p,g,ans;
int cnt[MAXN<<2];
int stk[MAXN],top;
int n;
int pm[33],tm[33],idx;
void breakdown(long long x)
{
	idx = 0;
	for (int i=2;i*i<=x;i++)
	{
		if (x%i!=0) continue ;
		idx ++;
		pm[idx] = i;
		tm[idx] = 0;
		while (x%i==0) 
		{
			tm[idx] ++;
			x = x/i;
		}
	}
	if (x>1)
	{
		++idx;
		pm[idx] = x;
		tm[idx] = 1;
	}
	for (int i=1;i<=idx;i++)
	{
		if (cnt[pm[i]]>=tm[i]) continue ;
		if (cnt[pm[i]]==0) stk[++top] = pm[i];
		while (cnt[pm[i]]<tm[i]) cnt[pm[i]]++,g = g*pm[i]%p;
	}
}
void work()
{
	top = 0;
	scanf("%d%lld",&n,&p);
	f[1] = 1;
	for (int i=2;i<=n;i++)
		f[i] = (f[i-1]*2+f[i-2]);
	g = 1,ans = 0;
	for (int i=1;i<=n;i++) 
	{
		breakdown(f[i]);
		ans = (i*g+ans)%p;
	}
	while (top) cnt[stk[top--]] = 0;
	printf("%lld\n",ans);
}
int main()
{
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--) work();
	return 0;
}
