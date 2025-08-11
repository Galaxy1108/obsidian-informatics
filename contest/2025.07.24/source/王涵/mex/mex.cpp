#include <cstdio>
typedef long long intt;

const int MX = 5010, P = 998244353;

int s[MX];

namespace solve
{
int f[MX][MX];

inline void md(int& x)
{
	x -= (x >= P) * P;
}

int solve(int n, int m)
{
	f[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= n and j <= m + 1; j++)
		{
			if (s[i])
			{
				md(f[i][j + 1] += f[i - 1][j]);
			}
			else
			{
				md(f[i][j + 1] += (intt)(m - j) * f[i - 1][j] % P);
				md(f[i][j] += (intt)j * f[i - 1][j] % P);
			}
		}
	}
	int ret = 0;
	for (int i = 0; i <= n and i <= m + 1; i++)
		md(ret += f[n][i]);
	return ret;
}
}

int main()
{
	freopen("mex.in", "r", stdin);
	freopen("mex.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; scanf("%d", s + i++));
	printf("%d", solve::solve(n, m));
}
