#include <cstdio>
#include <vector>
#include <unordered_set>
#include <algorithm>
#define min(A, B) (A < B ? A : B)
typedef long long intt;

const int MX = 310, P = 1e9 + 7;

int a[MX << 1];

namespace solve
{
const int M = 19491001, B = 1145141;

bool vis[M];

std::vector <int> vec, pos;

int solve(int n)
{
	static bool in[MX];
	for (int i = 1; i <= n << 1; i++)
		if (not ~a[i])
			pos.push_back(i);
		else
			in[a[i]] = true;
	for (int i = 1; i <= n << 1; i++)
		if (not in[i])
			vec.push_back(i);
	int ret = 0;
	do
	{
		for (int i = 0; i < vec.size(); i++)
			a[pos[i]] = vec[i];
		int h = 0;
		for (int i = 1; i <= n; i++)
			h = ((intt)h * B + min(a[(i << 1) - 1], a[i << 1])) % M;
		if (not vis[h])
			vis[h] = true,
			ret++;
	} while (std::next_permutation(vec.begin(), vec.end()));
	return ret;
}
}

int main()
{
	freopen("permutation.in", "r", stdin);
	freopen("permutation.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n << 1; scanf("%d", a + i++));
	printf("%d", solve::solve(n));
}
