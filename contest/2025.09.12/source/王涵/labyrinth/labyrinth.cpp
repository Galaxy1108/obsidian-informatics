#include <cstdio>
#include <vector>
#include <cstring>
#include <random>
#include <ctime>
#define min(A, B) (A < B ? A : B)
#define max(A, B) (A < B ? B : A)
#define INF 1e9

inline void minx(int& a, int b)
{
	a = min(a, b);
}

inline void maxx(int& a, int b)
{
	a = max(a, b);
}

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

const int MX = 200010, C = 1145;

std::vector <int> T[MX];

namespace solve
{
inline bool possi(double p)
{
	static std::mt19937 r(time(nullptr));
	return r() < INT32_MAX * p;
}

bool vis[MX];

namespace ctr
{
int ctr, mnmxs, tot, siz[MX];

void DFS(int u, int fa = 0)
{
	siz[u] = 1;
	int mxs = 0;
	for (int v : T[u])
		if (not vis[v] and v != fa)
			DFS(v, u),
			siz[u] += siz[v],
			maxx(mxs, siz[v]);
	maxx(mxs, tot - siz[u]);
	if (mxs < mnmxs)
		ctr = u,
		mnmxs = mxs;
}

void DFS1(int u, int fa = 0)
{
	siz[u] = 1;
	int mxs = 0;
	for (int v : T[u])
		if (not vis[v] and v != fa)
			DFS1(v, u),
			siz[u] += siz[v],
			maxx(mxs, siz[v]);
	maxx(mxs, tot - siz[u]);
	if (u != ctr and possi(exp(-2 * (mxs - mnmxs))))
		ctr = u;
}

int getctr(int u, int tot)
{
	mnmxs = INF;
	ctr::tot = tot;
	DFS(u);
	DFS1(u);
	return ctr;
}
}

int siz[MX];

void DFS(int u, int fa = 0)
{
	siz[u] = 1;
	for (int v : T[u])
		if (not vis[v] and v != fa)
			DFS(v, u),
			siz[u] += siz[v];
}

int TD(int u, int tot)
{
	u = ctr::getctr(u, tot);
	vis[u] = true;
	DFS(u);
	int ret = 0;
	for (int v : T[u])
		if (not vis[v])
			maxx(ret, TD(v, siz[v]));
	return ret + 1;
}

int solve(int n)
{
	memset(vis + 1, 0, sizeof(bool) * n);
	return TD(1, n);
}
}

int main()
{
	freopen("labyrinth.in", "r", stdin);
	freopen("labyrinth.out", "w", stdout);
	int t = read(), n;
	while (t--)
	{
		n = read();
		for (int i = 1, u, v; i < n; i++)
			u = read(), v = read(),
			T[u].push_back(v),
			T[v].push_back(u);
		int ans;
		if (n <= 20)
		{
			ans = INF;
			for (int i = 0; i < C; i++)
				minx(ans, solve::solve(n));
		}
		else
		{
			ans = 0;
			while (n)
				ans++,
				n >>= 1;
		}
		printf("%d\n", ans);
		for (int i = 1; i <= n; T[i++].clear());
	}
}
