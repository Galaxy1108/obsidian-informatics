#include <cstdio>

using namespace std;
typedef long long ll;
ll gcd(ll x, ll y)
{
	return x ? gcd(y % x, x) : y;
}

int main()
{
	freopen("never.in", "r", stdin);
	freopen("never.out", "w", stdout);
	int T, i;
	ll n, s, t, x, y, g, lp, stp, a;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lld%lld%lld%lld%lld", &n, &s, &t, &x, &y);
		t -= s;
		g = gcd(x, y);
		if(t < 0)
		{
			if((-t) / x + 1 >= n)
			{
				printf("%lld\n", s - n * x);
				continue;
			}
			n -= (-t) / x + 1;
			stp = y / g + x / g;
			n %= stp;
			a = -x * ((-t) / x + 1);
			for(i = 1; i <= n; i++)
				if(a >= t)
					a -= x;
				else
					a += y;
			printf("%lld\n", a + s);
		}
		else
		{
			if((t + y - 1) / y >= n)
			{
				printf("%lld\n", s + n * y);
				continue;
			}
			n -= (t + y - 1) / y;
			stp = y / g + x / g;
			n %= stp;
			a = y * ((t + y - 1) / y);
			for(i = 1; i <= n; i++)
				if(a >= t)
					a -= x;
				else
					a += y;
			printf("%lld\n", a + s);
		}
	}
	return 0;
}