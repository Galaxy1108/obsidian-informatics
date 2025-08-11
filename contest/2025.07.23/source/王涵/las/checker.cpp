#include <cstdio>

const int MX = 1000010;

int c[MX], p[MX];
bool vis[MX];

int main()
{
	freopen("las.in", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", c + i);
		c[i] <<= 1;
	}
	freopen("las.out", "r", stdin);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", p + i);
		if (vis[p[i]])
			c[p[i]] >>= 1;
		vis[p[i]] = true;
	}
	for (int i = 1; i <= n; i++)
	{
		if (p[i] == i)
		{
			if (c[i % n + 1] >> vis[i % n + 1] > c[i])
			{
				printf("WA\n");
				return 0;
			}
		}
		else
		{
			if (c[i] >> vis[i] > c[i % n + 1])
			{
				printf("WA\n");
				return 0;
			}
		}
	}
	printf("AC\n");
}
