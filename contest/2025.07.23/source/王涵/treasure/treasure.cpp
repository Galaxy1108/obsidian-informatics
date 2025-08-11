#include <cstdio>
#include <array>
#include <vector>
#include <unordered_map>

const int MX = 210, K = 7, P = 1e9 + 7;

int b[MX];

namespace solve
{
struct hash
{
	unsigned long long operator() (const std::array <int, K - 1>& arr) const
	{
		unsigned long long ret = 0;
		for (int i = 0, pd = 1; i < K - 1; pd *= (++i + 1))
		{
			ret += arr[i] * pd;
		}
		return ret;
	}
};

std::unordered_map <std::array <int, K - 1>, int, hash> f[MX];
std::vector <int> ppc[K + 1];

int solve(int n, int k)
{
	f[0].insert({ {}, 1 });
	for (int i = 0; i < 1 << k; i++)
		ppc[__builtin_popcount(i)].push_back(i);
	for (int i = 1, sum; i <= n; i++)
	{
		for (auto pr : f[i - 1])
		{
			sum = 0;
			for (int i = 0; i < k - 1; sum += pr.first[i++]);
			if (b[i] >= sum and b[i] - sum <= k)
				for (int s : ppc[b[i] - sum])
				{
					auto st = pr.first;
					for (int j = k - 2; j; j--)
					{
						st[j] = st[j - 1] + (bool)(s & (1 << j));
					}
					st[0] = s & 1;
					(f[i][st] += pr.second) %= P;
				}
		}
	}
	int ret = 0;
	for (auto pr : f[n])
		(ret += pr.second) %= P;
	return ret;
}
}

int main()
{
	freopen("treasure.in", "r", stdin);
	freopen("treasure.out", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; scanf("%d", b + i++));
	printf("%d", solve::solve(n, k));
}
