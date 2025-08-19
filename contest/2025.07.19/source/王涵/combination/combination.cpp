#include <cstdio>
typedef long long intt;

namespace solve
{
int qpow(int a, int p, int m)
{
	int ret = 1;
	while (p)
	{
		if (p & 1)
		{
			ret = (intt)ret * a % m;
		}
		a = (intt)a * a % m;
		p >>= 1;
	}
	return ret;
}

int solve(int n, int x, int p, int a0)
{
	return (intt)a0 * qpow(x + 1, n, p) % p;
}
}

int main()
{
	freopen("combination.in", "r", stdin);
	freopen("combination.out", "w", stdout);
	int n, x, p, a0;
	scanf("%d%d%d%*d%d", &n, &x, &p, &a0);
	printf("%d", solve::solve(n, x, p, a0));
}
