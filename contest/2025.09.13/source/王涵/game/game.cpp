#include <cstdio>
#include <cstring>
#define swap(A, B) (A ^= B ^= A ^= B)
#define lg(x) (31 - __builtin_clz(x))
typedef long long intt;

const int N = 1000000, MX = N + 10, P = 998244353;

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

inline void add(int& x, intt y)
{
	x = (x + y) % P;
}

namespace sieve
{
bool npri[MX];
int pri[MX], tot, phi[MX];

void sieve(int n)
{
	phi[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (not npri[i])
			pri[++tot] = i,
			phi[i] = i - 1;
		for (int j = 1; j <= tot and i * pri[j] <= n; j++)
		{
			npri[i * pri[j]] = true;
			if (i % pri[j])
				phi[i * pri[j]] = (intt)phi[i] * phi[pri[j]] % P;
			else
			{
				phi[i * pri[j]] = (intt)phi[i] * pri[j] % P;
				break;
			}
		}
	}
}
}

int k, f[MX], inv[MX];

void init(int k)
{
	solve::k = k;
	sieve::sieve(N);
	inv[1] = 1;
	for (int i = 2; i <= N; inv[i] = (intt)(P - P / i) * inv[P % i] % P, i++);
	f[0] = 1;
	for (int i = 1; i <= N; i++)
	{
		f[i] = md(f[i - 1] << 1);
		if (i - 2 >= 0)
			add(f[i], P - f[i - 2]);
		if (i - k - 1 >= 0)
			add(f[i], f[i - k - 1]);
		if (i - k - 2 >= 0)
			add(f[i], P - f[i - k - 2]);
	}
}

int qw(int n)
{
	if ((n -= k + 1) < 0)
		return 0;
	else
		return ((intt)(1 + k) * f[n] + (intt)(P - k) * (n ? f[n - 1] : 0)) % P;
}

int qm(int n)
{
	using sieve::phi;
	int ret = 0;
	for (int i = 1; i * i <= n; i++)
	{
		if (not (n % i))
		{
			add(ret, (intt)qw(i) * phi[n / i]);
			if (i * i != n)
				add(ret, (intt)qw(n / i) * phi[i]);
		}
	}
	return (intt)ret * inv[n] % P;
}
}

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int k, t, n;
	scanf("%d%d", &k, &t);
	solve::init(k);
	while (t--)
	{
		scanf("%d", &n);
		printf("%d %d\n", solve::qw(n), solve::qm(n));
	}
}
