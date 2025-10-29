#include <cstdio>
typedef long long intt;

int read()
{
	char c = getchar();
	while (c < '0' or '9' < c)
		c = getchar();
	int ret = 0;
	while ('0' <= c and c <= '9')
		ret = (ret << 3) + (ret << 1) + c - '0',
		c = getchar();
	return ret;
}

const int MX = 1000010, V = 1000000;

int a[MX];

namespace solve
{
int sc[MX];

intt solve(int n)
{
	for (int i = 1; i <= n; sc[a[i++]]++);
	for (int i = V; i; sc[i] += sc[i + 1], i--);
	intt ret = 0;
	for (int d = 1; d <= V; d++)
	{
#define s(i) (sc[(i) * d] - ((i + 1) * d <= V ? sc[(i + 1) * d] : 0))
		int cc = s(1) & 1, s = 0;
		for (int i = 2; i * d <= V; i++)
			cc += s(i) & 1,
			s += (s(i) & 1 and s(i - 1) & 1) * s(i);
		ret += (cc == 2) * s + (cc == 1) * (s(1) & 1) * s(1);
#undef s
	}
	return ret;
}
}

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int n = read();
	for (int i = 1; i <= n; a[i++] = read());
	printf("%lld", solve::solve(n));
}
