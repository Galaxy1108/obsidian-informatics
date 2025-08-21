#include <cstdio>
#include <utility>

const int MX = 2510;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

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

std::pair <int, int> E[MX];
bool pri[MX], vis[MX];

int main()
{
	freopen("divisors.in", "r", stdin);
	freopen("divisors.out", "w", stdout);
	int n, tot = 0;
	scanf("%d", &n);
	DSU::init(n);
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int x = 1; x < i; x++)
		{
			if (not (i % x))
			{
			cnt++;
				vis[x] = true;
				if (not DSU::in(i, x))
					DSU::unite(i, x),
					E[++tot] = { i, x };
			}
		}
		if (cnt == 1)
			pri[i] = true;
	}
	int lcm = 1;
	for (int x = 1; x <= n; x++)
	{
		if (pri[x] or not vis[x])
			lcm = lcm * x / gcd(lcm, x);
		if (not vis[x])
			E[++tot] = { 1, x };
	}
	printf("%d ", lcm);
	for (int i = 2; i <= n; i++)
	{
		printf("%d ", i);
	}putchar('\n');
	for (int i = 1; i <= tot; i++)
		printf("%d %d\n", E[i].first, E[i].second);
}
