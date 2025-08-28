#include <cstdio>
#include <vector>
#include <algorithm>
using std::min;
using std::max;

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

void write(int x)
{
	if (x >= 10)
		write(x / 10);
	putchar(x % 10 + '0');
}

const int MX = 500010;

int a[MX];

namespace solve
{
int ans[MX];

namespace sgt
{
std::vector <int> nd[MX << 2];
int n;

void add(int l, int r, int id, int p = 1, int cl = 1, int cr = n)
{
	if (l <= cl and cr <= r)
		nd[p].push_back(id);
	else
	{
		int mid = (cl + cr) >> 1;
		if (l <= mid)
			add(l, r, id, p << 1, cl, mid);
		if (mid < r)
			add(l, r, id, p << 1 | 1, mid + 1, cr);
	}
}

namespace solve
{
namespace sgt
{
int mx[MX << 2], mn[MX << 2], mk[MX << 2], n;

inline void push_add(int p, int x)
{
	mx[p] += x;
	mn[p] += x;
	mk[p] += x;
}

inline void push_down(int p)
{
	if (mk[p])
	{
		push_add(p << 1, mk[p]);
		push_add(p << 1 | 1, mk[p]);
		mk[p] = 0;
	}
}

inline void push_up(int p)
{
	mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
	mn[p] = min(mn[p << 1], mn[p << 1 | 1]);
}

void build(const std::vector <int>& vec, int p = 1, int cl = 0, int cr = n)
{
	mk[p] = 0;
	if (cl == cr)
		mx[p] = mn[p] = ans[vec[cl]];
	else
	{
		int mid = (cl + cr) >> 1;
		build(vec, p << 1, cl, mid);
		build(vec, p << 1 | 1, mid + 1, cr);
		push_up(p);
	}
}

void init(const std::vector <int>& vec)
{
	sgt::n = vec.size() - 1;
	build(vec);
}

void con(int x, int p = 1, int cl = 0, int cr = n)
{
	if (mx[p] < x)
		push_add(p, 1);
	else if (x < mn[p])
		push_add(p, -1);
	else if (mn[p] != mx[p])
	{
		push_down(p);
		int mid = (cl + cr) >> 1;
		con(x, p << 1, cl, mid);
		con(x, p << 1 | 1, mid + 1, cr);
		push_up(p);
	}
}

void assign(const std::vector <int>& vec, int p = 1, int cl = 0, int cr = n)
{
	if (cl == cr)
		ans[vec[cl]] = mx[p];
	else
	{
		push_down(p);
		int mid = (cl + cr) >> 1;
		assign(vec, p << 1, cl, mid);
		assign(vec, p << 1 | 1, mid + 1, cr);
	}
}
}

void solve(int p = 1, int cl = 1, int cr = n)
{
	if (not nd[p].empty())
	{
		std::sort(nd[p].begin(), nd[p].end(), [](int a, int b) -> bool
		{
			return ans[a] < ans[b];
		});
		sgt::init(nd[p]);
		for (int i = cl; i <= cr; i++)
			sgt::con(a[i]);
		sgt::assign(nd[p]);
	}
	if (cl != cr)
	{
		int mid = (cl + cr) >> 1;
		solve(p << 1, cl, mid);
		solve(p << 1 | 1, mid + 1, cr);
	}
}
}
}

void init(int n)
{
	sgt::n = n;
}

void add(int l, int r, int c, int id)
{
	sgt::add(l, r, id);
	ans[id] = c;
}

using sgt::solve::solve;
}

int main()
{
	freopen("thief.in", "r", stdin);
	freopen("thief.out", "w", stdout);
	int n = read(), m = read(), l, r, c;
	for (int i = 1; i <= n; a[i++] = read());
	solve::init(n);
	for (int i = 1; i <= m; i++)
	{
		l = read(); r = read(); c = read();
		solve::add(l, r, c, i);
	}
	solve::solve();
	for (int i = 1; i <= m; i++)
		write(solve::ans[i]),
		putchar('\n');
}
