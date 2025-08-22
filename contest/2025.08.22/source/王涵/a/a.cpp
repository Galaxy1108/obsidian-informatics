#include <cstdio>
typedef long long intt;

const int MX = 10000010;
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
		return x - ((__int128)x * m >> 64) * p;
	}
} mod;

int pre[2][MX], suf[2][MX], pp[2][MX], ss[2][MX];

int solve(int n, int m)
{
	mod = Barrett(P);
	pre[0][m] = suf[0][1] = pp[0][m] = ss[0][1] = 1;
	for (int i = 1, p; i <= n; i++)
	{
		p = i & 1;
		for (int j = 1; j <= m; j++)
			pre[p][j] = mod(pre[p][j - 1] + (intt)j * pre[p ^ 1][m] - pp[p ^ 1][j - 1] - (intt)j * suf[p ^ 1][j + 1]),
			pp[p][j] = md(pp[p][j - 1] + pre[p][j]);
		for (int j = m; j; j--)
			suf[p][j] = mod(suf[p][j + 1] + (intt)(m - j + 1) * pre[p ^ 1][m] - (intt)(m - j + 1) * pre[p ^ 1][j - 1] - ss[p ^ 1][j + 1]),
			ss[p][j] = md(ss[p][j + 1] + suf[p][j]);
	}
	return pre[n & 1][m];
}
}

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int n, m;
	scanf("%d%d%d", &n, &m, &P);
	printf("%d", solve::solve(n, m));
}
