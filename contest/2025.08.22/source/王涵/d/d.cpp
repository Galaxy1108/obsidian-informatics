#include <cstdio>

const int MX = 100010;

int x[MX];

struct anst
{
	int a, b, c;
	
	bool operator< (anst oth)
	{
		return c == oth.c ? a == oth.a ? b < oth.b : a < oth.a : c < oth.c;
	}
};

namespace solve
{
anst query(int l, int r)
{
	for (int c = 1; c <= 10; c++)
	{
		for (int a = 0; a <= 10; a++)
			for (int b = 0; b <= 10; b++)
			{
				bool fl = true;
				for (int x = l; x <= r; x++)
				{
					if (a * (x - l) + b < 0 or (a * (x - l) + b) / c != ::x[x])
					{
						fl = false;
						break;
					}
				}
				if (fl)
					return { a, b, c };
			}
	}
	return { -1, -1, -1 };
}
}

namespace solve1
{
anst query(int l, int r)
{
	return { l < r ? x[l + 1] - x[l] : 0, x[l], 1 };
}
}

int main()
{
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
	int t, n, q, l, r, tn = 0;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		tn += n;
		for (int i = 1; i <= n; i++)
			scanf("%d", x + i);
		scanf("%d", &q);
		anst ans;
		while (q--)
		{
			scanf("%d%d", &l, &r);
			ans = tn <= 20 ? solve::query(l, r) : solve1::query(l, r);
			printf("%d %d %d\n", ans.a, ans.b, ans.c);
		}
	}
}
