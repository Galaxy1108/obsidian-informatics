#include <cstdio>
#define min(A, B) (A < B ? A : B)
typedef long long intt;

const int MX = 110;

namespace solve
{
int P;

int qpow(int a, int p)
{
	static int mem[MX * MX];
	if (a == 2 and mem[p]) return mem[p];
	int ret = 1;
	while (p)
	{
		if (p & 1)
		{
			ret = (intt)ret * a % P;
		}
		a = (intt)a * a % P;
		p >>= 1;
	}
	if (a == 2)
		mem[p] = ret;
	return ret;
}

namespace C
{
int fac[MX], ifa[MX];

void init(int n)
{
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		fac[i] = (intt)fac[i - 1] * i % P;
	}
	ifa[n] = qpow(fac[n], P - 2);
	for (int i = n; i; i--)
	{
		ifa[i - 1] = (intt)ifa[i] * i % P;
	}
}

int C(int n, int m)
{
	return (intt)fac[n] * ifa[m] % P * ifa[n - m] % P;
}
}

int res(int n, int m)
{
	int ret = 0;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			(ret += (intt)((i + j) & 1 ^ 1 ? P - 1 : 1) * C::C(n, i) % P * C::C(m, j) % P * qpow(2, (n - i) * (m - j)) % P) %= P;
		}
	}
	for (int j = 0; j <= m; j++)
	{
		(ret += (intt)(j & 1 ? P - 1 : 1) * C::C(m, j) % P * qpow(2, n * (m - j)) % P) %= P;
	}
	for (int i = 0; i <= n; i++)
	{
		(ret += (intt)(i & 1 ? P - 1 : 1) * C::C(n, i) % P * qpow(2, (n - i) * m) % P) %= P;
	}
	return ret;
}

int mm[MX][MX];

int solve(int n, int m, int k, int d)
{
	P = d;
	C::init(100);
	int ret = 0;
	for (int st = 0; st < 1 << (n * m); st++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				mm[i][j] = (bool)(st & (1 << (n * i + j))) + 1;
			}
		}
		int pd = 1;
		for (int i = 0, mn; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				mn = 4;
				for (int x = 0; x < n; x++)
				{
					mn = min(mn, mm[x][j]);
				}
				for (int x = 0; x < m; x++)
				{
					mn = min(mn, mm[i][x]);
				}
				(pd *= mn) % P;
			}
		}
		(ret += pd) %= P;
	}
	return ret;
}
}

int main()
{
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	int n, m, k, d;
	scanf("%d%d%d%d", &n, &m, &k, &d);
	printf("%d", solve::solve(n, m, k, d));
}
