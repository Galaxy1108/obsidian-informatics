#include <cstdio>
#include <cstring>
#define min(A, B) ((A) < (B) ? A : B)
#define abs(x) (x < 0 ? -(x) : x)
#define INF 1e18
typedef long long intt;

const int MX = 200010;

int a[MX];

namespace solve
{
intt f[2][4][2];

intt solve(int n)
{
	memset(f[0], 0x3f, sizeof(f[0]));
	f[0][0][0] = 0;
	for (int i = 1, p; i <= n + 1; i++)
	{
		p = i & 1;
#define m(i) (min(f[p ^ 1][i][0], f[p ^ 1][i][1]))
#define f(i, j) (f[p ^ 1][i][j])
		f[p][0][0] = f(0, 0) + a[i];
		f[p][0][1] = min(min(m(0), m(1)), min(m(2), m(3))) + a[i];
		f[p][1][0] = min(min(f(0, 0), f(1, 0)), min(f(2, 0), f(3, 0))) + abs(a[i] - 2);
		f[p][1][1] = min(min(f(1, 1), f(2, 1)), f(3, 1)) + abs(a[i] - 2);
		if (not a[i])
			f[p][2][0] = f[p][2][1] = INF;
		else if (a[i] & 1)
			f[p][2][0] = min(min(f(0, 0), f(1, 0)), min(f(2, 0), f(3, 0))) + 1,
			f[p][2][1] = min(min(f(1, 1), f(2, 1)), f(3, 1)) + 1;
		else
			f[p][2][0] = INF,
			f[p][2][1] = min(min(a[i - 1] & 1 ? INF : f(2, 1), a[i - 1] & 1 ? f(3, 1) : INF), min(min(f(0, 0), f(1, 0)), min(f(2, 0), f(3, 0)))) + 1;
		if (a[i] & 1)
			f[p][3][0] = INF,
			f[p][3][1] = min(min(a[i - 1] & 1 ? INF : f(2, 1), a[i - 1] & 1 ? f(3, 1) : INF), min(min(f(0, 0), f(1, 0)), min(f(2, 0), f(3, 0))));
		else
			f[p][3][0] = min(min(f(0, 0), f(1, 0)), min(f(2, 0), f(3, 0))),
			f[p][3][1] = min(min(f(1, 1), f(2, 1)), f(3, 1));
#undef m
#undef f
	}
	return f[n & 1 ^ 1][0][1];
}
}

int main()
{
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; scanf("%d", a + i++));
	printf("%lld", solve::solve(n));
}
