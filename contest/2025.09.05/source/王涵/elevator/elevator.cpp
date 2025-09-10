#include <cstdio>
#include <unordered_map>
#include <set>
#include <vector>
#define min(A, B) (A < B ? A : B)
#define max(A, B) (A < B ? B : A)
#define abs(x) (x < 0 ? -(x) : x)
#define lg(x) (31 - __builtin_clz(x))
#define lowbit(x) (x & -x)
#define INF 1e9

inline void minx(int& a, int b)
{
	a = min(a, b);
}

const int MX = 2010, F = 9, C = 4;

int a[MX], b[MX];

namespace solve
{
const int W = 3;

std::unordered_map <int, int> f[MX];

#define gt(s, p) (s >> W * p & (1 << W) - 1)
#define pt(x, p) (x << W * p)
#define o(p) (1 << W * p)

inline void minx(std::unordered_map <int, int>& f, int p, int x)
{
	if (not f.count(p) or f[p] > x)
		f[p] = x;
}

int solve(int n)
{
	f[0].insert({ 0, 0 });
	for (int i = 1; i <= n; i++)
	{
		a[i]--; b[i]--;
		for (auto pr : f[i - 1])
		{
			int cnt = 0, s = 0;
			for (int i = 0; i < F; i++)
			{
				cnt += gt(pr.first, i);
				s |= (bool)gt(pr.first, i) << i;
			}
			if (cnt < C and a[i] == a[i - 1])
				minx(f[i], pr.first + o(b[i]), pr.second);
			else
			{
				for (int t = s; ; --t &= s)
				{
					if (not gt(pr.first, a[i]) or (t & 1 << a[i]))
					{
						int to = pr.first, tot = 0;
						for (int tt = t; tt; tt -= lowbit(tt))
							to -= pt(gt(pr.first, __builtin_ctz(tt)), __builtin_ctz(tt)),
							tot -= gt(pr.first, __builtin_ctz(tt));
						if (cnt + tot < C)
							minx(f[i], to + o(b[i]), pr.second + (t ? (max(lg(t), max(a[i], a[i - 1])) - min(__builtin_ctz(t), min(a[i], a[i - 1])) << 1) - abs(a[i] - a[i - 1]) : abs(a[i] - a[i - 1])));
					}
					if (not t)
						break;
				}
			}
		}
	}
	int ret = INF;
	for (auto pr : f[n])
	{
		int s = 0;
		for (int i = 0; i < F; i++)
			s |= (bool)gt(pr.first, i) << i;
		
		::minx(ret, pr.second + max(lg(s), a[n]) - min(__builtin_ctz(s), a[n]) + min(max(lg(s), a[n]) - a[n], a[n] - min(__builtin_ctz(s), a[n])));
	}
	return ret + (n << 1);
}

#undef gt
#undef pt
#undef o
}

int main()
{
	freopen("elevator.in", "r", stdin);
	freopen("elevator.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; scanf("%d%d", a + i, b + i), i++);
	printf("%d", solve::solve(n));
}
