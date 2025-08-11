#include <cstdio>
#include <vector>
#define min(A, B) (A < B ? A : B)
#define max(A, B) (A < B ? B : A)
#define INF 9e18
typedef long long intt;

const int MX = 200010, MXT = MX << 7, V = 1000000000;

int a[MX], h[MX], c[MX];

namespace solve
{
namespace tr
{
std::vector <int> T[MX];
int cyc[MX];
bool vis[MX], in[MX];

bool DFS(int u)
{
	vis[u] = true;
	if (in[a[u]])
	{
		cyc[u] = a[u];
		return true;
	}
	else
	{
		in[u] = true;
		if (DFS(a[u]) and cyc[a[u]] != a[u])
		{
			cyc[u] = cyc[a[u]];
			in[u] = false;
			return true;
		}
		else
		{
			in[u] = false;
			return false;
		}
	}
}

void build(int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (not vis[i])
		{
			DFS(i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (not cyc[i])
		{
			T[cyc[a[i]] ? cyc[a[i]] : a[i]].push_back(i);
		}
	}
}
}

namespace DP
{
namespace sgt
{
intt mx[MXT], mn[MXT], mk[MXT][2], st[MXT][2];
int ls[MXT], rs[MXT], tot;

int newrt()
{
	return ++tot;
}

#define gtmxls(p) (ls[p] ? mx[ls[p]] : st[p][0] + mk[p][0])
#define gtmxrs(p) (rs[p] ? mx[rs[p]] : st[p][1] + mk[p][1])
#define gtmnls(p) (ls[p] ? mn[ls[p]] : st[p][0] + mk[p][0])
#define gtmnrs(p) (rs[p] ? mn[rs[p]] : st[p][1] + mk[p][1])

void push_up(int p)
{
	mx[p] = max(gtmxls(p), gtmxrs(p));
	mn[p] = min(gtmnls(p), gtmnrs(p));
}

void push_down(int p)
{
	if (st[p][0] and ls[p])
	{
		mx[ls[p]] = mn[ls[p]] = st[ls[p]][0] = st[ls[p]][1] = st[p][0];
		mk[ls[p]][0] = mk[ls[p]][1] = st[p][0] = 0;
	}
	if (mk[p][0] and ls[p])
	{
		mx[ls[p]] += mk[p][0];
		mn[ls[p]] += mk[p][0];
		mk[ls[p]][0] += mk[p][0];
		mk[ls[p]][1] += mk[p][0];
		mk[p][0] = 0;
	}
	if (st[p][1] and rs[p])
	{
		mx[rs[p]] = mn[rs[p]] = st[rs[p]][0] = st[rs[p]][1] = st[p][1];
		mk[rs[p]][0] = mk[rs[p]][1] = st[p][1] = 0;
	}
	if (mk[p][1] and rs[p])
	{
		mx[rs[p]] += mk[p][1];
		mn[rs[p]] += mk[p][1];
		mk[rs[p]][0] += mk[p][1];
		mk[rs[p]][1] += mk[p][1];
		mk[p][1] = 0;
	}
}

intt add(int x, int v, int p, int cl = 1, int cr = V)
{
	if (cl == cr)
	{
		mx[p] += v;
		mn[p] += v;
		return mx[p];
	}
	else
	{
		push_down(p);
		int mid = (cl + cr) >> 1;
		intt ret;
		if (x <= mid)
		{
			if (not ls[p]) ls[p] = ++tot, push_down(p);
			ret = add(x, v, ls[p], cl, mid);
		}
		else
		{
			if (not rs[p]) rs[p] = ++tot, push_down(p);
			ret = add(x, v, rs[p], mid + 1, cr);
		}
		push_up(p);
		return ret;
	}
}

int upper(int r, intt x, int p, int cl = 1, int cr = V)
{
	if (cl == cr)
	{
		return cl;
	}
	else
	{
		push_down(p);
		int mid = (cl + cr) >> 1;
		if (r <= mid or gtmxls(p) > x)
		{
			if (not ls[p]) ls[p] = ++tot, push_down(p);
			return upper(r, x, ls[p], cl, mid);
		}
		else
		{
			if (not rs[p]) rs[p] = ++tot, push_down(p);
			return upper(r, x, rs[p], mid + 1, cr);
		}
	}
}

void set(int l, int r, intt x, int p, int cl = 1, int cr = V)
{
	if (l <= cl and cr <= r)
	{
		mx[p] = mn[p] = st[p][0] = st[p][1] = x;
		mk[p][0] = mk[p][1] = 0;
	}
	else
	{
		push_down(p);
		int mid = (cl + cr) >> 1;
		if (l <= mid)
		{
			if (not ls[p]) ls[p] = ++tot, push_down(p);
			set(l, r, x, ls[p], cl, mid);
		}
		if (mid < r)
		{
			if (not rs[p]) rs[p] = ++tot, push_down(p);
			set(l, r, x, rs[p], mid + 1, cr);
		}
		push_up(p);
	}
}

void merge(int p, int q, int cl = 1, int cr = V)
{
	if (cl == cr)
	{
		mx[p] += mx[q];
		mn[p] += mx[q];
	}
	else
	{
		push_down(p);
		push_down(q);
		int mid = (cl + cr) >> 1;
		if (st[q][0] or mk[q][0])
		{
			mk[p][0] += st[q][0] + mk[q][0];
		}
		else if (not ls[p])
		{
			ls[p] = ls[q];
			mk[p][0] += st[p][0];
			st[p][0] = 0;
		}
		else if (ls[q])
		{
			merge(ls[p], ls[q], cl, mid);
		}
		if (st[q][1] or mk[q][1])
		{
			mk[p][1] += st[q][1] + mk[q][1];
		}
		else if (not rs[p])
		{
			rs[p] = rs[q];
			mk[p][1] += st[p][1];
			st[p][1] = 0;
		}
		else if (rs[q])
		{
			merge(rs[p], rs[q], mid + 1, cr);
		}
		push_down(p);
		push_up(p);
	}
}

intt query(int p)
{
	return mn[p];
}

#undef gtmxls
#undef gtmxrs
#undef gtmnls
#undef gtmnrs
#undef ls
#undef rs
}

using tr::T;
using tr::cyc;

int rt[MX];

void DFS(int u)
{
	rt[u] = sgt::newrt();
	for (int v : T[u])
	{
		DFS(v);
		sgt::merge(rt[u], rt[v]);
	}
	if (not cyc[u])
	{
		intt t = sgt::add(h[u], -c[u], rt[u]);
		sgt::set(sgt::upper(h[u], t, rt[u]), h[u], t, rt[u]);
	}
}

intt DP(int n)
{
	intt sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += c[i];
		if (cyc[i] == i)
		{
			DFS(i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (cyc[i])
		{
			sgt::add(h[i], -c[i], rt[cyc[i]]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (cyc[i] == i)
		{
			sum += sgt::query(rt[i]);
		}
	}
	return sum;
}
}

intt solve(int n)
{
	tr::build(n);
	return DP::DP(n);
}
}

int main()
{
	freopen("reporter.in", "r", stdin);
	freopen("reporter.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", a + i, h + i, c + i);
	}
	printf("%lld", solve::solve(n));
}
