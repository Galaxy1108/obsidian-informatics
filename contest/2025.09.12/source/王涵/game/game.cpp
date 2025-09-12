#include <cstdio>
#include <algorithm>
#include <cstring>
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

const int MX = 200010;

intt w[MX];

namespace solve
{
intt solve(int n)
{
	std::sort(w + 1, w + n + 1, std::greater <intt>());
	intt ret = 0;
	for (int i = 1; i <= n; i++)
		ret += i & 1 ? w[i] : -w[i];
	return ret >> 1;
}
}

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int t = read(), n, m, u, v, w;
	while (t--)
	{
		n = read(); m = read();
		while(m--)
			u = read(), v = read(), w = read(),
			::w[u] += w, ::w[v] += w;
		printf("%lld\n", solve::solve(n));
		memset(::w + 1, 0, sizeof(intt) * n);
	}
}
