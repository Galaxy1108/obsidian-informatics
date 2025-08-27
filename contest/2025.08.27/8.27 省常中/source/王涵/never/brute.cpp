#include <cstdio>

int main()
{
	freopen("never.in", "r", stdin);
	freopen("never.ans", "w", stdout);
	int tt, n, s, t, x, y;
	scanf("%d", &tt);
	while (tt--)
	{
		scanf("%d%d%d%d%d", &n, &s, &t, &x, &y);
		while (n--)
		{
			if (s < t)
				s += y;
			else
				s -= x;
		}
		printf("%d\n", s);
	}
}
