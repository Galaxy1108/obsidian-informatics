#include <cstdio>
#define INF 1e9

const int MX = 510;

struct edge
{
	int u, v;
} E[MX];

int a[MX];

namespace solve
{
namespace DSU
{
int fa[MX];

void init(int n)
{
	for (int i = 1; i <= n; fa[i] = i, i++);
}

int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

bool in(int u, int v)
{
	return find(u) == find(v);
}

void unite(int u, int v)
{
	fa[find(u)] = find(v);
}
}

int g[MX];
bool vis[MX];

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int solve(int n, int k)
{
	k = n - 1 - k;
	DSU::init(n);
	for (int i = 1; i <= n; g[i] = a[i], i++);
	while (k--)
	{
		int mn = INF, e;
		for (int i = 1; i < n; i++)
			if (not vis[i] and g[DSU::find(E[i].u)] + g[DSU::find(E[i].v)] - gcd(g[DSU::find(E[i].u)], g[DSU::find(E[i].v)]) < mn)
				e = i,
				mn = g[DSU::find(E[i].u)] + g[DSU::find(E[i].v)] - gcd(g[DSU::find(E[i].u)], g[DSU::find(E[i].v)]);
		
		g[DSU::find(E[e].v)] = gcd(g[DSU::find(E[e].u)], g[DSU::find(E[e].v)]);
		DSU::unite(E[e].u, E[e].v);
		vis[e] = true;
	}
	int ret = 0;
	for (int i = 1; i <= n; i++)
		if (DSU::find(i) == i)
			ret += g[i];
	return ret;
}
}

int main()
{
	freopen("plan.in", "r", stdin);
	freopen("plan.out", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++)
		scanf("%d%d", &E[i].u, &E[i].v);
	for (int i = 1; i <= n; scanf("%d", a + i++));
	printf("%d", solve::solve(n, k));
}
