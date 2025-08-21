#include <cstdio>
#include <algorithm>
#define abs(x) (x < 0 ? -(x) : x)

const int MX = 55;

std::pair <int, int> a[MX], b[MX];

int main()
{
	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1, x; i <= n; scanf("%d", &x), b[i] = a[i] = { x, i }, i++);
	if (n > 8)
	{
		std::sort(a + 1, a + n + 1);
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int p = std::lower_bound(a + 1, a + n + 1, b[i]) - a;
			ans += abs(p - i);
		}
		printf("%d", ans);
	}
	else
	{
		int x[MX] = {}, y[MX] = {}, ans = 1e9;
		for (int i = 1; i <= n; x[i] = i, i++);
		do {
			int ret = 0;
			for (int i = 1; i <= n; i++)
				y[x[i]] = a[i].first,
				ret += abs(x[i] - i);
			bool fl = true;
			for (int i = 1; i <= n; i++)
				if (y[i] < y[i - 1])
					fl = false;
			if (fl)
			{
				ans = std::min(ans, ret);
			}
		} while (std::next_permutation(x + 1, x + n + 1));
		printf("%d", ans);
	}
}
