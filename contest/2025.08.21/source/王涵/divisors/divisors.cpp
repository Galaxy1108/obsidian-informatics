#include <cstdio>

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	freopen("divisors.in", "r", stdin);
	freopen("divisors.out", "w", stdout);
	int n;
	scanf("%d", &n);
	int lcm = 1;
	for (int i = 2; i <= n; i++)
	{
		lcm = lcm * i / gcd(lcm, i);
	}
	printf("%d ", lcm);
	for (int i = 2; i <= n; i++)
		printf("%d ", i);
	putchar('\n');
	for (int i = 2; i <= n; i++)
	{
		printf("%d %d\n", 1, i);
	}
}
