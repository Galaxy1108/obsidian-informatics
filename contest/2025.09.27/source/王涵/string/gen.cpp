#include <cstdio>
#include <random>
#include <ctime>

std::mt19937 r(time(nullptr));

int main()
{
	freopen("string.in", "w", stdout);
	int c = 400;
	while (c--)
	{
		putchar('0' + r() % 3);
	}
}
