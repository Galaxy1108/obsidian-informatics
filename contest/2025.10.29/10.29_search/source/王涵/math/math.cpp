#include <cstdio>
#define max(A, B) (A < B ? B : A)
#define abs(x) (x < 0 ? -(x) : x)

const int MX = 1010;
const double EPS = 1e-9;

bool nn(double x)
{
	return abs(x) > EPS;
}

bool ge(double a, double b)
{
	return a - b >= -EPS;
}

namespace solve
{
int ans[MX];

bool DFS(int d, int p, double r)
{
	if (p > d)
		return not nn(r);
	else
	{
		for (int i = max(ans[p - 1] + 1, 1 / r); ge((double)(d - p + 1) / i, r); i++)
			if (ge(r, 1.0 / i))
			{
				ans[p] = i;
				if (DFS(d, p + 1, r - 1.0 / i))
					return true;
			}
		return false;
	}
}

int solve(int a, int b)
{
	int d = 1;
	for (; not DFS(d, 1, (double)a / b); d++);
	return d;
}
}

int main()
{
	freopen("math.in", "r", stdin);
	freopen("math.out", "w", stdout);
	int a, b;
	scanf("%d%d", &a, &b);
	int ans = solve::solve(a, b);
	printf("%d\n", ans);
	for (int i = 1; i <= ans; printf("%d ", solve::ans[i++]));
}
