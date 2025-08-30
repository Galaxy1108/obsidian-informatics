#include <cstdio>

using namespace std;
typedef long long ll;

const int mod = 998244353;
int fac[10005], inv[10005];
int qpow(int x, int y)
{
	int ans = 1;
	while(y)
	{
		if(y & 1)
			ans = (ll)ans * x % mod;
		x = (ll)x * x % mod;
		y >>= 1;
	}
	return ans;
}
int C(int x, int y)
{
	return (x < y || y < 0) ? 0 : ((ll)fac[x] * inv[y] % mod * inv[x - y] % mod);
}

int main()
{
	freopen("oracle.in", "r", stdin);
	freopen("oracle.out", "w", stdout);
	int n, m, i, j, k, ed, cc, ans = 0, pc, tmp;
	scanf("%d%d", &n, &m);
	fac[0] = 1;
	for(i = 1; i <= n * n; i++)
		fac[i] = (ll)fac[i - 1] * i % mod; 
	inv[n * n] = qpow(fac[n * n], mod - 2);
	for(i = n * n; i >= 1; i--)
		inv[i - 1] = (ll)inv[i] * i % mod;
	for(i = 0; i < (1 << (n - 1)); i++)
	{
		pc = cc = ed = 0;
		k = (i & (i << 1));
		for(j = n - 1; j >= 0; j--)
		{
			pc += ((i >> j) & 1);
			if(!(i & (1 << j)))
				ed++;
			if(!j || !(i & (1 << (j - 1))))
				cc += ed;
		}
		tmp = C(cc, m);
		if(pc & 1)
			ans = (ans + mod - tmp) % mod;
		else
			ans = (ans + tmp) % mod;
	}
	printf("%d\n", ans);
	return 0;
}