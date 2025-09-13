#include <cstdio>
#include <queue>
#include <cstring>
#define max(A, B) (A < B ? B : A)
#define maxx(A, B) (A = max(A, B))
#define swap(A, B) (A ^= B ^= A ^= B)
typedef long long intt;

intt read()
{
	char c = getchar();
	while (c < '0' or '9' < c)
		c = getchar();
	intt ret = 0;
	while ('0' <= c and c <= '9')
		ret = (ret << 3) + (ret << 1) + c - '0',
		c = getchar();
	return ret;
}

const int MX = 100010;

intt a[MX];

namespace solve
{
intt solve(int n)
{
	intt ret = 0;
	std::priority_queue <std::pair <intt, int>, std::vector <std::pair <intt, int> >, std::greater <std::pair <intt, int> > > q;
	for (int i = 1; i < n; i++)
		q.push({ a[i] + a[i + 1], i });
	while (not q.empty())
	{
		int p = q.top().second;
		intt s = q.top().first;
		q.pop();
		if (s != a[p] + a[p + 1] or a[p] >= a[p + 1])
			continue;
		else if (a[p + 1] - a[p] == 1)
			return -1;
		
		maxx(ret, s);
		
		swap(a[p], a[p + 1]);
		a[p]--; a[p + 1]++;
		if (p - 1)
			q.push({ a[p - 1] + a[p], p - 1 });
		if (p < n)
			q.push({ a[p + 1] + a[p + 2], p + 1 });
	}
	return ret;
}
}

int main()
{
	freopen("jyrg.in", "r", stdin);
	freopen("jyrg.out", "w", stdout);
	int t = read(), n;
	while (t--)
	{
		n = read();
		for (int i = 1; i <= n; a[i++] = read());
		printf("%lld\n", solve::solve(n));
	}
}
