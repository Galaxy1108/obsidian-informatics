#include <cstdio>

const int MX = 110;

int a[MX];

namespace solve
{
int m, arr[MX], ans, n;
long long sum = 0, s;

void DFS(int p)
{
	if (p == m + 1)
	{
		ans ^= sum == s;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			sum += a[i];
			DFS(p + 1);
			sum -= a[i];
		}
	}
}

int solve(int m, int s, int n)
{
	solve::m = m;
	solve::s = s;
	solve::n = n;
	ans = 0;
	DFS(1);
	return ans;
}
}

int main()
{
	freopen("give.in", "r", stdin);
	freopen("give.out", "w", stdout);
	int t, m, s, n;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d", &m, &s, &n);
		for (int i = 1; i <= n; scanf("%d", a + i++));
		printf("%d\n", solve::solve(m, s, n));
	}
}
