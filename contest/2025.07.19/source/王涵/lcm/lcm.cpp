#include <cstdio>
typedef long long intt;

const int MX = 100010, P = 998244353;

namespace solve
{
int a[MX], n, k, ret;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

void DFS(int p)
{
	if (not p)
	{
		int lcm = 1;
		for (int i = 1; i <= k; i++)
		{
			lcm = lcm * a[i] / gcd(lcm, a[i]);
		}
		ret = (intt)ret * lcm % P;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			a[p] = i;
			DFS(p - 1);
		}
	}
}

int solve(int n, int k)
{
	solve::n = n;
	solve::k = k;
	ret = 1;
	DFS(k);
	return ret;
}
}

int main()
{
	freopen("lcm.in", "r", stdin);
	freopen("lcm.out", "w", stdout);
	int t, n, k;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &k);
		printf("%d\n", solve::solve(n, k));
	}
}
