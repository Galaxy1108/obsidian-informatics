#include <cstdio>
#include <algorithm>
#define min(A, B) (A < B ? A : B)
#define minx(A, B) (A = min(A, B))
#define INF 1e18
typedef long long intt;

const int MX = 200010;

int a[MX], l[MX], r[MX];

namespace solve
{
struct seg
{
	intt l, r;
} s[MX << 1];

int init(int n)
{
	std::sort(s + 1, s + n + 1, [](seg& a, seg& b) -> bool
	{
		return a.l < b.l;
	});
	static seg stk[MX << 1];
	int top = 0;
	for (int i = 1; i <= n; i++)
	{
		for (; top and stk[top].r > s[i].r; top--);
		stk[++top] = s[i];
	}
	memcpy(s + 1, stk + 1, sizeof(seg) * top);
	return top;
}

intt solve(int n, int m)
{
	std::sort(a + 1, a + n + 1);
	n = std::unique(a + 1, a + n + 1) - a - 1;
	for (int i = 1; i <= m; s[i] = { l[i], r[i] }, i++);
	for (int i = 1; i <= n; s[m + i] = { a[i], a[i] }, i++);
	int tot = init(n + m);
	intt f = 0, g = 0, rr = s[2].r, mn = INF, mn2 = INF;
	for (int i = 1, j = 1; i <= tot; i++)
	{
		if (j <= n and s[i].l <= a[j] and a[j] <= s[i].r)
		{
			if (j > 1)
				f = min(min(s[i - 1].l - a[j - 1] + g, a[j] - rr + f), g + mn + a[j] - a[j - 1]),
				g = min(min(s[i - 1].l - a[j - 1] + g, (a[j] - rr << 1) + f), g + mn2 + (a[j] << 1) - a[j - 1]);
			else
				f = a[j] - s[1].r,
				g = f << 1;
			rr = s[i + 1].r;
			mn = mn2 = INF;
			j++;
			if (j <= n and s[i].l <= a[j] and a[j] <= s[i].r)
			{
				for (; j <= n and s[i].l <= a[j] and a[j] <= s[i].r; j++);
				g = f;
			}
		}
		else
			minx(mn, s[i].l - s[i + 1].r),
			minx(mn2, s[i].l - (s[i + 1].r << 1));
	}
	if (a[n] < s[tot].l)
		return g + s[tot].l - a[n];
	else
		return f;
}
}

int main()
{
	freopen("points.in", "r", stdin);
	freopen("points.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; scanf("%d", a + i++));
	for (int i = 1; i <= m; scanf("%d%d", l + i, r + i), i++);
	printf("%lld", solve::solve(n, m));
}
