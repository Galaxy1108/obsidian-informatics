#include <cstdio>
#include <vector>
#define min(A, B) (A < B ? A : B)
#define minx(A, B) (A = min(A, B))
#define INF 1e9

const int MX = 50010, K = 10;

int a[MX];

namespace solve
{
int k;

namespace sgt
{
struct node
{
	std::vector <int> pre, suf;
	int ans, s, len;
	
	void init(int k, int len)
	{
		pre.assign(1 << k, INF);
		suf.assign(1 << k, INF);
		pre[0] = suf[0] = 0;
		ans = INF;
		this->len = len;
	}
	
	void set(int x)
	{
		for (int t = s; t; --t &= s)
			pre[t] = suf[t] = INF;
		pre[1 << x] = suf[1 << x] = 1;
		s = 1 << x;
	}
} tree[MX << 2];

void merge(node& a, node& b, node& c)
{
	for (int t = c.s; t; --t &= c.s)
		c.pre[t] = c.suf[t] = INF;
	c.ans = min(a.ans, b.ans);
	c.s = a.s | b.s;
	
	for (int t = c.s; t; --t &= c.s)
		c.pre[t] = min(a.pre[t], a.len + b.pre[t ^ (a.s & t)]),
		c.suf[t] = min(b.suf[t], b.len + a.suf[t ^ (b.s & t)]);
	
	for (int t = b.s; t; --t &= b.s)
		minx(c.ans, b.pre[t] + a.suf[(1 << k) - 1 ^ t]);
}

int n;

void build(int p = 1, int cl = 1, int cr = n)
{
	tree[p].init(k, cr - cl + 1);
	if (cl == cr)
		tree[p].set(a[cl] - 1);
	else
	{
		int mid = (cl + cr) >> 1;
		build(p << 1, cl, mid);
		build(p << 1 | 1, mid + 1, cr);
		merge(tree[p << 1], tree[p << 1 | 1], tree[p]);
	}
}

void set(int x, int v, int p = 1, int cl = 1, int cr = n)
{
	if (cl == cr)
		tree[p].set(v - 1);
	else
	{
		int mid = (cl + cr) >> 1;
		if (x <= mid)
			set(x, v, p << 1, cl, mid);
		else
			set(x, v, p << 1 | 1, mid + 1, cr);
		merge(tree[p << 1], tree[p << 1 | 1], tree[p]);
	}
}

int query()
{
	return tree[1].ans;
}
}

void init(int n, int k)
{
	solve::k = k;
	sgt::n = n;
	sgt::build();
}

using sgt::set;

int query()
{
	return sgt::query() < INF ? sgt::query() : -1;
}
}

int main()
{
	freopen("truth.in", "r", stdin);
	freopen("truth.out", "w", stdout);
	int n, k, m;
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 1; i <= n; scanf("%d", a + i++));
	solve::init(n, k);
	int op, p, v;
	while (m--)
	{
		scanf("%d", &op);
		if (op == 1)
			scanf("%d%d", &p, &v),
			solve::set(p, v);
		else
			printf("%d\n", solve::query());
	}
}
