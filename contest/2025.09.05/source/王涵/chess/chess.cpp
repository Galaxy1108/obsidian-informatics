#include <cstdio>
typedef long long intt;

const int MX = 110, P = 9999973;

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

int f[MX][MX][MX];

int solve(int n, int m)
{
	f[0][m][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= m; j++)
			for (int k = 0; j + k <= m; k++)
			{
				add(f[i][j][k], f[i - 1][j][k]);
				if (j)
					add(f[i][j - 1][k + 1], (intt)j * f[i - 1][j][k] % P);
				if (k)
					add(f[i][j][k - 1], (intt)k * f[i - 1][j][k] % P);
				if (j > 1)
					add(f[i][j - 2][k + 2], ((intt)j * (j - 1) >> 1) * f[i - 1][j][k] % P);
				if (j and k)
					add(f[i][j - 1][k], (intt)j * k * f[i - 1][j][k] % P);
				if (k > 1)
					add(f[i][j][k - 2], ((intt)k * (k - 1) >> 1) * f[i - 1][j][k] % P);
			}
	int ret = 0;
	for (int i = 0; i <= m; i++)
		for (int j = 0; i + j <= m; j++)
			add(ret, f[n][i][j]);
	return ret;
}
}

int main()
{
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%d", solve::solve(n, m));
}
