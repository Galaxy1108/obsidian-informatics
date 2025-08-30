#include <cstdio>
#include <random>
#include <ctime>

std::mt19937 r(time(nullptr));

const int V = 1e9 + 1;

int main()
{
	freopen("glyph.in", "w", stdout);
	printf("%d %d\n", 300, 200000);
	for (int i = 1; i <= 300; i++)
	{
		for (int j = 1; j <= 300; j++)
			printf("%d ", r() % V);
		printf("\n");
	}
	for (int i = 0; i < 200000; i++)
	{
		int rl = r() % 300 + 1, rr = r() % 300 + 1, cl = r() % 300 + 1, cr = r() % 300 + 1;
		if (rl > rr)
			std::swap(rl, rr);
		if (cl > cr)
			std::swap(cl, cr);
		printf("%d %d %d %d\n", rl, rr, cl, cr);
	}
}
