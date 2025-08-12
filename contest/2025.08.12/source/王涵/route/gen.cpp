#include <cstdio>

int main()
{
	freopen("route.in", "a", stdout);
	for (int i = 0; i < 3e6; i++)
	{
		printf("%d %d %lld\n", 0, 20, (long long)(i * 1e6));
	}
}
