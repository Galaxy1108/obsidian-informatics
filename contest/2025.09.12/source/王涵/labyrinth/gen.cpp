#include <cstdio>
#include <random>
#include <ctime>

std::mt19937 r(time(nullptr));

int main()
{
	freopen("x.in", "w", stdout);
	int T = 100, N = 9;
	printf("%d\n", T);
	while (T--)
	{
		printf("%d\n", N);
		for (int i = 2; i <= N; i++)
			printf("%d %d\n", r() % (i - 1) + 1, i);
		putchar('\n');
	}
}
