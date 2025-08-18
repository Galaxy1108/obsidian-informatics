#include <cstdio>
#include <cstring>
#define min(A, B) (A < B ? A : B)
#define minx(A, B) (A = min(A, B))
#define INF 1e9

const int MX = 10010, MXM = 110;

int a[MX];

namespace solve
{
int f[MX][MXM];

int solve(int n, int m)
{
	memset(f, 0x3f, sizeof(f));
	for (int i = 1; i < m; f[0][i] = a[i], i++);
	for (int i = 0; i < n; i++)
	{
		for (int x = 1; x < m and i + x <= n; x++)
			for (int z = 1; x + z <= m and i + x + z <= n; z++)
				minx(f[i + x][z], f[i][x] + a[i + x + z]);
	}
	int ret = INF;
	for (int i = n - m + 1; i <= n; i++)
		for (int x = 1; i + x <= n; x++)
			minx(ret, f[i][x]);
	return ret;
}
}

int main()
{
	freopen("brush.in", "r", stdin);
	freopen("brush.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; scanf("%d", a + i++));
	printf("%d", solve::solve(n, m));
}
