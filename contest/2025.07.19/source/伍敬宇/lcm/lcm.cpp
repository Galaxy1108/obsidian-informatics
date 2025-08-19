#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int SIZE = 1<<21,MAXN = 2e6 + 12;
const long long mod = 998244353;
const long long phi = (mod-1)*1/2*6/7*16/17;
char buf[SIZE+1],*iS,*iT;
int exc;
long long rem;
inline char mget()
{
	if (iS==iT) iS = buf,iT = buf + fread(buf,1,SIZE,stdin),*iT = 'E';
	return *(iS++);
}
inline int read()
{
	int x = 0;
	char ch = mget();
	while (ch<'0'||ch>'9') ch = mget();
	while ('0'<=ch&&ch<='9') x = x*10 + ch - '0',ch = mget();
	return x;
}
int p[MAXN],b[MAXN],cnt;
struct Value{
	int a[202];
};
void init()
{
	b[1] = 1;
	int n = 1.1e6;
	for (int i=2;i<=n;i++)
	{
		if (b[i]==0) p[++cnt] = i;
		for (int j=1;j<=cnt&&p[j]*i<=n;j++)
		{
			b[i*p[j]] = 1;
			if (i%p[j] == 0) break;
		}
	}
}
int flag;
long long mpw(long long x,long long k,long long mod)
{
	long long res = 1;
	while (k)
	{
		if (k&1) res = res*x%mod;
		k>>=1;
		x = x*x%mod;
	}
	return res;
}
int n;
void work()
{
	n = read();
	char ch = mget();
	rem = 0;
	exc = 0;
	while ('0'<=ch&&ch<='9')
	{
		rem = rem*10 + ch - '0';
		if (rem>=phi)
		{
			rem -= phi;
			exc = 1;
		}
		ch = mget();
	}
	long long sum = 1;
	int t = 0;
	for (int i=1;p[i]<=n;i++)
	{
		long long pw = p[i];
		for (int a=1;pw<=n;a++,pw=pw*p[i])
		{
			t++;
			int x = n - (n/(pw*p[i])),y = n - (n/pw);
			long long ans;
			if (exc) ans = (mpw(x,rem+phi,mod-1) - mpw(y,rem+phi,mod-1) + mod - 1)%(mod-1);
			else ans = (mpw(x,rem,mod-1) - mpw(y,rem,mod-1) + mod - 1)%(mod-1);
			sum = sum*mpw(pw,ans,mod)%mod;
		}
	}
	printf("%lld\n",sum);
}
int main()
{
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
	init();
	int t = read();
	while (t--)
	{
		work();
	}
	return 0;
}
