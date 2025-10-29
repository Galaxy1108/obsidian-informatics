#include <cstdio>
#include <cstring>
#define max(A, B) (A < B ? B : A)
typedef long long intt;

const int MX = 510, P = 998244353;

namespace solve
{
inline void add(int& x, int y)
{
	(x += y) >= P and (x -= P);
}

inline void add(int& x, intt y)
{
	x = (x + y) % P;
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

namespace pc
{
int fac[MX], ifa[MX], pw[MX][MX];

void init(int n, int x)
{
	fac[0] = 1;
	for (int i = 1; i <= n; fac[i] = (intt)fac[i - 1] * i % P, i++);
	ifa[n] = qpow(fac[n], P - 2);
	for (int i = n; i; ifa[i - 1] = (intt)ifa[i] * i % P, i--);
	for (int i = 0; i <= x; i++)
		for (int j = pw[i][0] = 1; j <= n; j++)
			pw[i][j] = (intt)pw[i][j - 1] * i % P;
}

inline int C(int n, int m)
{
	return (intt)fac[n] * ifa[m] % P * ifa[n - m] % P;
}
}

int f[2][MX][MX];

int solve(int n, int x)
{
	pc::init(n, x);
	int ret = 0;
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i - 1; j++)
			f[1][i][j] = (intt)(pc::pw[j][i] + P - pc::pw[j - 1][i]) * pc::C(n, i) % P;
	for (int i = 0; i <= x; i++)
		add(ret, f[1][n][i]);
	for (int i = 2, p; i <= x - n + 2; i++)
	{
		p = i & 1;
		memset(f[p], 0, sizeof(f[p]));
		for (int j = 0; j <= n; j++)
			for (int k = 0; k <= x; k++)
				if (f[p ^ 1][j][k])
					for (int ex = 0; j + ex <= n and k + j + ex - 1 <= x; ex++)
						add(f[p][j + ex][k + j + ex - 1], (intt)pc::pw[j + ex - 1][ex] * pc::C(n - j, ex) % P * f[p ^ 1][j][k]);
		for (int j = 0; j <= x; j++)
			add(ret, f[p][n][j]);
	}
	return ret;
}
}

int main()
{
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	int n, x;
	scanf("%d%d", &n, &x);
	printf("%d", solve::solve(n, x));
}
