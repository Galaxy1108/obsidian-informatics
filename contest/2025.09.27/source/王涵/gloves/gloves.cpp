#include <cstdio>
#include <algorithm>
#define abs(x) (x < 0 ? -(x) : x)

const int MX = 100010, V = 1e9;

int l[MX], r[MX];

namespace solve
{
namespace DP
{
bool check(int n, int m, int k)
{
	auto dis = [](int x, int y) -> int
	{
		return abs(x - y);
	};
	for (int i = 1, j = 1; i <= n; i++)
	{
		for (; j <= m and r[j] < l[i] and dis(r[j], l[i]) > k; j++);
		if (j > m or dis(r[j], l[i]) > k)
			return false;
		else
			j++;
	}
	return true;
}
}

int solve(int n, int m)
{
	if (n > m)
		std::swap(n, m),
		std::swap(l, r);
	std::sort(l + 1, l + n + 1);
	std::sort(r + 1, r + m + 1);
	int l = 0, r = V, mid;
	while (l < r)
	{
		mid = (l + r) >> 1;
		if (DP::check(n, m, mid))
			r = mid;
		else
			l = mid + 1;
	}
	return l;
}
}

int main()
{
	freopen("gloves.in", "r", stdin);
	freopen("gloves.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; scanf("%d", l + i++));
	for (int i = 1; i <= m; scanf("%d", r + i++));
	printf("%d", solve::solve(n, m));
}
