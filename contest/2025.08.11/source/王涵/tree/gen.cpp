#include <cstdio>
#include <random>
#include <ctime>

std::mt19937 r(time(nullptr));

const int N = 10, V = 10;

int main()
{
//	freopen("tree.in", "w", stdout);
	printf("%d\n", N);
	for (int i = 2; i <= N; printf("%d ", r() % (i++ - 1) + 1)); putchar('\n');
	for (int i = 1; i <= N; printf("%d ", r() % V + 1), i++);
}
