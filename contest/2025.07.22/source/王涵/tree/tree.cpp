#include <cstdio>
#include <cstring>
#define max(A, B) (A < B ? B : A)
typedef long long intt;

const int MX = 5010, P = 998244353;

int l[MX], r[MX];

namespace solve
{
inline void md(int& x)
{
	x -= (x >= P) * P;
}

int wei[MX], pu[MX], pv[MX], inv[MX], n;

void init(int n)
{
	solve::n = n;
	inv[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		inv[i] = (intt)(P - P / i) * inv[P % i] % P;
	}
}

void add(int p[], int u)
{
	static int diff[MX];
	diff[u] = 1;
	diff[u - 1] = P - 1;
	for (int i = u; i; i--)
	{
		md(p[i] = p[i + 1] + diff[i]);
		diff[i] = 0;
		md(diff[r[i]] += (intt)p[i] * inv[r[i] - l[i] + 1] % P);
		md(diff[l[i] - 1] += P - (intt)p[i] * inv[r[i] - l[i] + 1] % P);
	}
}

namespace DP
{
int f[MX][MX], diff[MX][MX], p[MX];

void add(int u, int v, int w)
{
	md(diff[u][v] += w);
	md(diff[u - 1][v] += P - w);
	md(diff[u][v - 1] += P - w);
	md(diff[u - 1][v - 1] += w);
}

void DP(int n)
{
	for (int i = n; i; i--)
	{
		for (int j = n; j; j--)
		{
			f[i][j] = diff[i][j];
			md(f[i][j] += f[i + 1][j]);
			md(f[i][j] += f[i][j + 1]);
			md(f[i][j] += P - f[i + 1][j + 1]);
			if (i != j)
			{
				if (i < j)
				{
					md(diff[i][r[j]] += (intt)f[i][j] * inv[r[j] - l[j] + 1] % P);
					md(diff[i][l[j] - 1] += P - (intt)f[i][j] * inv[r[j] - l[j] + 1] % P);
					md(diff[i - 1][r[j]] += P - (intt)f[i][j] * inv[r[j] - l[j] + 1] % P);
					md(diff[i - 1][l[j] - 1] += (intt)f[i][j] * inv[r[j] - l[j] + 1] % P);
				}
				if (j < i)
				{
					md(diff[r[i]][j] += (intt)f[i][j] * inv[r[i] - l[i] + 1] % P);
					md(diff[l[i] - 1][j] += P - (intt)f[i][j] * inv[r[i] - l[i] + 1] % P);
					md(diff[r[i]][j - 1] += P - (intt)f[i][j] * inv[r[i] - l[i] + 1] % P);
					md(diff[l[i] - 1][j - 1] += (intt)f[i][j] * inv[r[i] - l[i] + 1] % P);
				}
			}
		}
		md(p[i] += f[i][i]);
		md(p[i - 1] += P - f[i][i]);
	}
	for (int i = n; i; i--)
	{
		md(p[i] += p[i + 1]);
		md(p[r[i]] += (intt)p[i] * inv[r[i] - l[i] + 1] % P);
		md(p[l[i] - 1] += P - (intt)p[i] * inv[r[i] - l[i] + 1] % P);
	}
	for (int i = 1; i <= n; i++)
	{
		md(wei[i] += ((P << 1) - (p[i] << 1)) % P);
	}
}
}


void add(int u, int v, int w)
{
	add(pu, u);
	add(pv, v);
	DP::add(u, v, w);
	for (int i = 1; i <= u or i <= v; i++)
	{
		md(wei[i] += (intt)(pu[i] + pv[i]) * w % P);
	}
	memset(pu + 1, 0, sizeof(int) * u);
	memset(pv + 1, 0, sizeof(int) * v);
}

void solve()
{
	DP::DP(n);
}

int query(int u)
{
	return wei[u];
}
}

int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	int n, m, u, v, w;
	scanf("%d", &n);
	for (int i = 2; i <= n; scanf("%d%d", l + i, r + i), i++);
	solve::init(n);
	scanf("%d", &m);
	while (m--)
	{
		scanf("%d%d%d", &u, &v, &w);
		if (w %= P)
			solve::add(u, v, w);
	}
	solve::solve();
	for (int i = 2; i <= n; i++)
	{
		printf("%d ", solve::query(i));
	}
}
