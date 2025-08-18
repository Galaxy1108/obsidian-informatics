#include <cstdio>
#include <cstring>
#define min(A, B) (A < B ? A : B)
#define minx(A, B) (A = min(A, B))
#define INF 1e9

const int MX = 110, X = 10, MXX = X + 2;

char ch[MX];

namespace solve
{
int f[MX][MXX][MXX][MXX], pa[MX], pb[MX], pc[MX];

int solve(int n)
{
	for (int i = 1; i <= n; pa[i] = pa[i - 1] + (ch[i] == 'A'), pb[i] = pb[i - 1] + (ch[i] == 'B'), pc[i] = pc[i - 1] + (ch[i] == 'C'), i++);
	memset(f, 0x3f, sizeof(f));
	f[min(n, X)][pa[min(n, X)]][pb[min(n, X)]][pc[min(n, X)]] = 0;
	for (int i = min(n, X); i < n; i++)
		for (int a = 0; a <= X; a++)
			for (int b = 0, c; a + b <= X; b++)
				c = X - a - b,
				minx(f[min(i + a, n)][pa[min(i + a, n)] - pa[i]][pb[min(i + a, n)] - pb[i] + b][pc[min(i + a, n)] - pc[i] + c], f[i][a][b][c] + 1),
				minx(f[min(i + b, n)][pa[min(i + b, n)] - pa[i] + a][pb[min(i + b, n)] - pb[i]][pc[min(i + b, n)] - pc[i] + c], f[i][a][b][c] + 1),
				minx(f[min(i + c, n)][pa[min(i + c, n)] - pa[i] + a][pb[min(i + c, n)] - pb[i] + b][pc[min(i + c, n)] - pc[i]], f[i][a][b][c] + 1);
	int ret = INF;
	for (int a = 0; a <= X; a++)
		for (int b = 0; a + b <= X; b++)
			for (int c = 0; a + b + c <= X; c++)
				minx(ret, f[n][a][b][c] + (bool)a + (bool)b + (bool)c);
	return ret;
}
}

int main()
{
	freopen("worker.in", "r", stdin);
	freopen("worker.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; scanf(" %c", ch + i++));
	printf("%d", solve::solve(n));
}
