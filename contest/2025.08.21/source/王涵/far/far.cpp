#include <cstdio>
#include <unordered_map>
typedef long long intt;

const int MX = 45, MXM = 65, P = 998244353;

intt l[MX], r[MX];

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

namespace pw
{
int pw[MXM];

void init(int n)
{
	pw[0] = 1;
	for (int i = 1; i <= n; pw[i] = md(pw[i - 1] << 1), i++);
}
}

struct num
{
	intt x;
	int s;
	
	bool isnull() const
	{
		return not x;
	}
	
	bool operator== (num oth) const
	{
		return x == oth.x and s == oth.s;
	}
};

struct rnum
{
	int x, s, p;
};

int m;

namespace sgt
{
template <typename F>
void update(intt l, intt r, const F& f, num pt = { 0, m })
{
	if (l <= pt.x and (pt.x | ((1ll << pt.s) - 1)) <= r)
		f(pt);
	else
	{
		if (l < (pt.x | 1ll << (pt.s - 1)))
			update(l, r, f, { pt.x, pt.s - 1 });
		if ((pt.x | 1ll << (pt.s - 1)) <= r)
			update(l, r, f, { pt.x | 1ll << (pt.s - 1), pt.s - 1 });
	}
}
}

rnum to(num x)
{
	if (x.s >= m >> 1)
		return { 0, m >> 1, pw::pw[x.s - (m >> 1)] };
	else
	{
		int tx = x.x & ((1 << (m >> 1)) - 1);
		for (int z = (m + 1) >> 1; z < m and (m >> 1) - (z - ((m + 1) >> 1)) > x.s; z++)
			tx ^= (bool)(x.x & (1ll << z)) << ((m >> 1) - (z - ((m + 1) >> 1)) - 1);
		return { tx, x.s, 1 };
	}
}

struct hash
{
	unsigned long long operator() (num x) const
	{
		return (unsigned long long)x.x + ((unsigned long long)x.s << (m >> 1));
	}
};

typedef std::unordered_map <num, int, hash> ft;

void trans(const ft& f, ft& g, rnum x)
{
	for (auto pr : f)
	{
		if (x.s <= pr.first.s)
		{
			num to = { x.x & (-1 ^ ((1 << pr.first.s) - 1)) ^ pr.first.x, pr.first.s };
			add(g[to], (intt)x.p % P * pw::pw[x.s] % P * pr.second % P);
		}
		else
		{
			num to = { x.x ^ pr.first.x & (-1 ^ ((1 << x.s) - 1)), x.s };
			add(g[to], (intt)x.p % P * pw::pw[pr.first.s] % P * pr.second % P);
		}
	}
}

ft f[2];
int ans[MX];

void solve(int n, int m)
{
	solve::m = m;
	pw::init(m);
	f[0][{ 0, 0 }] = 1;
	for (int i = 1, p; i <= n; i++)
	{
		p = i & 1;
		f[p].clear();
		sgt::update(l[i], r[i], [&p](const num& x)
		{
			trans(f[p ^ 1], f[p], to(x));
		});
		for (auto pr : f[p])
			if (pr.first.isnull())
				add(ans[i], pr.second);
	}
}
}

int main()
{
	freopen("far.in", "r", stdin);
	freopen("far.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld%lld", l + i, r + i);
	solve::solve(n, m);
	for (int i = 1; i <= n; i++)
		printf("%d\n", solve::ans[i]);
}
