#include <cstdio>
#include <algorithm>
typedef long long intt;

const int MX = 5010, P = 1e9 + 7;

int a[MX];

namespace solve
{
inline int md(int x)
{
	return x >= P ? x - P : x;
}

inline void add(int& x, int y)
{
	x = md(x + y);
}

int qpow(int a, int p)
{
	int ret = 1;
	while (p)
	{
		if (p & 1)
			ret = (intt)ret * a % P;
		a = (intt)a * a % P;
		p >>= 1;
	}
	return ret;
}

namespace num
{
int S[MX][MX], inv[MX];

void init(int n)
{
	inv[1] = 1;
	for (int i = 2; i <= n; inv[i] = (intt)(P - P / i) * inv[P % i] % P, i++);
	S[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			S[i][j] = (S[i - 1][j - 1] + (intt)j * S[i - 1][j]) % P;
}
}

int pws(int n, int k)
{
	int ret = 0;
	for (int i = 0, pw = n + 1; i <= k; pw = (intt)pw * (n - i++) % P)
		add(ret, (intt)num::S[k][i] * pw % P * num::inv[i + 1] % P);
	return ret;
}

int pws(int l, int r, int k)
{
	return md(pws(r, k) + P - pws(l - 1, k));
}

int solve(int n)
{
	num::init(n + 1);
	std::sort(a + 1, a + n + 1);
	int sum = 0;
	for (int i = n, pd = 1; i; i--)
	{
		pd = (intt)pd * qpow(a[i], P - 2) % P;
		add(sum, (intt)pd * pws(a[i - 1] + 1, a[i], n - i + 1) % P);
	}
	return md(a[n] + 1 + P - sum);
}
}

int main()
{
	freopen("dice.in", "r", stdin);
	freopen("dice.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; scanf("%d", a + i++));
	printf("%d", solve::solve(n));
}
