#include <cstdio>
#include <cstring>
#define max(A, B) (A < B ? B : A)
#define maxx(A, B) (A = max(A, B))
#define INF 1e8

const int MX = 110, MXK = 15;

int a[MX][2];

namespace solve
{
int f[MX][MXK][5];

int solve(int n, int m, int k)
{
	if (m == 1)
		for (int i = 1; i <= n; a[i++][1] = -INF);
	memset(f, 0xc0, sizeof(f));
	f[0][0][0] = 0;
	for (int i = 1; i <= n + 1; i++)
		for (int x = 0; x <= k; x++)
			{
				maxx(f[i][x + 1][4], f[i - 1][x][0] + a[i][0] + a[i][1]);
				for (int s = 0; s < 4; s++)
					for (int t = 0; t < 4; t++)
						maxx(f[i][x + __builtin_popcount(t & ~s)][t], f[i - 1][x][s] + (t & 1) * a[i][0] + (t >> 1) * a[i][1]);
				maxx(f[i][x][0], f[i - 1][x][4]);
				maxx(f[i][x][4], f[i - 1][x][4] + a[i][0] + a[i][1]);
			}
	int ret = 0;
	for (int x = 0; x <= k; x++)
		maxx(ret, f[n + 1][x][0]);
	return ret;
}
}

int main()
{
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		for (int x = 0; x < m; x++)
			scanf("%d", a[i] + x);
	printf("%d", solve::solve(n, m, k));
}
