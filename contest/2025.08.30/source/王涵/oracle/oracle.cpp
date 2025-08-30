#include <cstdio>
#include <cstring>
typedef long long intt;

const int MX = 110, MXM = MX * MX, P = 998244353;

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

int qpow(int a, int p)
{
	int ret = 1;
	while (p)
	{
		if (p & 1)
			ret = (intt)ret * a % P;
		a = (intt)a * a % P;
		p >>= 1;
	}
	return ret;
}

namespace C
{
int fac[MX], ifa[MX];

void init(int n)
{
	fac[0] = 1;
	for (int i = 1; i <= n; fac[i] = (intt)fac[i - 1] * i % P, i++);
	ifa[n] = qpow(fac[n], P - 2);
	for (int i = n; i; ifa[i - 1] = (intt)ifa[i] * i % P, i--);
}

inline int C(int n, int m)
{
	return (intt)fac[n] * ifa[m] % P * ifa[n - m] % P;
}
}

int f[2][MX][MXM];

int solve(int n, int m)
{
	C::init(n);
	f[0][0][0] = 1;
	for (int i = 1, p; i <= n; i++)
	{
		p = i & 1;
		memset(f[p], 0, sizeof(f[p]));
		for (int j = 0; j < i; j++)
			for (int k = 0; k <= m; k++)
				for (int x = 0; x <= j; x++)
					for (int y = 0; x + y <= i and k + x + y <= m; y++)
						add(f[p][j - x + (not x and not y)][k + x + y], (intt)C::C(j, x) * C::C(i - j, y) % P * f[p ^ 1][j][k] % P);
	}
	return md(f[n & 1 ^ 1][0][m] + f[n & 1][0][m]);
}
}

int main()
{
	freopen("oracle.in","r",stdin);
	freopen("oracle.out","w",stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%d", solve::solve(n, m));
}
