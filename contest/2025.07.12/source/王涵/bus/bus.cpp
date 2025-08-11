#include <cstdio>
#include <algorithm>
#include <cstring>
typedef long long intt;
typedef long long tt;

const int MX = 200010;

struct node
{
	intt d;
	int c;
} p[MX];

intt s[MX];

namespace solve
{
namespace disc
{
intt num[MX];

int q;

int upper(intt x)
{
	int l = 1, r = q + 1, mid;
	while (l < r)
	{
		mid = (l + r) >> 1;
		if (x <= num[mid])
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	return l;
}

int disc(int n)
{
	for (int i = 1; i <= n; num[i] = p[i].d, i++);
	q = std::unique(num + 1, num + n + 1) - num - 1;
	for (int i = 1; i <= n; i++)
	{
		p[i].d = std::lower_bound(num + 1, num + q + 1, p[i].d) - num;
	}
	return q;
}
}

namespace sgt
{
intt a[MX], k;
bool fl[MX];
int n;

void build(intt x, intt t, int w, int m)
{
	for (int i = 1; i <= m; a[p[i].d] += -p[i].c + (x / t + (disc::num[p[i].d] <= x % t)) * w, i++);
}

void add(intt x)
{
	k += x;
}

struct node
{
	tt val;
	int p;
};

void del(int l, int r)
{
	for (int i = l; i <= r; fl[i++] = true);
}

node query(int l, int r)
{
	node ret = { 0, r + 1 };
	tt sum = 0;
	for (int i = r; i >= l; i--)
	{
		if (not fl[i])
		{
			sum += a[i] + k;
			if (sum > ret.val)
			{
				ret = { sum, i };
			}
		}
	}
	return ret;
}
}

bool cmp(node& a, node& b)
{
	return a.d < b.d;
}

#define bk(i) (s[i] / t)

intt solve(intt x, int n, int m, int w, intt t)
{
	std::sort(p + 1, p + m + 1, cmp);
	std::sort(s + 1, s + n + 1);
	sgt::n = disc::disc(m);
	sgt::build(x, t, w, m);
	tt ret = (x / t + 1) * w;
	s[n + 1] = x;
	for (int i = 1; i <= m; ret += (x / t + (disc::num[p[i++].d] <= x % t)) * w);
	sgt::node nd;
	for (int i = 0, l, r = 0; i <= n; i++)
	{
		if (bk(i) != bk(i + 1)) sgt::add(-w * (bk(i + 1) - bk(i))), l = 1;
		else l = r + 1;
		r = disc::upper(s[i + 1] % t) - 1;
		if (l <= r)
		{
			nd = sgt::query(l, r);
			sgt::del(nd.p, r);
			ret -= nd.val;
		}
	}
	return ret;
}

#undef bk
}

namespace sss
{
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

void main(intt x, int n, int m, int w, intt t)
{
	for (int i = 1; i <= n; scanf("%lld", s + i++));
	for (int i = 1; i <= m; scanf("%lld%d", &p[i].d, &p[i].c), i++);
	printf("%lld", solve::solve(x, n, m, w, t));
}
}

int main()
{
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	intt x, t;
	int n, m, w;
	scanf("%lld%d%d%d%lld", &x, &n, &m, &w, &t);
	if (n <= 8)
	{
		sss::main(x, n, m, w, t);
		return 0;
	}
	for (int i = 1; i <= n; scanf("%lld", s + i++));
	for (int i = 1; i <= m; scanf("%lld%d", &p[i].d, &p[i].c), i++);
	printf("%lld", solve::solve(x, n, m, w, t));
}
