#include <cstdio>

const int MX = 110;

int a[MX];

int main()
{
	freopen("truth.in", "r", stdin);
	freopen("truth.ans", "w", stdout);
	int n, k;
	scanf("%d%d%*d", &n, &k);
	for (int i = 1; i <= n; scanf("%d", a + i++));
	int ans = 1e9;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			int vis[12] = {};
			for (int p = i; p <= j; p++)
			{
				vis[a[p]] = true;
			}
			bool fl = true;
			for (int i = 1; i <= k; i++)
				if (not vis[i])
					fl = false;
			if (fl)
				if (ans > j - i + 1)
					ans = j - i + 1;
		}
	}
	printf("%d", ans < 1e9 ? ans : -1);
}
