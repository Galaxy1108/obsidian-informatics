#include <cstdio>
#include <cstring>
#define max(A, B) (A < B ? B : A)
#define maxx(A, B) (A = max(A, B))
#define NINF 0x8080808080808080
typedef long long intt;

const int MX = 2010;

int x[MX];

namespace solve
{
int n, m, j[MX];
intt ans;

void DFS(int p = 1)
{
	if (p == m + 1)
	{
		intt a[MX] = {};
		for (int i = 1; i <= m; i++)
		{
			a[j[i]] = x[i] - a[j[i]];
		}
		intt sum = 0;
		for (int i = 1; i <= n; i++)
		{
			sum += a[i];
		}
		if (sum > ans)
			ans = sum;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		j[p] = i;
		DFS(p + 1);
	}
}

intt solve(int n, int m)
{
	ans = 0;
	solve::n = n;
	solve::m = m;
	DFS(1);
	return ans;
}
}

namespace solve1
{
intt f[MX][MX << 1];

intt solve(int n, int m)
{
	memset(f, 0x80, sizeof(f));
	f[0][MX] = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = -n; j <= n; j++)
		{
			maxx(f[i][j + 1 + MX], f[i - 1][j + MX] + x[i]);
			maxx(f[i][j - 1 + MX], f[i - 1][j + MX] - x[i]);
		}
		for (int j = -n; j <= n; j++)
		{
			printf("%20lld ", f[i][j + MX]);
		}putchar('\n');
	}
	intt ret = NINF;
	for (int i = -n; i <= n; i++)
	{
		maxx(ret, f[m][i + MX]);
	}
	return ret;
}
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int t, n, m;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; scanf("%d", x + i++));
		printf("%lld\n", solve::solve(n, m));
	}
}
