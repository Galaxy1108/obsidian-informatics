#include <cstdio>
#define min(A, B) (A < B ? A : B)
typedef long long intt;

const int V = 1000000, MX = V + 10;

namespace solve
{
namespace sieve
{
int pri[MX], mu[MX], tot;
bool npri[MX];

void sieve(int n)
{
	mu[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (not npri[i])
		{
			pri[++tot] = i;
			mu[i] = -1;
		}
		for (int j = 1; j <= tot and i * pri[j] <= n; j++)
		{
			npri[i * pri[j]] = true;
			if (i % pri[j])
			{
				mu[i * pri[j]] = mu[i] * mu[pri[j]];
			}
			else
			{
				break;
			}
		}
	}
	for (int i = 2; i <= n; mu[i] += mu[i - 1], i++);
}
}

void init(int n)
{
	sieve::sieve(n);
}

intt solve(int n, int m)
{
	using sieve::mu;
	intt ret = 0;
	for (int i = 1, p, q; i <= n and i <= m; i++)
	{
		p = n / (n / i);
		q = m / (m / i);
		ret += (intt)(n / i) * (m / i) * (mu[min(p, q)] - mu[i - 1]);
		i = min(p, q);
	}
	return ret;
}

intt solve(int a, int b, int c, int d, int k)
{
	return solve(b / k, d / k) - solve(b / k, (c - 1) / k) - solve((a - 1) / k, d / k) + solve((a - 1) / k, (c - 1) / k);
}
}

int main()
{
	freopen("gcd.in", "r", stdin);
	freopen("gcd.out", "w", stdout);
	int n, a, b, c, d, k;
	scanf("%d", &n);
	solve::init(V);
	while (n--)
	{
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
		printf("%lld\n", solve::solve(a, b, c, d, k));
	}
}
