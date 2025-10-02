#include <cstdio>

const int MX = 1000010;

int a[MX];

namespace solve
{
int solve()
{
	if (a[3] - a[1] >= a[2])
		return 1;
	else
		return 3;
}
}

int main()
{
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
	int t, n;
	scanf("%d%d", &t, &n);
	for (int i = 1; i <= n; scanf("%d", a + i++));
	printf("%d\n", solve::solve());
	while (--t)
	{
		int k, x, y;
		scanf("%d", &k);
		while (k--)
			scanf("%d%d", &x, &y),
			a[x] = y;
		printf("%d\n", solve::solve());
	}
}
