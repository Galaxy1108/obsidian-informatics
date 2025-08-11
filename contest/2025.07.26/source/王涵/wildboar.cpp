#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define min(A, B) (A < B ? A : B)
#define minx(A, B) (A = min(A, B))
#define INF (intt)1e18
typedef long long intt;

const int MX = 2010, R = 2, MXL = 100010;

struct node
{
	int u, v;
} E[MX];

struct edge
{
	int to, w, id;
};

std::vector <edge> G[MX];
int x[MXL];

namespace solve
{
namespace sp
{
intt dis[MX << 1][MX << 1];

void dij(int u, intt dis[])
{
	static bool vis[MX << 1];
	memset(vis, 0, sizeof(vis));
	std::priority_queue <std::pair <intt, int>, std::vector <std::pair <intt, int> >, std::greater <std::pair <intt, int> > > q;
	q.push({ 0, u });
	dis[u] = 0;
	while (not q.empty())
	{
		u = q.top().second;
		q.pop();
		if (vis[u]) continue;
		else vis[u] = true;

		for (edge& e : G[u & 1 ? E[u >> 1].u : E[u >> 1].v])
		{
#define v e.to
			if (e.id == u >> 1) continue;
			if (dis[(e.id) << 1 | (E[e.id].u == v)] > dis[u] + e.w)
			{
				dis[(e.id) << 1 | (E[e.id].u == v)] = dis[u] + e.w;
				q.push({ dis[(e.id) << 1 | (E[e.id].u == v)], (e.id) << 1 | (E[e.id].u == v) });
			}
#undef v
		}
	}
}

void sp(int m)
{
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= (m << 1) + 1; i++)
	{
		dij(i, dis[i]);
	}
}
}

intt dis[MX << 1];

intt solve(int m, int l)
{
	E[0].u = x[1];
	sp::sp(m);
	for (int pt = 2; pt <= l; pt++)
	{
		for (int j = 1; j <= (m << 1) + 1; j++)
		{
			if ((j & 1 ? E[j >> 1].u : E[j >> 1].v) == x[pt])
			{
				dis[j] = INF;
			}
		}
		for (int i = 1; i <= (m << 1) + 1; i++)
		{
			if ((i & 1 ? E[i >> 1].u : E[i >> 1].v) == x[pt - 1])
			for (int j = 1; j <= (m << 1) + 1; j++)
			{
				if ((j & 1 ? E[j >> 1].u : E[j >> 1].v) == x[pt])
				{
					minx(dis[j], dis[i] + sp::dis[i][j]);
				}
			}
		}
	}
	intt ret = INF;
	for (int i = 1; i <= (m << 1) + 1; i++)
	{
		if ((i & 1 ? E[i >> 1].u : E[i >> 1].v) == x[l])
		{
			minx(ret, dis[i]);
		}
	}
	return ret;
}
}

int main()
{
	freopen("wildboar.in", "r", stdin);
	freopen("wildboar.out", "w", stdout);
	int n, m, t, l, u, v, w, p, q;
	scanf("%d%d%d%d", &n, &m, &t, &l);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		G[u].push_back({ v, w, i });
		G[v].push_back({ u, w, i });
		E[i] = { u, v };
	}
	for (int i = 1; i <= l; scanf("%d", x + i++));
	scanf("%d%d", &p, &q);
	x[p] = q;
	printf("%lld", solve::solve(n, l));
}
