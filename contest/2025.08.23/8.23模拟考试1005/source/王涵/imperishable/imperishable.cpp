#include <cstdio>
#define min(A, B) (A < B ? A : B)
#define minx(A, B) (A = min(A, B))

const int MX = 10, P = 998244353;

int a[MX];

namespace solve
{
int rr[MX], ans, tans, n;

template <typename F>
void DFS(int p, int x[], F f)
{
	if (p == n + 1)
	{
		bool fl = false;
		for (int i = 1; i <= n; i++)
			if (x[i])
			{
				fl = true;
				break;
			}
		if (fl)
			f();
	}
	else
	{
		int rrr = rr[p];
		for (int i = 0; i <= rrr; i++)
		{
			x[p] = i;
			rr[p] = rrr - x[p];
			DFS(p + 1, x, f);
		}
	}
}

int c(int x[])
{
	int p = 0, mx = 0;
	for (int i = 1; i <= n; i++)
		if (x[i] > mx)
			p = i,
			mx = x[i];
	return 1 << p;
}

void DFS()
{
	bool fl = true;
	for (int i = 1; i <= n; i++)
		if (rr[i])
		{
			fl = false;
			break;
		}
	if (fl)
	{
		minx(ans, tans);
	}
	else
	{
		int x[MX];
		DFS(1, x, [&x]()
		{
			int t = c(x);
			tans += t;
			DFS();
			tans -= t;
		});
	}
}

int solve(int n)
{
	solve::n = n;
	for (int i = 1; i <= n; rr[i] = a[i], i++);
	ans = 1e9;
	tans = 0;
	DFS();
	return ans;
}
}

int main()
{
	freopen("imperishable.in", "r", stdin);
	freopen("imperishable.out", "w", stdout);
	int n, q;
	scanf("%*d%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	printf("%d\n", solve::solve(n));
	scanf("%d", &q);
	while (q--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x] = y;
		printf("%d\n", solve::solve(n));
	}
}
