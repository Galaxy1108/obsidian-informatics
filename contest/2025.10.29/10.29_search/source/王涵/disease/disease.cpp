#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <random>
#include <ctime>
#define min(A, B) (A < B ? A : B)
#define INF 1e9

inline void minx(int& a, int b)
{
	a = min(a, b);
}

const int MX = 310;
const double TL = 0.95;

std::vector <int> T[MX];

namespace solve
{
int fa[MX], siz[MX];

namespace SA
{
bool pr(double p)
{
	static std::mt19937 r(time(nullptr));
	return r() <= p * INT32_MAX;
}

int SA()
{
	std::vector <int> vec(1, 1), v;
	std::vector <std::pair <int, int> > tv;
	int ret = 0;
	while (not vec.empty())
	{
		ret += vec.size();
		v.clear();
		for (int u : vec)
		{
			tv.clear();
			for (int v : T[u])
				if (v != fa[u])
					tv.push_back({ siz[v], v });
			std::sort(tv.begin(), tv.end(), std::greater <> ());
			bool fl = false;
			for (auto pr : tv)
			{
				if (fl or SA::pr(1 / 2.71))
					v.push_back(pr.second);
				else
					fl = true;
			}
			if (not fl and not tv.empty())
				v.pop_back();
		}
		vec.swap(v);
	}
	return ret;
}
}

void DFS(int u)
{
	siz[u] = 1;
	for (int v : T[u])
		if (v != fa[u])
			fa[v] = u,
			DFS(v),
			siz[u] += siz[v];
}

int solve()
{
	DFS(1);
	int ret = INF;
	while ((double)clock() / CLOCKS_PER_SEC < TL)
		minx(ret, SA::SA());
	return ret;
}
}

int main()
{
	freopen("disease.in", "r", stdin);
	freopen("disease.out", "w", stdout);
	int n;
	scanf("%d%*d", &n);
	for (int i = 1, u, v; i < n; scanf("%d%d", &u, &v), T[u].push_back(v), T[v].push_back(u), i++);
	printf("%d", solve::solve());
}
