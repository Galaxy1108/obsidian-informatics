#include <cstdio>
#include <map>

const int MX = 50010, MXKQ = 150010, MXV = (MX << 2) + (MXKQ << 1);

namespace solve
{
struct anst
{
	int x, y;
} pos[MXV];

namespace LCT
{
int fa[MXV], son[MXV][2], siz[MXV], tot;

#define get(x) (son[fa[x]][1] == x)
#define isrt(x) (son[fa[x]][0] != x and son[fa[x]][1] != x)
#define update(x) (siz[x] = siz[son[x][0]] + 1 + siz[son[x][1]])

void rotate(int x)
{
	int ffa = fa[fa[x]], dr = get(x);
	if (not isrt(fa[x]))
		son[ffa][get(fa[x])] = x;
	fa[son[x][not dr]] = fa[x];
	son[fa[x]][dr] = son[x][not dr];
	son[x][not dr] = fa[x];
	fa[fa[x]] = x;
	fa[x] = ffa;
	update(son[x][not dr]);
	update(x);
}

void splay(int x)
{
	while (not isrt(x))
	{
		if (not isrt(fa[x]))
			rotate(get(x) == get(fa[x]) ? fa[x] : x);
		rotate(x);
	}
}

int access(int x)
{
	int p = 0;
	for (; x; p = x, x = fa[x])
	{
		splay(x);
		son[x][1] = p;
		update(x);
	}
	return p;
}

void cut(int u, int v)
{
	access(v);
	splay(u);
	fa[u] = 0;
}

void link(int u, int v)
{
	fa[access(u)] = v;
}

int kth(int x, int k)
{
	k++;
	int p = access(x), pfa;
	while (p)
	{
		pfa = p;
		if (k > siz[son[p][1]])
		{
			k -= siz[son[p][1]] + 1;
			if (not k)
				break;
			p = son[p][0];
		}
		else
			p = son[p][1];
	}
	splay(p ? p : pfa);
	return p ? p : pfa;
}

#undef get
#undef isrt
#undef update
}

std::map <int, int> mr[MX], mc[MX];
int oppo[MXV], tid;

void init(int n, int m)
{
	for (int i = 1; i <= n; i++)
		mr[i].insert({ 0, ++tid }),
		pos[tid] = { i, 0 },
		oppo[tid] = tid,
		mr[i].insert({ m + 1, ++tid }),
		pos[tid] = { i, m + 1 },
		LCT::link(mr[i].begin()->second, mr[i].rbegin()->second);
	for (int i = 1; i <= m; i++)
		mc[i].insert({ 0, ++tid }),
		pos[tid] = { 0, i },
		oppo[tid] = tid,
		mc[i].insert({ n + 1, ++tid }),
		pos[tid] = { n + 1, i },
		LCT::link(mc[i].begin()->second, mc[i].rbegin()->second);
}

void add(int x, int y)
{
	int id0 = ++tid, id1 = ++tid;
	pos[id0] = pos[id1] = { x, y };
	oppo[id0] = id1; oppo[id1] = id0;
	auto itr = mr[x].upper_bound(y), itc = mc[y].lower_bound(x);
	int rl = oppo[prev(itr)->second], rr = itr->second, cl = oppo[prev(itc)->second], cr = itc->second;
	LCT::cut(rl, rr);
	LCT::link(rl, id0);
	LCT::cut(cl, cr);
	LCT::link(cl, id1);
	LCT::link(id0, cr);
	LCT::link(id1, rr);
	mr[x].insert({ y, id0 });
	mc[y].insert({ x, id1 });
}

anst query(int x, int y, int q)
{
	return pos[LCT::kth(x ? mr[x].begin()->second : mc[y].begin()->second, q)];
}
}

int main()
{
	freopen("corridor.in", "r", stdin);
	freopen("corridor.out", "w", stdout);
	int n, m, k, q, x, y, w, qq;
	scanf("%*d%d%d%d", &n, &m, &k);
	solve::init(n, m);
	while (k--)
		scanf("%d%d", &x, &y),
		solve::add(x, y);
	solve::anst ans;
	scanf("%d", &q);
	while (q--)
	{
		scanf("%d%d%d", &w, &x, &y);
		if (w == 1)
			solve::add(x, y);
		else
			scanf("%d", &qq),
			ans = solve::query(x, y, qq),
			printf("%d %d\n", ans.x, ans.y);
	}
}
