#include <cstdio>
#include <unordered_map>
#include <cstring>
#define min(A, B) (A < B ? A : B)
#define minx(A, B) (A = min(A, B))
#define INF 1e9
#define INFF 1e18
typedef long long intt;

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

const int MX = 2010, N = 8;

int w[MX][MX];

namespace solve
{
namespace mst
{
std::unordered_map <int, intt> f[1 << N];
int dis[MX];

intt prim(int n, int s)
{
	f[1 << (s - 1)].insert({ INF, 0 });
	for (int ss = 0; ss < 1 << n; ss++)
	{
		memset(dis, 0x3f, sizeof(dis));
		for (int i = 1; i <= n; i++)
			if (ss & (1 << (i - 1)))
				for (int j = 1; j <= n; j++)
					minx(dis[j], w[i][j]);
		for (auto pr : f[ss])
		{
			for (int x = 1; x <= n; x++)
			{
				if (not (ss & (1 << (x - 1))))
				{
					if (not f[ss | (1 << (x - 1))].count(min(pr.first, dis[x])))
						f[ss | (1 << (x - 1))].insert({ min(pr.first, dis[x]), pr.second + min(pr.first, dis[x]) });
					else
						minx(f[ss | (1 << (x - 1))][min(pr.first, dis[x])], pr.second + min(pr.first, dis[x]));
				}
			}
		}
	}
	intt ret = INFF;
	for (auto pr : f[(1 << n) - 1])
		minx(ret, pr.second);
	for (int i = 0; i < 1 << n; i++)
		f[i].clear();
	return ret;
}
}

intt ans[MX];

void solve(int n)
{
	for (int i = 1; i <= n; i++)
		ans[i] = mst::prim(n, i);
}
}

namespace solve1
{
intt ans[MX];
bool vis[MX];

void solve(int n)
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (w[i][j] == 1)
				vis[i] = vis[j] = true;
	for (int i = 1; i <= n; i++)
		if (vis[i])
			ans[i] = n - 1;
		else
			ans[i] = (int)1e9 + n - 2;
}
}

namespace solve2
{
intt ans[MX];

namespace mst
{
intt dis[MX];
bool vis[MX];
int mnw;

intt prim(int n, int s)
{
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	intt ret = INFF, tot = 0, mw = INFF;
	for (int i = 1; i <= n; i++)
	{
		int u = 0;
		intt mn = INFF;
		for (int x = 1; x <= n; x++)
			if (not vis[x] and dis[x] < mn)
				u = x,
				mn = dis[x];
		if (not u)
			u = s;
		
		vis[u] = true;
		tot += (u != s) * dis[u];
		mw = min(mw, dis[u]);
		if (i < n)
			minx(ret, tot + mw + (intt)(n - i - 1) * mnw);
		else
			minx(ret, tot);
		
		if (i == n)
			break;
		
		for (int x = 1; x <= n; x++)
			if (not vis[x] and dis[x] > w[u][x])
				dis[x] = w[u][x];
	}
	return ret;
}
}

void solve(int n)
{
	mst::mnw = INF;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j)
				minx(mst::mnw, w[i][j]);
	for (int i = 1; i <= n; i++)
		ans[i] = mst::prim(n, i);
}
}

int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int n = read();
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			w[i][j] = w[j][i] = read();
	if (n <= 8)
		solve::solve(n);
	else if (n <= 300)
		solve2::solve(n);
	else
		solve1::solve(n);
	for (int i = 1; i <= n; i++)
		printf("%lld\n", n <= 8 ? solve::ans[i] : n <= 300 ? solve2::ans[i] : solve1::ans[i]);
}
