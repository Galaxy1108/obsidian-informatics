#include <cstdio>
#include <vector>
#include <algorithm>

const int MX = 500010;

std::vector <int> T[MX];
int w[MX];

namespace solve
{
double f[MX];
int cnt[MX];

bool cmp(int a, int b)
{
	return f[a] > f[b];
}

void solve(int n)
{
	for (int u = n; u; u--)
	{
		std::sort(T[u].begin(), T[u].end(), cmp);
		f[u] = w[u];
		cnt[u] = 1;
		for (int v : T[u])
			if (f[v] < f[u])
				break;
			else
				f[u] = f[u] * cnt[u] / (cnt[u] + cnt[v]) + f[v] * cnt[v] / (cnt[u] + cnt[v]),
				cnt[u] += cnt[v];
	}
}
}

int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 2, fa; i <= n; scanf("%d", &fa), T[fa].push_back(i), i++);
	for (int i = 1; i <= n; scanf("%d", w + i++));
	solve::solve(n);
	for (int i = 1; i <= n; printf("%.7lf\n", solve::f[i++]));
}
