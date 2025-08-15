#include <cstdio>
#include <vector>
#include <cstring>
#define max(A, B) (A < B ? B : A)
#define maxx(A, B) (A = max(A, B))
typedef long long intt;

int read()
{
	char c = getchar();
	int fl = 1;
	while (c < '0' or '9' < c)
	{
		if (c == '-')
			fl = -1;
		c = getchar();
	}
	int ret = 0;
	while ('0' <= c and c <= '9')
		ret = (ret << 3) + (ret << 1) + c - '0',
		c = getchar();
	return ret * fl;
}

const int MX = 5010;

int f1[MX], f2[MX], d[MX], a[MX];

namespace solve
{
namespace tr
{
std::vector <int> T[MX];
intt dep[MX];
int lca[MX][MX];

void DFS(int u, std::vector <int>& t)
{
	t.push_back(u);
	for (int v : T[u])
		DFS(v, t);
}

void init(int n)
{
	for (int i = 1; i <= n; i++)
		dep[i] = dep[f1[i]] + d[i],
		T[f1[i]].push_back(i);
	for (int i = 1; i <= n; i++)
	{
		std::vector <int> son, t;
		son.push_back(i);
		lca[i][i] = i;
		for (int v : T[i])
		{
			t.clear();
			DFS(v, t);
			for (int x : t)
				for (int y : son)
					lca[x][y] = lca[y][x] = i;
			son.insert(son.end(), t.begin(), t.end());
		}
	}
}

intt dis(int u, int v)
{
	return dep[u] + dep[v] - (dep[lca[u][v]] << 1);
}
}

intt ans[MX], sum[MX], ts[MX];
bool vis[MX];

void solve(int n)
{
	tr::init(n);
	for (int i = 1; i <= n; i++)
	{
		memset(vis, 0, sizeof(vis));
		vis[i] = true;
		sum[i] = 0;
		ts[i] = a[i];
		for (int u = i + 1; u <= n; u++)
		{
			if (vis[f2[u]])
			{
				vis[u] = true;
				sum[u] = sum[f2[u]] + ts[f2[u]];
				ts[u] = ts[f2[u]] + a[u];
				maxx(ans[i], tr::dis(i, u) + sum[u]);
			}
		}
	}
}
}

namespace solve1
{
namespace sgt
{
intt tree[MX << 2], mark[MX << 2];
int ls[MX << 2], rs[MX << 2], n, tot;

void push_up(int p)
{
	tree[p] = max(tree[ls[p]], tree[rs[p]]);
}

void push_down(int p)
{
	if (mark[p])
	{
		if (ls[p])
			tree[ls[p]] += mark[p],
			mark[ls[p]] += mark[p];
		if (rs[p])
			tree[rs[p]] += mark[p],
			mark[rs[p]] += mark[p];
		mark[p] = 0;
	}
}

void update(int x, intt v, int p = 1, int cl = 1, int cr = n)
{
	if (cl == cr)
		tree[p] = v;
	else
	{
		push_down(p);
		int mid = (cl + cr) >> 1;
		if (x <= mid)
		{
			if (not ls[p])
				ls[p] = ++tot;
			update(x, v, ls[p], cl, mid);
		}
		else
		{
			if (not rs[p])
				rs[p] = ++tot;
			update(x, v, rs[p], mid + 1, cr);
		}
		push_up(p);
	}
}

void add(intt x)
{
	tree[1] += x;
	mark[1] += x;
}
}

intt pre[MX], ans[MX], sum[MX];

void solve(int n)
{
	sgt::n = n;
	memset(sgt::tree, 0xc0, sizeof(sgt::tree));
	for (int i = 1; i <= n; i++)
		pre[i] = pre[i - 1] + d[i];
	intt sum = 0;
	for (int i = n; i; i--)
	{
		sgt::update(i, 0);
	}
}
}

int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	int n = read();
	for (int i = 2; i <= n; f1[i++] = read());
	for (int i = 2; i <= n; d[i++] = read());
	for (int i = 2; i <= n; f2[i++] = read());
	for (int i = 1; i <= n; a[i++] = read());
	if (n <= 5000)
	{
		solve::solve(n);
		for (int i = 1; i <= n; i++)
			printf("%lld ", solve::ans[i]);
	}
	else
	{
		solve1::solve(n);
		for (int i = 1; i <= n; i++)
			printf("%lld ", solve1::ans[i]);
	}
}
