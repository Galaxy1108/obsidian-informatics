#include <cstdio>
#include <cstring>

const int MX = 3010;
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

int f[2][MX][2], n;

#define trans(f, to, x, t1, out, in)\
	add(to[(x) - not (out) + not (in)][(t1) or (x) == n - 1 and (out)], f[x][t1])

int solve(int n, int m)
{
	solve::n = n;
	for (int i = 0; i <= n; f[0][i][i == n] = 1, i++);
	for (int i = 1, p; i <= m; i++)
	{
		p = i & 1;
		memset(f[p], 0, sizeof(f[p]));
		for (int j = 1; j < n; j++)
		{
			trans(f[p ^ 1], f[p], j, 0, 0, 0);
			trans(f[p ^ 1], f[p], j, 0, 0, 1);
			trans(f[p ^ 1], f[p], j, 0, 1, 0);
			trans(f[p ^ 1], f[p], j, 0, 1, 1);
			trans(f[p ^ 1], f[p], j, 1, 0, 0);
			trans(f[p ^ 1], f[p], j, 1, 0, 1);
			trans(f[p ^ 1], f[p], j, 1, 1, 0);
			trans(f[p ^ 1], f[p], j, 1, 1, 1);
		}
		for (int s = 0; s < 4; s++)
			trans(f[p ^ 1], f[p], 0, s & 1, 1, s >> 1);
		trans(f[p ^ 1], f[p], n, 1, 0, 0);
		trans(f[p ^ 1], f[p], n, 1, 0, 1);
	}
	int ret = 0;
	for (int i = 0; i <= n; i++)
		add(ret, f[m & 1][i][1]);
	return ret;
}
}

int main()
{
	freopen("easyhard.in", "r", stdin);
	freopen("easyhard.out", "w", stdout);
	int n, m;
	scanf("%d%d%d", &n, &m, &P);
	printf("%d", solve::solve(n, m));
}
