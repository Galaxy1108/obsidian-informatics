#include <cstdio>
#include <random>
#include <ctime>
#include <set>

std::mt19937 r(time(nullptr));
std::set <std::pair <int, int> > st;

int main()
{
	freopen("corridor.in", "w", stdout);
	int n = 50000, m = 50000, k = 100000, q = 50000;
	printf("0 %d %d %d\n", n, m, k);
	while (k--)
	{
tt:
		int x = r() % n + 1, y = r() % m + 1;
		if (not st.count({ x, y }))
			st.insert({ x, y });
		else goto tt;
		printf("%d %d\n", x, y);
	}
	printf("%d\n", q);
	while (q--)
	{
		printf("%d %d %d %d\n", 2, 0, r() % m + 1, r() % (150000 / 5) + 1);
	}
}
