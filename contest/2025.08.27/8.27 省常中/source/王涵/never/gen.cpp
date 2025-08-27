#include <cstdio>
#include <random>
#include <ctime>

std::mt19937 r(time(nullptr));

int main()
{
	freopen("never.in", "w", stdout);
	printf("1\n");
	int V = 10;
	printf("5 %d %d %d %d\n", r() % V + 1, r() % V + 1, r() % V + 1, r() % V + 1);
}
