#include <cstdio>
#include <vector>
#define max(A, B) (A < B ? B : A)
#define maxx(A, B) (A = max(A, B))
typedef long long intt;

const int MX = 5010;

struct edge
{
	int to, w, id;
};

std::vector <edge> T[MX];
int w[MX];

namespace solve
{
int c[MX][MX], f[MX];
intt a[MX][MX];

int DFS(int u, int c[], int e = 0)
{
	int siz = 1;
	for (edge& ee : T[u])
	{
		if (ee.id != e)
			siz += DFS(ee.to, c, ee.id);
	}
	c[e] = siz;
	return siz;
}

int solve(int n)
{
	for (int i = 1; i <= n; i++)
		DFS(i, c[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = (intt)c[j][i] * w[i];
	for (int i = 1; i <= n; i++)
	{
		intt mx = 0;
		for (int j = 1; j <= n; j++)
			if (a[j][i] > mx)
				mx = a[j][i];
		for (int j = 1; j <= n; j++)
			if (a[j][i] == mx)
				f[j]++;
	}
	int ret = 0;
	for (int i = 1; i <= n; i++)
		ret ^= f[i];
	return ret;
}
}

namespace solve1
{
const int MX = 1000010;

int siz[MX], mxs[MX], fa[MX], n;

void DFS(int u)
{
	siz[u] = 1;
	for (edge& e : T[u])
	{
		int v = e.to;
		if (v != fa[u])
			fa[v] = u,
			DFS(v),
			siz[u] += siz[v],
			maxx(mxs[u], siz[v]);
	}
	maxx(mxs[u], n - siz[u]);
}

int solve(int n)
{
	solve1::n = n;
	DFS(1);
	int ret = 0;
	for (int i = 2; i <= n; i++)
	{
		int cnt = 0;
		if (siz[i] == mxs[fa[i]])
			cnt++;
		if (n - siz[i] == mxs[i])
			cnt++;
		ret ^= cnt;
	}
	return ret;
}
}

int main()
{
	freopen("treeq.in", "r", stdin);
	freopen("treeq.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 2, f, w; i <= n; i++)
		scanf("%d%d", &f, &w),
		::w[i] = w,
		T[f].push_back({ i, w, i }),
		T[i].push_back({ f, w, i });
	bool fl = true;
	for (int i = 2; i <= n; i++)
		if (w[i] != 1)
			fl = false;
	printf("%d", fl ? solve1::solve(n) : solve::solve(n));
}
