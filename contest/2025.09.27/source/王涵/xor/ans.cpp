#include <cstdio>

const int MX = 100010;

int a[MX];

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.ans", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; scanf("%d", a + i++));
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
		{
			int mx = 0, xx = 0;
			for (int p = i; p <= j; xx ^= a[p++])
				if (a[p] > mx)
					mx = a[p];
			if (xx <= mx)
				ans++;
		}
	printf("%d", ans);
}
