#include <cstdio>
#include <random>
#include <ctime>

std::mt19937 r(time(nullptr));

int main()
{
	freopen("truth.in", "w", stdout);
	int n = 5e4, k = 10;
	printf("%d %d 1\n", n, k);
	for (int i = 1; i <= n; printf("%d ", r() % k + 1), i++);
	printf("\n2");
}
