#include <cstdio>
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

const int MX = 250010, R = 4, P = 998244353;

int a[MX], b[MX], c[MX];

namespace solve
{
inline int md(int x)
{
	return x >= P ? x - P : x;
}

inline void add(int& x, int y)
{
	x = md(x + y);
}

struct matrix
{
	int m[R][R];
	
	const static matrix I;
	
	matrix operator* (const matrix& oth)
	{
		matrix ret = {};
		for (int i = 0; i < R; i++)
			for (int j = 0; j < R; j++)
				for (int k = 0; k < R; k++)
					add(ret.m[i][j], (intt)m[i][k] * oth.m[k][j] % P);
		return ret;
	}
	
	void operator*= (const matrix& oth)
	{
		*this = *this * oth;
	}
};

struct anst
{
	int a, b, c;
	
	anst() = default;
	anst(const matrix& m): a(m.m[0][0]), b(m.m[0][1]), c(m.m[0][2]) {}
	
	void operator+= (const anst& oth)
	{
		add(a, oth.a);
		add(b, oth.b);
		add(c, oth.c);
	}
};

namespace sgt
{
matrix tree[MX << 2], mk[MX << 2];
bool ismk[MX << 2];
int n;

void push_down(int p)
{
	if (ismk[p])
	{
		tree[p << 1] *= mk[p];
		tree[p << 1 | 1] *= mk[p];
		mk[p << 1] *= mk[p];
		mk[p << 1 | 1] *= mk[p];
		ismk[p << 1] = ismk[p << 1 | 1] = true;
		mk[p] = matrix::I;
		ismk[p] = false;
	}
}

void push_up(int p)
{
	tree[p].m[0][0] = md(tree[p << 1].m[0][0] + tree[p << 1 | 1].m[0][0]);
	tree[p].m[0][1] = md(tree[p << 1].m[0][1] + tree[p << 1 | 1].m[0][1]);
	tree[p].m[0][2] = md(tree[p << 1].m[0][2] + tree[p << 1 | 1].m[0][2]);
}

void build(int p = 1, int cl = 1, int cr = n)
{
	mk[p] = matrix::I;
	if (cl == cr)
		tree[p].m[0][0] = a[cl],
		tree[p].m[0][1] = b[cl],
		tree[p].m[0][2] = c[cl],
		tree[p].m[0][3] = 1;
	else
	{
		int mid = (cl + cr) >> 1;
		build(p << 1, cl, mid);
		build(p << 1 | 1, mid + 1, cr);
		tree[p].m[0][3] = cr - cl + 1;
		push_up(p);
	}
}

void update(int l, int r, const matrix& m, int p = 1, int cl = 1, int cr = n)
{
	if (l <= cl and cr <= r)
	{
		tree[p] *= m;
		if (cl != cr)
			mk[p] *= m,
			ismk[p] = true;
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

anst query(int l, int r, int p = 1, int cl = 1, int cr = n)
{
	if (l <= cl and cr <= r)
		return tree[p];
	else
	{
		push_down(p);
		int mid = (cl + cr) >> 1;
		anst ret = {};
		if (l <= mid)
			ret += query(l, r, p << 1, cl, mid);
		if (mid < r)
			ret += query(l, r, p << 1 | 1, mid + 1, cr);
		return ret;
	}
}
}

const matrix matrix::I = {{
	{ 1 },
	{ 0, 1 },
	{ 0, 0, 1 },
	{ 0, 0, 0, 1 }
}}, aA = {{
	{ 1 },
	{ 1, 1 },
	{ 0, 0, 1 },
	{ 0, 0, 0, 1 }
}}, aB = {{
	{ 1 },
	{ 0, 1 },
	{ 0, 1, 1 },
	{ 0, 0, 0, 1 }
}}, aC = {{
	{ 1, 0, 1 },
	{ 0, 1 },
	{ 0, 0, 1 },
	{ 0, 0, 0, 1 }
}};
matrix eA = {{
	{ 1 },
	{ 0, 1 },
	{ 0, 0, 1 },
	{ 0, 0, 0, 1 }
}}, eB = {{
	{ 1 },
	{ 0, 0 },
	{ 0, 0, 1 },
	{ 0, 0, 0, 1 }
}}, eC = {{
	{ 1 },
	{ 0, 1 },
	{ 0, 0, 0 },
	{ 0, 0, 0, 1 }
}};

void init(int n)
{
	sgt::n = n;
	sgt::build();
}

void addA(int l, int r)
{
	sgt::update(l, r, aA);
}

void addB(int l, int r)
{
	sgt::update(l, r, aB);
}

void addC(int l, int r)
{
	sgt::update(l, r, aC);
}

void enA(int l, int r, int v)
{
	eA.m[3][0] = v;
	sgt::update(l, r, eA);
}

void enB(int l, int r, int v)
{
	eB.m[1][1] = v;
	sgt::update(l, r, eB);
}

void enC(int l, int r, int v)
{
	eC.m[3][2] = v;
	sgt::update(l, r, eC);
}

using sgt::query;
}

int main()
{
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
	int n = read(), m;
	for (int i = 1; i <= n; i++)
		a[i] = read(), b[i] = read(), c[i] = read();
	solve::init(n);
	m = read();
	int op, l, r, v;
	solve::anst ans;
	while (m--)
	{
		op = read(); l = read(); r = read();
		if (op == 1)
			solve::addA(l, r);
		else if (op == 2)
			solve::addB(l, r);
		else if (op == 3)
			solve::addC(l, r);
		else if (op <= 6)
		{
			v = read();
			if (op == 4)
				solve::enA(l, r, v);
			else if (op == 5)
				solve::enB(l, r, v);
			else
				solve::enC(l, r, v);
		}
		else
			ans = solve::query(l, r),
			printf("%d %d %d\n", ans.a, ans.b, ans.c);
	}
}
