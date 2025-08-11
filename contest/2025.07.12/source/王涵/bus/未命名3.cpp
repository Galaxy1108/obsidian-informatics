#include <cstdio>
#include <algorithm>
#include <cstring>
typedef long long intt;

const int MX = 200010, MXT = MX;

struct node
{
	intt d;
	int c;
} p[MX];

intt s[MX];

namespace solve
{
int n, m;
bool fl[MXT], fl1[MXT];
int ex[MXT], del[MXT];

intt DFS(intt x, int w, intt t, int st)
{
	memset(fl, 0, sizeof(fl));
	memset(fl1, 0, sizeof(fl1));
	memset(ex, 0, sizeof(ex));
	memset(del, 0, sizeof(del));
	intt ret = 0;
	for (int i = 0; i <= x; i++)
	{
		if (i % t == 0)
		{
			fl[i] = true;
			ex[i] = -1;
		}
		for (int j = 1; j <= m; j++)
		{
			if (st & (1 << (j - 1)))
			{
				if (i % t == p[j].d)
				{
					fl[i] = true;
					ex[i] = j;
					break;
				}
			}
			if (i % t == p[j].d)
				{
					ex[i] = j;
				}
		}
	}
	s[n + 1] = x + 1;
//	if (st == 31)
//	{
//		fprintf(stderr, "");
//	}
	for (int i = 0; i <= n; i++)
	{
		bool xxx = false;
		int cnt = 0;
		for (int j = s[i + 1] - 1; j >= s[i]; j--)
		{
			if (fl[j])
			{
				xxx = true;
			}
			if (ex[j] and not del[ex[j]] and not fl[j] and not xxx)
			{
				del[ex[j]] = -j;
			}
			if (ex[j] and del[ex[j]] <= 0 and xxx)
			{
				cnt++;
				//fprintf(stderr, "%d\n", ex[j]);
			}
		}//fprintf(stderr, "\n");
		for (int i = 1; i <= m; i++) if (del[i] < 0) del[i] = -del[i];
		ret += (intt)w * cnt;
	}
	for (int i = 1; i <= m; i++)
	{
		if (not (st & (1 << (i - 1))))
		{
			if (not del[i]) return 1e18;
			ret += p[i].c;
		}
	}
	return ret;
}

intt solve(intt x, int n, int m, int w, intt t)
{
	std::sort(s + 1, s + n + 1);
	solve::n = n;
	solve::m = m;
	intt ret = 1e18, tt;
	for (int st = 0; st < 1 << m; st++)
	{
		tt = DFS(x, w, t, st);
		if (tt < ret)
		{
			ret = tt;
		}
	}
	return ret;
}
}

int main()
{
	freopen("bus.in", "r", stdin);
	freopen("bus.ans", "w", stdout);
	intt x, t;
	int n, m, w;
	scanf("%lld%d%d%d%lld", &x, &n, &m, &w, &t);
	for (int i = 1; i <= n; scanf("%lld", s + i++));
	for (int i = 1; i <= m; scanf("%lld%d", &p[i].d, &p[i].c), i++);
	printf("%lld", solve::solve(x, n, m, w, t));
}
