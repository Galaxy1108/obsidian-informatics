#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <cstring>
#define min(A, B) (A < B ? A : B)
#define INF 1e9

inline void minx(int& a, int b)
{
	a = min(a, b);
}

const int MX = 100010, MXV = MX << 2;

std::vector <int> T[MX];

namespace solve
{
namespace HLD
{
int fa[MX], siz[MX], dep[MX], hs[MX], top[MX], pos[MX], tot;int id[MX];

void DFS(int u)
{
	siz[u] = 1;
	for (int v : T[u])
	{
		if (v != fa[u])
		{
			dep[v] = dep[u] + 1;
			fa[v] = u;
			DFS(v);
			siz[u] += siz[v];
			if (siz[v] > siz[hs[u]])
				hs[u] = v;
		}
	}
}

void DFS1(int u, int tp)
{
	pos[u] = ++tot;id[tot] = u;
	top[u] = tp;
	if (hs[u])
		DFS1(hs[u], tp);
	for (int v : T[u])
	{
		if (v != fa[u] and v != hs[u])
		{
			DFS1(v, v);
		}
	}
}

template <typename F>
int modi(int u, int v, F f)
{
	while (top[u] != top[v])
	{
		if (dep[top[u]] > dep[top[v]])
			std::swap(u, v);
		f(pos[top[v]], pos[v]);
		v = fa[top[v]];
	}
	if (dep[u] > dep[v])
		std::swap(u, v);
	f(pos[u], pos[v]);
	return u;
}

namespace fl
{
namespace sgt
{
int tree[MX << 2], n;

void build(int p = 1, int cl = 1, int cr = n)
{
	tree[p] = INF;
	if (cl != cr)
	{
		int mid = (cl + cr) >> 1;
		build(p << 1, cl, mid);
		build(p << 1 | 1, mid + 1, cr);
	}
}

void update(int x, int v, int p = 1, int cl = 1, int cr = n)
{
	if (cl == cr)
	{
		minx(tree[p], v);
	}
	else
	{
		int mid = (cl + cr) >> 1;
		if (x <= mid)
			update(x, v, p << 1, cl, mid);
		else
			update(x, v, p << 1 | 1, mid + 1, cr);
		tree[p] = min(tree[p << 1], tree[p << 1 | 1]);
	}
}

int query(int l, int r, int p = 1, int cl = 1, int cr = n)
{
	if (l <= cl and cr <= r)
	{
		return tree[p];
	}
	else
	{
		int mid = (cl + cr) >> 1, ret = INF;
		if (l <= mid)
			minx(ret, query(l, r, p << 1, cl, mid));
		if (mid < r)
			minx(ret, query(l, r, p << 1 | 1, mid + 1, cr));
		return ret;
	}
}
}

namespace sgt2
{
std::set <int> tree[MX << 2];
int n;

void build(int p = 1, int cl = 1, int cr = n)
{
	tree[p].clear();
	if (cl != cr)
	{
		int mid = (cl + cr) >> 1;
		build(p << 1, cl, mid);
		build(p << 1 | 1, mid + 1, cr);
	}
}

void update(int x, int y, int p = 1, int cl = 1, int cr = n)
{
	tree[p].insert(y);
	if (cl != cr)
	{
		int mid = (cl + cr) >> 1;
		if (x <= mid)
			update(x, y, p << 1, cl, mid);
		else
			update(x, y, p << 1 | 1, mid + 1, cr);
	}
}

bool query(int l, int r, int yl, int yr, int p = 1, int cl = 1, int cr = n)
{
	if (l <= cl and cr <= r)
	{
		return tree[p].upper_bound(yr) != tree[p].lower_bound(yl);
	}
	else
	{
		int mid = (cl + cr) >> 1, ret = 0;
		if (l <= mid)
			ret |= query(l, r, yl, yr, p << 1, cl, mid);
		if (mid < r)
			ret |= query(l, r, yl, yr, p << 1 | 1, mid + 1, cr);
		return ret;
	}
}
}

void init(int n)
{
	sgt::n = n;
	sgt::build();
	sgt2::n = n;
	sgt2::build();
}

bool add(int s, int t)
{
	int lca = modi(s, t, [](int, int){});
	bool ret;
	if (lca == s or lca == t)
	{
		if (lca == s)
			std::swap(s, t);
		ret = sgt::query(pos[s], pos[s] + siz[s] - 1) > dep[t];
		sgt::update(pos[s], dep[t]);
	}
	else
	{
		if (pos[t] > pos[s])
			std::swap(s, t);
		sgt::update(pos[s], dep[lca]);
		sgt::update(pos[t], dep[lca]);
		ret = not sgt2::query(pos[s], pos[s] + siz[s] - 1, pos[t], pos[t] + siz[t] - 1);
		sgt2::update(pos[s], pos[t]);
	}
	return ret;
}
}

void init(int n)
{
	HLD::tot = 0;
	memset(hs + 1, 0, sizeof(int) * n);
	HLD::DFS(1);
	HLD::DFS1(1, 1);
	fl::init(n);
}
}

namespace G
{
std::vector <int> G[MXV];
int tot;

struct sgt
{
	static int n;
	int st, id[MX << 2];
	bool fl;
	
	void build(int p = 1, int cl = 1, int cr = n)
	{
		id[p] = ++tot;
		if (cl != cr)
		{
			int mid = (cl + cr) >> 1;
			build(p << 1, cl, mid);
			build(p << 1 | 1, mid + 1, cr);
			if (fl)
				G[id[p]].push_back(id[p << 1]),
				G[id[p]].push_back(id[p << 1 | 1]);
			else
				G[id[p << 1]].push_back(id[p]),
				G[id[p << 1 | 1]].push_back(id[p]);
		}
	}
	
	void link(int arr[], int p = 1, int cl = 1, int cr = n)
	{
		if (cl == cr)
		{
			if (fl and arr[cl])
				G[id[p]].push_back(arr[cl]);
			else if (arr[cl])
				G[arr[cl]].push_back(id[p]);
		}
		else
		{
			int mid = (cl + cr) >> 1;
			link(arr, p << 1, cl, mid);
			link(arr, p << 1 | 1, mid + 1, cr);
		}
	}
	
	void link(int l, int r, int u, int p = 1, int cl = 1, int cr = n)
	{
		if (l <= cl and cr <= r)
			if (fl)
				G[id[p]].push_back(u);
			else
				G[u].push_back(id[p]);
		else
		{
			int mid = (cl + cr) >> 1;
			if (l <= mid)
				link(l, r, u, p << 1, cl, mid);
			if (mid < r)
				link(l, r, u, p << 1 | 1, mid + 1, cr);
		}
	}
} in, out;

int sgt::n;

void init(int n, int m)
{
	for (int i = 1; i <= tot; G[i++].clear());
	sgt::n = n;
	tot = m;
	in.fl = true;
	out.fl = false;
	in.build();
	out.build();
}

namespace topo
{
int deg[MXV];

bool topo()
{
	memset(deg + 1, 0, sizeof(int) * tot);
	for (int i = 1; i <= tot; i++)
		for (int v : G[i])
			deg[v]++;
	std::queue <int> q;
	int cnt = 0;
	for (int i = 1; i <= tot; i++)
		if (not deg[i])
			q.push(i),
			cnt++;
	int u;
	while (not q.empty())
	{
		u = q.front();
		q.pop();
		for (int v : G[u])
			if (not --deg[v])
				q.push(v),
				cnt++;
	}
	return cnt == tot;
}
}
}
	
int sid[MX], tid[MX], tot;
bool fl;

void init(int n, int m)
{
	tot = 0;
	HLD::init(n);
	G::init(n, m);
	memset(sid + 1, 0, sizeof(int) * n);
	memset(tid + 1, 0, sizeof(int) * n);
	fl = true;
}

void add(int s, int t)
{
	sid[HLD::pos[s]] = ++tot;
	tid[HLD::pos[t]] = tot;
	HLD::modi(s, t, [](int l, int r)
	{
//		printf("%d:\n", tot);
//		for (int i = l; i <= r; i++)
//		printf("%d ", HLD::id[i]);
//		putchar('\n');
		G::in.link(l, r, tot);
		G::out.link(l, r, tot);
	});
	fl = fl and HLD::fl::add(s, t);
}

bool query()
{
	G::in.link(tid);
	G::out.link(sid);
	return G::topo::topo() and fl;
}
}

int main()
{
	int q, n, m;
	scanf("%d", &q);
	while (q--)
	{
		scanf("%d", &n);
		for (int i = 1, u, v; i < n; i++)
		{
			scanf("%d%d", &u, &v);
			T[u].push_back(v);
			T[v].push_back(u);
		}
		scanf("%d", &m);
		solve::init(n, m);
		for (int i = 1, s, t; i <= m; i++)
		{
			scanf("%d%d", &s, &t);
			solve::add(s, t);
		}
		printf("%s\n", solve::query() ? "Yes" : "No");
		for (int i = 1; i <= n; T[i++].clear());
	}
}
