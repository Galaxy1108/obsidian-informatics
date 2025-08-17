#include <cstdio>
#include <algorithm>
typedef long long intt;

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

const int MX = 100010, P = 1e9 + 9;

struct oper
{
	int l, r, x;
} op[MX];

struct qry
{
	int ver, l, r, k, id;
} qr[MX << 1];

int ans[MX];

namespace solve
{
struct Barrett
{
	int p;
	intt m;
	
	Barrett(int p): p(p), m(((__int128)1 << 64) / p) {}
	
	int operator() (intt x)
	{
		return x - ((__int128)x * m >> 64) * p;
	}
} mod(P);

inline int md(int x)
{
	return x >= P ? x - P : x;
}

inline void add(int& x, int y)
{
	x = md(x + y);
}

namespace sgt
{
struct matrix
{
	int m[3][3];
	
	const static matrix I;
	
	matrix operator* (matrix oth)
	{
		return {{
			{ mod((intt)m[0][0] * oth.m[0][0]), mod((intt)m[0][0] * oth.m[0][1] + (intt)m[0][1] * oth.m[1][1]), mod((intt)m[0][0] * oth.m[0][2] + (intt)m[0][1] * oth.m[1][2] + (intt)m[0][2] * oth.m[2][2]) },
			{ 0, mod((intt)m[1][1] * oth.m[1][1]), mod((intt)m[1][1] * oth.m[1][2] + (intt)m[1][2] * oth.m[2][2]) },
			{ 0, 0, mod((intt)m[2][2] * oth.m[2][2]) }
		}};
	}
	
	void operator*= (matrix oth)
	{
		*this = *this * oth;
	}
} tree[MX << 2], mark[MX << 2];

const matrix matrix::I = {{
	{ 1 },
	{ 0, 1 },
	{ 0, 0, 1 }
}};

bool mk[MX << 2];
int n;

void push_up(int p)
{
	tree[p].m[0][1] = md(tree[p << 1].m[0][1] + tree[p << 1 | 1].m[0][1]);
	tree[p].m[0][2] = md(tree[p << 1].m[0][2] + tree[p << 1 | 1].m[0][2]);
}

void build(int p = 1, int cl = 1, int cr = n)
{
	tree[p] = {{{ cr - cl + 1, 0, 0 }}};
	mark[p] = matrix::I;
	if (cl != cr)
	{
		int mid = (cl + cr) >> 1;
		build(p << 1, cl, mid);
		build(p << 1 | 1, mid + 1, cr);
		push_up(p);
	}
}

void push_down(int p)
{
	if (mk[p])
	{
		tree[p << 1] *= mark[p];
		tree[p << 1 | 1] *= mark[p];
		mark[p << 1] *= mark[p];
		mark[p << 1 | 1] *= mark[p];
		mark[p] = matrix::I;
		mk[p << 1] = mk[p << 1 | 1] = true;
		mk[p] = false;
	}
}

matrix tr(int x)
{
	return {{
		{ 1, x },
		{ 0, 1 },
		{ 0, 0, 1 }
	}};
}

matrix cpy()
{
	return {{
		{ 1 },
		{ 0, 1, 1 },
		{ 0, 0, 1 }
	}};
}

void update(int l, int r, const matrix& m, int p, int cl, int cr)
{
	if (l <= cl and cr <= r)
	{
		tree[p] *= m;
		if (cl != cr)
			mark[p] *= m,
			mk[p] = true;
	}
	else
	{
		push_down(p);
		int mid = (cl + cr) >> 1;
		if (l <= mid)
			update(l, r, m, p << 1, cl, mid);
		if (mid < r)
			update(l, r, m, p << 1 | 1, mid + 1, cr);
		push_up(p);
	}
}

void update(int l, int r, int x)
{
	update(l, r, tr(x), 1, 1, n);
}

void copy()
{
	tree[1] *= cpy();
	mark[1] *= cpy();
	mk[1] = true;
}

int query(int l, int r, int p = 1, int cl = 1, int cr = n)
{
	if (l <= cl and cr <= r)
	{
		return tree[p].m[0][2];
	}
	else
	{
		push_down(p);
		int mid = (cl + cr) >> 1, ret = 0;
		if (l <= mid)
			add(ret, query(l, r, p << 1, cl, mid));
		if (mid < r)
			add(ret, query(l, r, p << 1 | 1, mid + 1, cr));
		return ret;
	}
}
}

bool cmp(qry& a, qry& b)
{
	return a.ver < b.ver;
}

void solve(int n, int m, int tq)
{
	sgt::n = n;
	sgt::build();
	std::sort(qr + 1, qr + tq + 1, cmp);
	for (int i = 1, j = 1; i <= m; i++)
	{
		sgt::update(op[i].l, op[i].r, op[i].x);
		sgt::copy();
		for (; j <= tq and qr[j].ver == i; add(ans[qr[j].id], md(P + qr[j].k * sgt::query(qr[j].l, qr[j].r))), j++);
	}
}
}

int main()
{
	freopen("newfile.in", "r", stdin);
	freopen("newfile.out", "w", stdout);
	int n = read(), m = read(), q = read();
	for (int i = 1; i <= m; i++)
		op[i].l = read(),
		op[i].r = read(),
		op[i].x = read();
	int tq = 0;
	for (int i = 1, u, d, l, r; i <= q; i++)
	{
		u = read(); d = read(); l = read(); r = read();
		if (u > 1)
			qr[++tq] = { u - 1, l, r, -1, i };
		qr[++tq] = { d, l, r, 1, i };
	}
	solve::solve(n, m, tq);
	for (int i = 1; i <= q; i++)
		printf("%d\n", ans[i]);
}
