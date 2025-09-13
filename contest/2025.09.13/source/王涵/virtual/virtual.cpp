#include <cstdio>
#define swap(A, B) (A ^= B ^= A ^= B)

int read()
{
	char c = getchar();
	while (c < '0' or '9' < c)
		c = getchar();
	int ret = 0;
	while ('0' <= c and c <= '9')
		ret = (ret << 3) + (ret << 1) + c - '0',
		c = getchar();
	return ret;
}

const int MX = 2000010;

char s[MX];

namespace solve
{
namespace DSU
{
int fa[MX], siz[MX];

void init(int n)
{
	for (int i = 1; i <= n; fa[i] = i, siz[i] = 1, i++);
}

int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

bool in(int u, int v)
{
	return find(u) == find(v);
}

void unite(int u, int v)
{
	if (not in(u, v))
	{
		if (siz[find(u)] > siz[find(v)])
			swap(u, v);
		siz[find(v)] += siz[find(u)];
		fa[find(u)] = find(v);
	}
}
}

int pre[MX], nxt[MX];

int lower(int l, int r, int p, int x)
{
	int mid;
	while (l < r)
	{
		mid = (l + r) >> 1;
		if (pre[p] - pre[mid - 1] <= x)
			r = mid;
		else
			l = mid + 1;
	}
	return l;
}

int upper(int l, int r, int p, int x)
{
	int mid;
	while (l < r)
	{
		mid = (l + r) >> 1;
		if (x < pre[p] - pre[mid - 1])
			l = mid + 1;
		else
			r = mid;
	}
	return l;
}

void init(int n, int lk, int rk)
{
	DSU::init(n);
	for (int i = 1; i <= n; nxt[i] = i + 1, i++);
	for (int i = 1, l = 1, r = 1; i <= n; i++)
	{
		pre[i] = pre[i - 1] + (s[i] == 'a');
		for (; pre[i] - pre[l - 1] > rk; l++);
		for (; pre[i] - pre[r - 1] >= lk; r++);
		for (int j = l, t; j < r; j = t)
			t = nxt[j],
			nxt[j] = r,
			DSU::unite(i, j);
	}
}

bool query(int x, int y)
{
	return DSU::in(x, y);
}
}

int main()
{
	freopen("virtual.in", "r", stdin);
	freopen("virtual.out", "w", stdout);
	int n = read(), l = read(), r = read();
	char c = getchar();
	while (c < 'a' or 'b' < c)
		c = getchar();
	for (int i = 1; i <= n; s[i++] = c, c = getchar());
	int q = read(), x, y;
	solve::init(n, l, r);
	while (q--)
	{
		x = read(); y = read();
		if (solve::query(x, y))
			putchar('Y'),
			putchar('e'),
			putchar('s');
		else
			putchar('N'),
			putchar('o');
		putchar('\n');
	}
}
