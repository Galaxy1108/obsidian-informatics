#include <cstdio>
typedef long long intt;

const int MX = 20010, MXP = 4000, B = 4000, MXB = B + 10;
int P;

namespace solve
{
inline int md(int x)
{
	return x >= P ? x - P : x;
}

inline void add(int& x, int y)
{
	x = md(x + y);
}

struct Barrett
{
	int p;
	intt m;
	
	Barrett() = default;
	Barrett(int p): p(p), m(((__int128)1 << 64) / p) {}
	
	int operator() (intt x)
	{
		int t = x - ((__int128)x * m >> 64) * p;
		return t >= p ? t - p : t;
	}
} mod;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

void exgcd(int a, int b, int& x, int& y)
{
	if (not a)
		x = 0, y = 1;
	else
	{
		exgcd(b % a, a, y, x);
		x -= b / a * y;
	}
}

int inv(int a)
{
	int x, y;
	exgcd(a, P, x, y);
	return x >= 0 ? x : x + P;
}

namespace sieve
{
bool npri[MX];
int pri[MXP], pk[MXP][MXB], pkb[MXP][MXB], inv[MXP], gcd[MXP], tot;

void sieve(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (not npri[i])
			pri[++tot] = i;
		for (int j = 1; j <= tot and i * pri[j] <= n; j++)
		{
			npri[i * pri[j]] = true;
			if (not (i % pri[j]))
				break;
		}
	}
	for (int i = 1; i <= tot; i++)
	{
		pk[i][0] = pkb[i][0] = 1;
		int t = pri[i] - 1, d;
		gcd[i] = 1;
		while ((d = solve::gcd(t, P)) > 1)
			gcd[i] *= d,
			t /= d;
		inv[i] = solve::inv((pri[i] - 1) / gcd[i]);
		for (int j = 1; j <= B; j++)
			pk[i][j] = mod((intt)pk[i][j - 1] * pri[i]);
		for (int j = 1; j <= B; j++)
			pkb[i][j] = mod((intt)pkb[i][j - 1] * pk[i][B]);
	}
}

inline int pow(int i, int k)
{
	return mod((intt)pkb[i][k / B] * pk[i][k % B]);
}
}

namespace g
{
inline int sum(int a, int d, int c)
{
	return ((a << 1) + (c - 1) * d) * c >> 1;
}

int g(int x)
{
	int ret = 1;
	for (int i = 1; i <= sieve::tot and sieve::pri[i] <= x; i++)
	{
		int kk = 0;
		for (int k = 1; (intt)sieve::pk[i][k - 1] * sieve::pri[i] <= x; k++)
			kk += (x + 1) * (x / sieve::pk[i][k]) - (sum(x - sieve::pk[i][k] + 1, -sieve::pk[i][k], x / sieve::pk[i][k]) << 1);
		ret = mod((intt)ret * (mod((intt)(sieve::pow(i, kk + 1) + P - 1) * sieve::inv[i]) / sieve::gcd[i]));
	}
	return ret;
}
}

int solve(int n)
{
	mod = Barrett(P);
	sieve::sieve(n);
	int ret = 0;
	for (int i = 1; i <= n; i++)
		add(ret, g::g(i));
	return ret;
}
}

int main()
{
	freopen("gonna.in", "r", stdin);
	freopen("gonna.out", "w", stdout);
	int n;
	scanf("%d%d", &n, &P);
	printf("%d", solve::solve(n));
}
