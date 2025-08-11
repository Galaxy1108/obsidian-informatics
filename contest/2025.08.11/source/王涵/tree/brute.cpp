#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define max(A, B) (A < B ? B : A)
#define maxx(A, B) (A = max(A, B))
typedef long long intt;

const int MX = 5010;

std::vector <int> T[MX];
int w[MX];

namespace solve
{
intt f[MX][MX];
int siz[MX];
double ans[MX];

void solve(int n)
{
	static intt tt[MX];
	for (int u = n; u; u--)
	{
		siz[u] = 1;
		f[u][1] = w[u];
		for (int v : T[u])
		{
			memset(tt + 1, 0, sizeof(intt) * (siz[u] + siz[v]));
			for (int x = 0; x <= siz[v]; x++)
				for (int i = siz[u]; i; i--)
					maxx(tt[i + x], f[u][i] + f[v][x]);
			siz[u] += siz[v];
			memcpy(f[u] + 1, tt + 1, sizeof(intt) * siz[u]);
		}
	}
	for (int i = 1; i <= n; i++)
		for (int x = 1; x <= siz[i]; x++)
			maxx(ans[i], (double)f[i][x] / x);
}
}

int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.ans", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 2, fa; i <= n; scanf("%d", &fa), T[fa].push_back(i), i++);
	for (int i = 1; i <= n; scanf("%d", w + i++));
	solve::solve(n);
	for (int i = 1; i <= n; printf("%.7lf\n", solve::ans[i++]));
}
