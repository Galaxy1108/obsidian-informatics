#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define max(A, B) (A < B ? B : A)
#define maxx(A, B) (A = max(A, B))
#define INF 1e9

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

const int MX = 200010;

std::vector <int> T[MX];

namespace solve
{
int ord[MX], siz[MX], anss[MX], xxx;
bool vis[MX], cc[MX];

bool DFS(int u, int fa = 0)
{
	if (u == xxx)
		return true;
	bool ret = false;
	for (int v : T[u])
		if (not vis[v] and v != fa)
			ret |= DFS(v, u);
	return ret;
}

void col(int u, int fa = 0)
{
	cc[u] = true;
	for (int v : T[u])
		if (not vis[v] and v != fa)
			col(v, u);
}

int solve(int n)
{
	for (int i = 1; i <= n; ord[i] = i, i++);
	int rrr = INF;
	do
	{
		int rr = 0;
		for (int x = 1; x <= n; x++)
		{
			int ans = 0;
			memset(vis + 1, 0, sizeof(bool) * n);
			memset(cc + 1, 0, sizeof(bool) * n);
			xxx = x;
			for (int i = 1; i <= n; i++)
			{
				if (cc[ord[i]])
					continue;
				
				vis[ord[i]] = true;
				ans++;
				if (ord[i] == x)
					break;
				for (int v : T[ord[i]])
					if (not vis[v])
						if (not DFS(v))
							col(v);
			}
			maxx(rr, ans);
		}
		if (rr < rrr)
			rrr = rr,
			memcpy(anss + 1, ord + 1, sizeof(int) * n);
	} while (std::next_permutation(ord + 1, ord + n + 1));
	for (int i = 1; i <= n; i++)
		fprintf(stderr, "%d ", anss[i]);
	fprintf(stderr, "\n");
	return rrr;
}
}

int main()
{
	freopen("x.in", "r", stdin);
	freopen("x.ans", "w", stdout);
	int t = read(), n;
	while (t--)
	{
		n = read();
		for (int i = 1, u, v; i < n; i++)
			u = read(), v = read(),
			T[u].push_back(v),
			T[v].push_back(u);
		printf("%d\n", solve::solve(n));
		for (int i = 1; i <= n; T[i++].clear());
	}
}
