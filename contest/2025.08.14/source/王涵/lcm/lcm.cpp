#include <cstdio>

int P;

namespace solve
{
long long gcd(long long a, long long b)
{
	return b ? gcd(b, a % b) : a;
}

int solve(int n)
{
	long long e = 1, f = 0, lcm = 1, ret = 0;
	for (int i = 1; i <= n; i++)
	{
		long long t = f;
		f += e;
		e += t * 2;
		lcm = lcm * f / gcd(lcm, f);
		(ret += ((long long)i * lcm) % P) %= P;
	}
	return ret;
}
}

int main()
{
	freopen("lcm.in", "r", stdin);
	freopen("lcm.out", "w", stdout);
	int t, n;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &P);
		printf("%d\n", solve::solve(n));
	}
}
