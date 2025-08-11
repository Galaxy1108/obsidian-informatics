#include <cstdio>
#include <random>
#include <ctime>

std::mt19937 r(time(nullptr));
bool vis[100];int V = 1e2;
int main()
{
	freopen("bus.in", "w", stdout);
	int t = r() % 100 + 10, n = 3, m = 5, w = r() % 10 + 1, x = 10;
	printf("%d %d %d %d %d\n", t, n, m, w, x);
	for (int i = 1; i <= n; i++)
	{
A:
		int xx = r() % x;
		if (not xx or xx % x == t % x or vis[xx])
		{
			goto A;
		}
		vis[xx] = true;
		printf("%d ", xx + r() % (t / x) * x);
	}
	putchar('\n');
	for (int i = 1; i <= m; i++)
	{
		
B:
		int xx = r() % x;
		if (not xx or xx % x == t % x or vis[xx])
		{
			goto B;
		}
		vis[xx] = true;
		printf("%d %d\n", xx, r() % V);
	}
}
