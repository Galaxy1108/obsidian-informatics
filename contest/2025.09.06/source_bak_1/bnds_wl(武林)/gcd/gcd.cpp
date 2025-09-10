#include <cstdio>
#include <vector>

using namespace std;

const int mod = 998244353;
int fac[10000005], inv[10000005], F[500005], f[500005];
int mo[10000005];
int prime[1000005], cnt = 0;
bool ntp[10000005];
vector<int> v[500005];
int p[45], a[45];
int qpow(int x, int y)
{
	int ans = 1;
	while(y)
	{
		if(y & 1)
			ans = 1ll * ans * x % mod;
		x = 1ll * x * x % mod;
		y >>= 1;
	}
	return ans;
}
int gcd(int x, int y)
{
	return x ? gcd(y % x, x) : y;
}
void sieve(int x)
{
	int i, j, k;
	ntp[1] = 1;
	mo[1] = 1;
	for(i = 2; i <= x; i++)
	{
		if(!ntp[i])
		{
			prime[++cnt] = i;
			mo[i] = -1;
		}
		for(j = 1; j <= cnt && 1ll * i * prime[j] <= x; j++)
		{
			k = i * prime[j];
			ntp[k] = 1;
			if(!(i % prime[j]))
			{
				mo[k] = 0;
				break;
			}
			mo[k] = -mo[i];
		}
	}
}

int main()
{
	freopen("gcd.in", "r", stdin);
	freopen("gcd.out", "w", stdout);
	int n, i, j, w, m = 1, ans = 0, tmp;
	scanf("%d%d", &n, &w);
	for(i = 1; i <= w; i++)
	{
		scanf("%d%d", p + i, a + i);
		m = 1ll * m * qpow(p[i], a[i]) % mod;
	}
	sieve(n);
	fac[0] = 1;
	for(i = 1; i <= n; i++)
		fac[i] = 1ll * fac[i - 1] * i % mod;
	inv[n] = qpow(fac[n], mod - 2);
	for(i = n; i >= 1; i--)
		inv[i - 1] = 1ll * inv[i] * i % mod;
	if(m != 1)
	{
		for(i = 1; i <= n; i++)
			for(j = i; j <= n; j += i)
				v[j].push_back(i);
		for(i = 1; i <= n; i++)
		{
			if(m % i)
			{
				f[i] = n;
				for(auto k: v[i])
					if(k != i)
					{
						f[i] = (f[i] + 1ll * (n / k) * F[k] % mod) % mod;
						f[i] = (f[i] + (mod + 1ll * (n / i) * f[k] * mo[i / k] % mod) % mod) % mod;
					}
				f[i] = 1ll * f[i] * inv[n - n / i] % mod * fac[n - n / i - 1] % mod;
			}
			for(auto k: v[i])
				F[i] = (F[i] + (mod + f[k] * mo[i / k]) % mod) % mod;
		}
		for(i = 1; i <= n; i++)
			ans = (ans + f[i]) % mod;
		ans = 1ll * ans * inv[n] % mod * fac[n - 1] % mod;
		ans = (ans + 1) % mod;
		printf("%d\n", ans);
		return 0;
	}
	for(i = 2; i <= n; i++)
	{
		if(!mo[i])
			continue;
		tmp = 1ll * inv[n - n / i] * fac[n - n / i - 1] % mod;
		tmp = 1ll * (n / i) * (n / i) % mod * tmp % mod;
		ans = (ans + (mod + mo[i] * tmp) % mod) % mod;
	}
	ans = (1 + 1ll * (n + mod - ans - 1) % mod * inv[n] % mod * fac[n - 1] % mod) % mod;
	printf("%d\n", ans);
	return 0;
}