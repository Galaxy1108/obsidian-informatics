#include <cstdio>
typedef long long intt;

const int MX = 610, P = 1e9 + 7;

int a[MX];

namespace solve
{
inline void md(int& x)
{
	x -= (x >= P) * P;
}

namespace C
{
int fac[MX], ifa[MX];

int qpow(int a, int p)
{
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
	return ret;
}

void init(int n)
{
	fac[0] = 1;
	for (int i = 1; i <= n; fac[i] = (intt)fac[i - 1] * i % P, i++);
	ifa[n] = qpow(fac[n], P - 2);
	for (int i = n; i; ifa[i - 1] = (intt)ifa[i] * i % P, i--);
}

int C(int n, int m)
{
	return (intt)fac[n] * ifa[m] % P * ifa[n - m] % P;
}
}

int f[MX << 1][MX];
bool fl[MX << 1];

int solve(int n)
{
	C::init(n);
	for (int i = 1; i <= n; fl[a[i++]] = true);
	f[0][0] = 1;
	for (int i = 0, cnt = 0; i < n << 1; i++)
	{
		cnt += fl[i];
		printf("%d:\n", i);
		for (int j = 0; j <= n; j++)
		{
			if (fl[i + 1])
			{
				md(f[i + 1][j] += (intt)(j - cnt) * f[i][j] % P);
			}
			else
			{
				int res = i - cnt + j;
				if (j + res + 1 == n)
				{
					md(f[i + 1][n] += (intt)(res + 2) * C::fac[res] % P * f[i][j] % P);
				}
				else
				{
					md(f[i + 1][j] += f[i][j]);
					for (int x = 0; x <= res; x++)
					{
						md(f[i + 1][j + x + 1] += (intt)(x + 2) * C::C(res, x) % P * C::fac[x] % P * f[i][j] % P);
					}
				}
			}
			printf("%d ", f[i][j]);
		}putchar('\n');
	}
	return (intt)f[n << 1][n] * C::qpow(2, P - 1 - n) % P;
}
}

int main()
{
//	freopen("ruin.in", "r", stdin);
//	freopen("ruin.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; scanf("%d", a + i++));
	printf("%d", solve::solve(n));
}
