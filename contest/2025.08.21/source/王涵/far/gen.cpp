#include <cstdio>
#include <random>
#include <ctime>

int main()
{
	freopen("far.in", "w", stdout);
	int n = 60, m = 60;
	printf("%d %d\n", n, m);
	std::mt19937_64 r(time(nullptr));
	for (int i = 1; i <= n; i++)
	{
		long long l = r() % (1ll << m), rr = r() % (1ll << m);
		if (l > rr)
			std::swap(l, rr);
		printf("%lld %lld\n", l, rr);
	}
}
