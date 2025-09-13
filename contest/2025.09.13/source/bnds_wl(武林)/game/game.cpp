#include <cstdio>

using namespace std;

const int mod = 998244353;
int f[1000005], ans[1000005], s2[1000005], ans2[1000005], s[1000005];
int prime[1000005], cnt = 0;
int mo[1000005];
int fac[1000005], inv[1000005];
bool ntp[1000005];
void sieve(int x)
{
	int i, j;
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
			ntp[i * prime[j]] = 1;
			if(!(i % prime[j]))
			{
				mo[i * prime[j]] = 0;
				break;
			}
			mo[i * prime[j]] = -mo[i];
		}
	}
}
int qpow(int x, int y)
{
	int ans = 1;
	while(y)
	{
		if(y & 1)
			ans = 1ll * x * ans % mod;
		x = 1ll * x * x % mod;
		y >>= 1;
	}
	return ans;
}

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int n, i, t, k, j, iv;
	scanf("%d", &k);
	f[k] = 1;
	s[k] = 1;
	for(i = k + 1; i <= 1000000; i++)
	{
		f[i] = (1 + s[i - k - 1]) % mod;
		s[i] = (s[i - 1] + f[i]) % mod;
	}
	ans[k + 1] = k + 1;
	for(i = k + 2; i <= 1000000; i++)
		ans[i] = (((1 + ans[i - 1]) % mod + s[i - k - 2]) % mod + 1ll * k * f[i - k - 2]) % mod;
	fac[0] = 1;
	for(i = 1; i <= 1000000; i++)
		fac[i] = 1ll * fac[i - 1] * i % mod;
	inv[1000000] = qpow(fac[1000000], mod - 2);
	for(i = 1000000; i >= 1; i--)
		inv[i - 1] = 1ll * inv[i] * i % mod;
	sieve(1000000);
	for(i = 1; i <= 1000000; i++)
		for(j = i; j <= 1000000; j += i)
			s2[j] = ((s2[j] + 1ll * mo[j / i] * ans[i] % mod) % mod + mod) % mod;
	for(i = 1; i <= 1000000; i++)
	{
		iv = 1ll * inv[i] * fac[i - 1] % mod;
		for(j = i; j <= 1000000; j += i)
			ans2[j] = (ans2[j] + 1ll * iv * s2[i] % mod) % mod;
	}
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		printf("%d %d\n", ans[n], ans2[n]);
	}
	return 0;
}