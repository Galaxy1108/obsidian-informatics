#include <cstdio>
#include <random>
#include <ctime>

std::mt19937 r(time(nullptr));

int main()
{
	freopen("xor.in", "w", stdout);
	int n = 1e3, V = 30;
	printf("%d\n", n);
	for (int i = 1; i <= n; i++)
		printf("%d ", r() & (1 << V) - 1);
}
