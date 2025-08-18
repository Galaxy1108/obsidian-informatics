#include <cstdio>
#define max(A, B) (A < B ? B : A)
#define maxx(A, B) (A = max(A, B))
#define INF 1e9

const int MX = 2010;

int a[2][MX];

namespace solve
{
int pre[MX], pm[MX], mxp[MX], mxs[MX];

int solve(int n)
{
	int ret = pm[0] = -INF;
	for (int i = 1; i <= n; pre[i] = pre[i - 1] + a[1][i], mxp[i] = max(mxp[i - 1], 0) + a[0][i] + a[1][i], i++);
	for (int i = n; i; mxs[i] = max(mxs[i + 1], 0) + a[0][i] + a[1][i], i--);
	for (int i = 1; i <= n; i++)
	{
		pm[i] = max(pm[i - 1], mxp[i] - pre[i]);
		if (i > 2)
			maxx(ret, pre[i - 1] + mxs[i] + pm[i - 2]);
	}
	return ret;
}
}

int main()
{
	freopen("base.in", "r", stdin);
	freopen("base.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int x = 0; x < 2; x++)
		for (int i = 1; i <= n; scanf("%d", a[x] + i++));
	printf("%d", solve::solve(n));
}
