#include <cstdio>
typedef long long intt;

const int MX = 210;

int P;

namespace solve
{
struct Barrett
{
	int p;
	intt m;
	
	Barrett() = default;
	Barrett(int p): p(p), m(((__int128)1 << 64) / p) {}
	
	int operator() (intt x) const
	{
		int t = x - ((__int128)x * m >> 64) * p;
		return t >= p ? t - p : t;
	}
} mod;

int f[MX][MX * MX][2];

int solve(int n)
{
	mod = Barrett(P);
	const int S = n * (n - 1) >> 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = -(n * (n - 1) >> 1); j < (n * (n - 1) >> 1); j++)
		{
			
		}
	}
	return f[n][0][1];
}
}

int main()
{
	freopen("pairs.in", "r", stdin);
	freopen("pairs.out", "w", stdout);
	int n;
	scanf("%d%d", &n, &P);
	printf("%d", solve::solve(n));
}
