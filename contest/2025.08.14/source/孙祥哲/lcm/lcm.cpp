#include <bits/stdc++.h>
#define int unsigned long long
#define int1 unsigned __int128
#define eps 1e-9
using namespace std;

int T, n;
int1 f[1000005], g[1000005], ans, sum, p=1e9+7;

int1 qpow(int1 x, int1 y)
{
	int1 res = 1;
	while (y)
	{
		if (y % 2) res = res*x%p;
		x = x*x%p;
		y >>= 1;
	}
	return res;
}
int1 inv(int1 a) { return qpow(a, p-2); }

int1 gcd(int1 a, int1 b) { return b?gcd(b,a%b):a; }
int1 lcm(int1 a, int1 b) { return a/(gcd(a,b))*b; }

void init()
{
	f[1] = g[1] = ans = 1;
	if (n == 1) return;
	f[2] = 2, sum = 6, g[2] = 2, ans = 5;
	for (int1 i = 3; i <= n; i++)
	{
		f[i] = sum - f[i-1] + 1;
		sum += f[i]*2;
		g[i] = lcm(g[i-1], f[i]);
		ans = (ans + g[i]%p*i%p) % p;
//		printf("%lld: %lld %lld %lld\n",(int)i,(int)f[i],(int)g[i],(int)ans);
	}
}

signed main()
{
	freopen("lcm.in", "r", stdin);
	freopen("lcm.out", "w", stdout);
	cin >> T;
	while (T--)
	{
		int x;
		cin >> n >> x; p = x;
		init();
		cout << (int)ans << '\n';
	}
	return 0;
}
