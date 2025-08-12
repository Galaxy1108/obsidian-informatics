#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define min(A, B) (A < B ? A : B)
#define minx(A, B) (A = min(A, B))
#define INF 1e18
typedef long long intt;

intt read()
{
	char c = getchar();
	while (c < '0' or '9' < c)
		c = getchar();
	intt ret = 0;
	while ('0' <= c and c <= '9')
		ret = (ret << 3) + (ret << 1) + c - '0',
		c = getchar();
	return ret;
}

void write(intt x)
{
	if (x >= 10)
		write(x / 10);
	putchar(x % 10 + '0');
}

const int MX = 95;

struct edge
{
	int to;
	intt l, c;
};

std::vector <edge> G[MX];

namespace solve
{
namespace sp
{
bool vis[MX];

void dij(int u, int n, intt s, intt dis[])
{
	memset(dis, 0x3f, sizeof(intt) * n);
	memset(vis, 0, sizeof(bool) * n);
	std::priority_queue <std::pair <intt, int>, std::vector <std::pair <intt, int> >, std::greater <std::pair <intt, int> > > q;
	dis[u] = 0;
	q.push({ dis[u], u });
	while (not q.empty())
	{
		u = q.top().second;
		q.pop();
		if (vis[u]) continue;
		else vis[u] = true;
		
		intt t = dis[u] % s;
		
		for (edge& e : G[u])
		{
#define v e.to
			if (dis[v] > (t <= e.c - e.l ? dis[u] + e.l : dis[u] + s - t + e.l))
			{
				dis[v] = t <= e.c - e.l ? dis[u] + e.l : dis[u] + s - t + e.l;
				q.push({ dis[v], v });
			}
#undef v
		}
	}
}

void dij(int u, int n, intt s, intt dis[], intt pre)
{
	memset(dis, 0x3f, sizeof(intt) * n);
	memset(vis, 0, sizeof(bool) * n);
	std::priority_queue <std::pair <intt, int>, std::vector <std::pair <intt, int> >, std::greater <std::pair <intt, int> > > q;
	dis[u] = pre;
	q.push({ dis[u], u });
	while (not q.empty())
	{
		u = q.top().second;
		q.pop();
		if (vis[u]) continue;
		else vis[u] = true;
		
		intt t = dis[u] % s;
		
		for (edge& e : G[u])
		{
#define v e.to
			if (t <= e.c - e.l and dis[v] > dis[u] + e.l)
			{
				dis[v] = dis[u] + e.l;
				q.push({ dis[v], v });
			}
			else if (t > e.c - e.l)
				break;
#undef v
		}
	}
}
}

intt dis[MX][MX], s;
int n;

bool cmp(edge& a, edge& b)
{
	return a.c - a.l > b.c - b.l;
}

void init(int n, intt s)
{
	solve::n = n;
	solve::s = s;
	for (int i = 0; i < n; std::sort(G[i].begin(), G[i].end(), cmp), i++);
	for (int i = 0; i < n; i++)
		sp::dij(i, n, s, dis[i]);
}

intt query(int u, int v, intt t)
{
	static intt to[MX];
	sp::dij(u, n, s, to, t);
	intt ret = INF;
	for (int i = 0; i < n; i++)
		minx(ret, to[i] - t + (i != v) * (s - to[i] % s) + dis[i][v]);
	return ret;
}
}

int main()
{
	freopen("route.in", "r", stdin);
	freopen("route.out", "w", stdout);
	int n, m, q, u, v;
	intt s, l, c;
	n = read(); m = read(); s = read(); q = read();
	while (m--)
	{
		u = read(); v = read(); l = read(); c = read();
		G[u].push_back({ v, l, c });
		G[v].push_back({ u, l, c });
	}
	solve::init(n, s);
	while (q--)
	{
		u = read(); v = read(); l = read();
		write(solve::query(u, v, l));
		putchar('\n');
	}
}
