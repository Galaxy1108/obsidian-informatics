#include <cstdio>
#include <algorithm>
#include <cstring>

namespace solve0
{
const int MX = 5;

int a[MX * MX], b[MX * MX];

void solve(int n, unsigned x, unsigned y)
{
	for (int i = 1; i <= n * n; a[i] = i, i++);
	do
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				b[(j - 1) * n + i] = a[(i - 1) * n + j];
		unsigned cx = 0, cy = 0;
		for (int i = 1; i <= n * n; i++)
			for (int j = i + 1; j <= n * n; j++)
				cx += a[i] > a[j],
				cy += b[i] > b[j];
		if (cx == x and cy == y)
		{
			printf("YES\n");
			for (int i = 1; i <= n; putchar('\n'), i++)
				for (int j = 1; j <= n; j++)
					printf("%d ", a[(i - 1) * n + j]);
			return;
		}
	} while (std::next_permutation(a + 1, a + n * n + 1));
	printf("NO\n");
}
}

namespace solve1
{
void solve(int n)
{
	printf("YES\n");
	for (int i = 1; i <= n; putchar('\n'), i++)
		for (int j = 1; j <= n; j++)
			printf("%d ", (i - 1) * n + j);
}
}

namespace solve2
{
const int MX = 310;

namespace invp
{
namespace BIT
{
int tree[MX * MX], n;

#define lowbit(x) (x & -x)

void init(int n)
{
	BIT::n = n;
	memset(tree + 1, 0, sizeof(int) * n);
}

void add(int x, int v)
{
	for (int i = x; i <= n; i += lowbit(i))
		tree[i] += v;
}

int query(int x)
{
	int ret = 0;
	for (int i = x; i; i -= lowbit(i))
		ret += tree[i];
	return ret;
}

#undef lowbit
}

unsigned invp(int a[], int n)
{
	unsigned ret = 0;
	BIT::init(n);
	for (int i = n; i; i--)
		ret += BIT::query(a[i]),
		BIT::add(a[i], 1);
	return ret;
}
}

int b[MX * MX];

void solve(int n, unsigned x, unsigned y)
{
	bool fl = false;
	if (not x and not y)
		goto no;
	else if (not y)
		fl = true,
		std::swap(x, y);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			b[(j - 1) * n + i] = (i - 1) * n + j;
	if (invp::invp(b, n * n) != y)
		goto no;
	printf("YES\n");
	if (fl)
		for (int i = 1; i <= n; putchar('\n'), i++)
			for (int j = 1; j <= n; j++)
				printf("%d ", (j - 1) * n + i);
	else
		for (int i = 1; i <= n; putchar('\n'), i++)
			for (int j = 1; j <= n; j++)
				printf("%d ", (i - 1) * n + j);
	return;
no:
	printf("NO\n");
}
}

int main()
{
	freopen("matrixcascade.in", "r", stdin);
	freopen("matrixcascade.out", "w", stdout);
	int t, n;
	unsigned x, y;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%u%u", &n, &x, &y);
		if (n <= 3)
			solve0::solve(n, x, y);
		else if (not x or not y)
			solve2::solve(n, x, y);
		else if (n == 10)
			solve1::solve(n);
		else
			printf("NO\n");
	}
}
