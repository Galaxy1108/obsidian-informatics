#include <cstdio>
#include <vector>
#include <algorithm>
#define lowbit(x) (x & -x)

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

const int MX = 1000010, V = 100000, MXV = V + 10, P = 998244353;

int a[MX], b[MX];

namespace solve
{
struct qry
{
	int r, x;
} qr[MX];

namespace offline
{
inline int md(int x)
{
	return x >= P ? x - P : x;
}

inline void add(int& x, int y)
{
	x = md(x + y);
}

namespace BIT
{
int tree[MXV];

void add(int p, int x)
{
	for (int i = p; i <= V; i += lowbit(i))
		offline::add(tree[i], x);
}

int query(int p)
{
	int ret = 0;
	for (int i = p; i; i -= lowbit(i))
		offline::add(ret, tree[i]);
	return ret;
}

int query(int l, int r)
{
	return md(query(r) + P - query(l - 1));
}
}

int lst[MXV], tot[MX];

bool cmp(qry& a, qry& b)
{
	return a.r > b.r;
}

int solve(int n, int tq)
{
	std::sort(qr + 1, qr + tq + 1, cmp);
	int ret = 0;
	for (int i = n, j = 1; i; i--)
	{
		tot[i] = md(BIT::query(V) + 1);
		BIT::add(a[i], md(BIT::query(V) + P - tot[lst[a[i]]] + 1));
		lst[a[i]] = i;
		for (; j <= tq and qr[j].r == i; add(ret, BIT::query(qr[j].x)), j++);
	}
	return ret;
}
}

std::vector <int> pos[MXV];

int solve(int n, int m)
{
	int tq = 0;
	for (int i = 1; i <= n; i++)
		pos[a[i]].push_back(i);
	for (int i = 1, r = 1; i <= m and r <= n; i++)
	{
		qr[++tq] = { r, b[i] - 1 };
		r = *std::lower_bound(pos[b[i]].begin(), pos[b[i]].end(), r) + 1;
	}
	return (offline::solve(n, tq) + m) % P;
}
}

int main()
{
	freopen("seq.in", "r", stdin);
	freopen("seq.out", "w", stdout);
	int n = read(), m;
	for (int i = 1; i <= n; a[i++] = read());
	m = read();
	for (int i = 1; i <= m; b[i++] = read());
	printf("%d", solve::solve(n, m));
}
