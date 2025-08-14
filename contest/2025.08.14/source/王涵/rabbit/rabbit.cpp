#include <cstdio>
#include <vector>
#include <cstring>
typedef long long intt;

const int MX = 110, P = 998244353;

struct edge
{
	int to, o;
};

std::vector <edge> G[MX];

namespace solve
{
inline int md(int x)
{
	return x >= P ? x - P : x;
}

inline void add(int& x, int y)
{
	x = md(x + y);
}

int qpow(int a, int p)
{
	int ret = 1;
	while (p)
	{
		if (p & 1)
			ret = (intt)ret * a % P;
		a = (intt)a * a % P;
		p >>= 1;
	}
	return ret;
}

namespace elim
{
template <typename T>
void elim(int n, int t, T& a)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
			if (a[j][i])
			{
				std::swap(a[j], a[i]);
				break;
			}
		for (int j = 1, x, inv = qpow(a[i][i], P - 2); j < i; j++)
		{
			x = (intt)a[j][i] * inv % P;
			for (int k = j; k <= n + t; k++)
				a[j][k] = ((intt)x * a[i][k] + P - a[j][k]) % P;
		}
		for (int j = i + 1, x, inv = qpow(a[i][i], P - 2); j <= n; j++)
		{
			x = (intt)a[j][i] * inv % P;
			for (int k = i; k <= n + t; k++)
				a[j][k] = ((intt)x * a[i][k] + P - a[j][k]) % P;
		}
	}
	for (int i = 1, inv; i <= n; i++)
	{
		inv = qpow(a[i][i], P - 2);
		a[i][i] = 1;
		for (int j = n + 1; j <= n + t; j++)
			a[i][j] = (intt)a[i][j] * inv % P;
	}
}
}

namespace acc
{
std::vector <int> G[MX];
bool acc[MX];

void DFS(int u)
{
	acc[u] = true;
	for (int v : G[u])
		if (not acc[v])
			DFS(v);
}

void run(int n, int t)
{
	for (int i = 1; i <= n; i++)
		for (edge& e : ::G[i])
#define v e.to
			if (e.o)
				G[v].push_back(i);
#undef v
	DFS(t);
}
}

int a[MX << 1][MX * 3], b[MX << 1][MX << 1], c[MX][MX], d[MX][MX];

std::pair <int, int> solve(int n, int s, int t)
{
	G[t].clear();
	for (int i = 1, inv; i <= n; i++)
	{
		a[i][i] = d[i][i] = 1;
		inv = qpow(G[i].size(), P - 2);
		for (edge& e : G[i])
		{
#define v e.to
			add(a[i][v + not e.o * n], P - inv);
			if (e.o)
				add(d[i][v], P - inv);
#undef v
		}
	}
	d[t][n + 1] = 1;
	for (int i = 1; i <= n; a[i + n][i + n] = a[i + n][i + (n << 1)] = 1, i++);
	elim::elim(n << 1, n, a);
	elim::elim(n, 1, d);
	acc::run(n, t);
	for (int i = 1, inv; i <= n; i++)
	{
		b[i][i] = b[i + n][i + n] = 1;
		if (acc::acc[i] and i != t)
		{
			inv = qpow(G[i].size(), P - 2);
			for (edge& e : G[i])
			{
#define v e.to
				if (e.o and acc::acc[v])
					add(b[i][v], P - inv),
					add(b[i][(n << 1) + 1], (intt)inv * d[v][n + 1] % P),
					add(b[i + n][v + n], P - inv);
					add(b[i + n][v], P - ((intt)inv * d[v][n + 1] << 1) % P),
					add(b[i + n][(n << 1) + 1], (intt)inv * d[v][n + 1] % P * d[v][n + 1] % P);
#undef v
			}
		}
	}
	elim::elim(n << 1, 1, b);
	for (int i = 1; i <= n; i++)
	{
		c[i][i] = 1;
		for (int j = 1; j <= n; j++)
			add(c[i][j], P - a[i][j + (n << 1)]);
		c[i][n + 1] = md(P - b[i][(n << 1) + 1]);
	}
	c[n + 1][n + 1] = c[n + 1][n + 2] = 1;
	elim::elim(n + 1, 1, c);
	int e = c[s][n + 2];
	memset(c, 0, sizeof(c));
	for (int i = 1; i <= n; i++)
	{
		c[i][i] = 1;
		for (int j = 1; j <= n; j++)
			add(c[i][j], P - a[i][j + (n << 1)]);
		c[i][n + 1] = md(P - b[i + n][(n << 1) + 1]);
	}
	c[n + 1][n + 1] = c[n + 1][n + 2] = 1;
	elim::elim(n + 1, 1, c);
	return { e, md(c[s][n + 2] + P - (intt)e * e % P) };
}
}

int main()
{
	freopen("rabbit.in", "r", stdin);
	freopen("rabbit.out", "w", stdout);
	int n, m, s, t, x, y, o;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	while (m--)
	{
		scanf("%d%d%d", &x, &y, &o);
		G[x].push_back({ y, o });
	}
	std::pair <int, int> ans = solve::solve(n, s, t);
	printf("%d %d", ans.first, ans.second);
}
